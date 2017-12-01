#include <iostream>

using namespace std;
class fraction {
    private:
        int _numerator, _denominator;
        int gcd(const int &, const int &) const;
            // If you don't need this method, just ignore it.
        void simp();
            // To get the lowest terms.
    public:
        fraction(const int & = 0, const int & = 1);
            // The numerator and the denominator
            // fraction(5) = 5/1 = 5 :)
        fraction(const fraction &);
            // copy constructor

        void operator=(const fraction &);

        // You must know the meaning of +-*/, don't you ?
        fraction operator+(const fraction &) const;
        fraction operator-(const fraction &) const;
        fraction operator*(const fraction &) const;
        fraction operator/(const fraction &) const;

        void operator+=(const fraction &);
        void operator-=(const fraction &);
        void operator*=(const fraction &);
        void operator/=(const fraction &);

        // Comparison operators
        bool operator==(const fraction &) const;
        bool operator!=(const fraction &) const;
        bool operator<(const fraction &) const;
        bool operator>(const fraction &) const;
        bool operator<=(const fraction &) const;
        bool operator>=(const fraction &) const;

        friend std::istream & operator>>(std::istream &, fraction &);
            // Input Format: two integers with a space in it
            // "a b" is correct. Not "a/b"
        friend std::ostream & operator<<(std::ostream &, const fraction &);
            // Normally you should output "a/b" without any space and LF
            // Sometims you may output a single integer (Why? Guess XD)
            // If it is not a number (den = 0), output "NaN"
};

void print(const bool & f) {
    if (f)
        std::cout << "True" << std::endl;
    else
        std::cout << "False" << std::endl;
}

int main() {
    fraction f1, f2;
    std::cin >> f1 >> f2;
    std::cout << f1 << endl << f2 << endl;
    std::cout << f1 + f2 << ' ' << f1 - f2 << ' '
              << f1 * f2 << ' ' << f1 / f2 << std::endl;
    f1 += f2;
    std::cout << f1 << std::endl;
    f1 -= f2;
    std::cout << f1 << std::endl;
    f1 *= f2;
    std::cout << f1 << std::endl;
    f1 /= f2;
    std::cout << f1 << std::endl;
    print(f1 == f2);
    print(f1 != f2);
    print(f1 < f2);
    print(f1 > f2);
    print(f1 <= f2);
    print(f1 >= f2);
    return 0;
}

long long MyGcd(long long lhs, long long rhs) {
    if (rhs == 0)
        return lhs;
    return MyGcd(rhs, lhs % rhs);
}
void MySimp(long long& lhs, long long& rhs) {
    long long _gcd = MyGcd(lhs, rhs);
    lhs /= _gcd;
    rhs /= _gcd;
    if (rhs < 0) {
        rhs *= -1;
        lhs *= -1;
    }
}
fraction::fraction(const int& a, const int& b) : _numerator(a), _denominator(b) { }
int fraction::gcd(const int& lhs, const int& rhs) const {
    if (rhs == 0)
        return lhs;
    return gcd(rhs, lhs % rhs);
}
void fraction::simp() {
    int _gcd = gcd(_numerator, _denominator);
    _numerator /= _gcd;
    _denominator /= _gcd;
    if (_denominator < 0) {
        _denominator *= -1;
        _numerator *= -1;
    }
}

fraction::fraction(const fraction& rhs):fraction(){
    *this = rhs;
    simp();
}

void fraction::operator=(const fraction& rhs) {
    _numerator = rhs._numerator;
    _denominator = rhs._denominator;
}

void fraction::operator+=(const fraction& rhs) {
    long long tmp_num = (long long)  _numerator * rhs._denominator + (long long)  _denominator * rhs._numerator;
    long long tmp_de = (long long) _denominator * rhs._denominator;
    MySimp(tmp_num, tmp_de);
    _numerator = tmp_num;
    _denominator = tmp_de;
}

void fraction::operator-=(const fraction& rhs) {
    long long tmp_num = (long long)  _numerator * rhs._denominator - (long long)  _denominator * rhs._numerator;
    long long tmp_de = (long long) _denominator * rhs._denominator;
    MySimp(tmp_num, tmp_de);
    _numerator = tmp_num;
    _denominator = tmp_de;
}

void fraction::operator*=(const fraction& rhs) {
    long long tmpNum = (long long)_numerator * rhs._numerator;
    long long tmpDe = (long long) _denominator * rhs._denominator;
    MySimp(tmpNum, tmpDe);
    _denominator = tmpDe; 
    _numerator = tmpNum; 
    simp();
}

void fraction::operator/=(const fraction& rhs) {
    fraction tmp(rhs._denominator, rhs._numerator);
    *this *= tmp;
    simp();
}

fraction fraction::operator+(const fraction& rhs) const {
    fraction ret(*this);
    ret += rhs;
    ret.simp();
    return ret;
}

fraction fraction::operator-(const fraction& rhs) const{
    fraction ret(*this);
    ret -= rhs;
    ret.simp();
    return ret;
}

fraction fraction::operator*(const fraction& rhs) const {
    fraction ret(*this);
    ret *= rhs;
    ret.simp();
    return ret;
}

fraction fraction::operator/(const fraction& rhs) const {
    fraction ret(*this);
    ret /= rhs;
    ret.simp();
    return ret;
}

bool fraction::operator==(const fraction& rhs) const { 
    return (_denominator == 0 && rhs._denominator == 0) || (_denominator == rhs._denominator && _numerator == rhs._numerator);
}

bool fraction::operator!=(const fraction& rhs) const {
    return !(*this == rhs);
}

bool fraction::operator<(const fraction& rhs) const {
    return 1.0 * _numerator/_denominator < 1.0 * rhs._numerator/rhs._denominator;
}

bool fraction::operator>(const fraction& rhs) const {
    return 1.0 * _numerator/_denominator > 1.0 * rhs._numerator / rhs._denominator;
}

bool fraction::operator>=(const fraction& rhs) const {
    return !(*this < rhs);
}

bool fraction::operator<=(const fraction& rhs) const {
    return !(*this > rhs);
}

std::istream& operator>>(std::istream& is, fraction& rhs) {
    int a, b;
    is >> a >> b;
    rhs._numerator = a;
    rhs._denominator = b;
    rhs.simp();
    return is;
}

std::ostream& operator<<(std::ostream& os, const fraction& rhs) {
    if (rhs._denominator == 0)
        os<< "NaN";
    else if (rhs._denominator == 1) {
        os<< rhs._numerator;
    } else {
        os << rhs._numerator << "/" << rhs._denominator; 
    }
    return os;
}

