#include<iostream>
using namespace std;
#define N 5
const int max_length = 32 * N;
class bitset {
    private:
        int a[N];
    public:
        bitset();
        void set(int pos);
        void reset(int pos);
        int count() const;
        bool test(int pos) const;
        bool any() const;
        bool none() const;
        bool all() const;
        bitset& operator&= (const bitset& b);
        bitset& operator|= (const bitset& b);
        bitset& operator^= (const bitset& b);
        bitset& operator= (const bitset& b);
        bitset& operator <<= (int pos);
        bitset& operator >>= (int pos);
        bitset operator~() const;
        bitset operator&(const bitset& b) const;
        bitset operator|(const bitset& b) const;
        bitset operator^(const bitset& b) const;
        bitset operator<<(int pos) const;
        bitset operator>>(int pos) const;
        bool operator== (const bitset& b) const;
        bool operator!= (const bitset& b) const;
        bool operator[] (int pos) const;
        friend std::ostream& operator << (std::ostream& os, const bitset& s) {
            for (int i = N-1; i >= 0; i--) {
                for (int j = 31; j >= 0; j--) {
                    if (s.a[i] & (1 << j)) os << 1;
                    else os << 0;
                }
            }
            return os;
        }
};


int main() {
    bitset a, b;
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.set(x);
    }
    cout << "a.count() is " << a.count() << "\n";
    cout << "a.test(5) is " << (a.test(5) ? "true" : "false") << "\n";
    cout << "a.any() is " << (a.any() ? "true" : "false") << "\n";
    cout << "a.none() is " << (a.none() ? "true" : "false") << "\n";
    cout << "a.all() is " << (a.all() ? "true" : "false") << "\n";
    b = ~b;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        b.reset(x);
    }
    cout << "a:" << endl << a << "\n";
    cout << "b:" << endl << b << "\n";
    if (a == b) {
        cout << "hello\n";
    }
    if (a != b) {
        cout << "world\n";
    }
    bitset c;
    // test &
    cout << endl << endl << endl;
    c = a;
    c &= b;
    cout << "&:" << endl << c << "\n";
    c = a & b;
    cout << "&:" << endl << c << "\n";
    // test |
    c = a;
    c |= b;
    cout << "|:\n" << c << "\n";
    c = a | b;
    cout << "|:\n" <<c << "\n";
    // test ^
    c = a;
    c ^= b;
    cout << "^:\n" << c << "\n";
    c = a ^ b;
    cout << c << "\n";
    // test <<
    cout << endl << endl << endl;
    c = a;
    cout << c << endl;
    c <<= 2;
    cout << "<<=\n" << c << "\n";
    c = a << 2;
    cout << c << "\n";
    // test >>
    c = b;
    cout << c << endl;
    c >>= 2;
    cout << ">>=:\n" << c << "\n";
    c = b >> 2;
    cout << c << "\n";
    // test []
    cout << a << endl;
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        if (a[i])
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}

bitset::bitset() {
	for (int i = 0; i < N; ++i) {
		a[i] = 0;
	}
}

void bitset::set(int pos) {
	int index = pos / 32;
	a[index] |= 1UL << (pos - index * 32);
}

void bitset::reset(int pos) {
	int index = pos / 32;
	a[index] &= ~(1UL << (pos - index * 32));
	
	
}

int bitset::count() const {
	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		for (int pos = 0; pos < 32; ++pos) {
			if (a[i] & (1UL << pos)) {
				cnt++;
			}
		}
	}
	return cnt;
}

bool bitset::test(int pos) const {
	int index = pos / 32;
	return a[index] & (1UL << (pos - 32 * index));
}

bool bitset::any() const {
	for (int i = 0; i < N; ++i ){
		if (a[i] != 0) {
			return true;
		}
	}
	return false;
}

bool bitset::none() const {
	for (int i = 0; i < N; ++i) {
		if (a[i] != 0) {
			return false;
		}
	}
	return true;
}

bool bitset::all() const {
	for (int i = 0; i < N; ++i) {
		//if (a[i] != ((1LL << 32) - 1)) {
		if (a[i] != 0xff) {
			return false;
		}
	}
	return true;
}

bitset& bitset::operator&= (const bitset& b) {
	for (int i = 0; i < N; ++i) {
		a[i] &= b.a[i];
	}
	return *this;
}
bitset& bitset::operator|= (const bitset& b) {
	for (int i = 0; i < N; ++i) {
		a[i] |= b.a[i];
	}
	return *this;
}
bitset& bitset::operator^= (const bitset& b) {
	for (int i = 0; i < N; ++i) {
		a[i] ^= b.a[i];
	}
	return *this;
}

bitset& bitset::operator= (const bitset& b) {
	for (int i = 0; i < N; ++i) {
		a[i] = b.a[i];
	}
	return *this;
}

bitset& bitset::operator <<= (int pos) {
	unsigned long com = 0;
	for (int i = N - 1; i >= 0; --i) {
		a[i] <<= pos;
		if (i == 0) com = 0;
		else {
			com = a[i - 1] >> (32 - pos);
			com &= ((1UL << pos) - 1);
		}
		a[i] |= com;
	}
	return *this;
}

bitset& bitset::operator>>= (int pos) {
	unsigned long com = 0UL;
	for (int i = 0; i < N; ++i) {
		a[i] >>= pos;
		if (i == N - 1) {
			com = ((1LL << pos) - 1)<<(32 - pos);
		} else {
			com = a[i + 1] << (32 - pos);
		}
		long long zeros = ~(((1 << pos) - 1) << (32 - pos));
		a[i] &= zeros;
		a[i] |=  com;
	}
	return *this;
}

bitset bitset::operator~() const {
	bitset ret;
	for (int i = 0; i < N; ++i) {
		ret.a[i] = ~a[i];
	}
	return ret;
}

bitset bitset::operator&(const bitset& b) const {
	bitset ret;
	ret = *this;
	ret &= b;
	return ret;
}

bitset bitset::operator|(const bitset& b) const {
	bitset ret;
	ret = *this;
	ret |= b;
	return ret;
}

bitset bitset::operator^(const bitset& b) const {
	bitset ret;
	ret = *this;
	ret ^= b;
	return ret;
}

bitset bitset::operator<<(int pos) const {
	bitset ret;
	ret = *this;
	ret <<= pos;
	return ret;
}
bitset bitset::operator>>(int pos) const {
	bitset ret;
	ret = *this;
	ret >>= pos;
	return ret;
}
bool bitset::operator== (const bitset& b) const {
	for (int i = 0; i < N; ++i) {
		if (a[i] != b.a[i])
			return false;
	}
	return true;
}
bool bitset::operator!= (const bitset& b) const {
	return ! (*this == b);
}

bool bitset::operator[] (int pos) const {
	int index = pos / 32;
	return a[index] & (1UL << (pos - 32 * index));
}
	
















