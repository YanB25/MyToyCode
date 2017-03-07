#ifndef _MY_TOOLS_H_
#define _MY_TOOLS_H_
#include <vector>
#include <iostream>
#include <cmath>
using std::vector;
using std::cout;
using std::endl;
using std::ostream;
namespace yb {
	
	//function max and min
	//need c++14
	template <typename T>
	inline T max(T value) { return value; }

	template <typename T, typename U>
	inline auto max(const T& lhs, const U& rhs) {
		return lhs > rhs ? lhs : rhs;
	}

	template <typename T, typename ...Args>
	auto max(const T& first, const Args & ...args) {
		return yb::max(first, yb::max(args...));
	}

	template <typename T, typename ...Args>
	auto min(const T& first, const Args& ...args) {
		return -1 * yb::max(-1 * first, yb::max((-1 * args)...));
	}
	
	//math vector
	template <unsigned dim>
	class mathVector {
	public:
		mathVector() { data.resize(dim); }
		mathVector(const mathVector<dim>& rhs) : data(rhs.data) { }
		mathVector(mathVector<dim> && rhs) : data(std::move(rhs.data)) { }
		mathVector& operator=(const mathVector<dim>& rhs) { data = rhs.data; return *this; }
		mathVector& operator=(mathVector<dim>&& rhs) { data = std::move(rhs.data); return *this; }
		~mathVector() = default;
		template <typename ...Args> mathVector(double, Args ...args);
		const vector<double>& elements() const { return data; }
		
		mathVector& operator+= (const mathVector&);
		mathVector& operator-= (const mathVector &);
		mathVector& operator*= (double scale);
		mathVector operator+ (const mathVector& rhs) const;
		mathVector operator- (const mathVector& rhs) const;
		mathVector operator* (double scale) const;
		double operator* (const mathVector&) const;
		
		double length() const;
	private:
		vector<double> data;
		template <typename ...Args> void inputData(double, Args ...args);
		void inputData(double s) { data.push_back(s); }
	};
	
	template <unsigned dim> template <typename ...Args>
	mathVector<dim>::mathVector(double first, Args ...args) {
		if (dim >= 1 && sizeof...(args) == dim - 1) {
			inputData(first, args...);
		}
	}
	
	template <unsigned dim> template <typename ...Args>
	void mathVector<dim>::inputData(double first, Args ...args) {
		data.push_back(first);
		inputData(args...);
	}
	
	template <unsigned dim>
	bool operator== (const mathVector<dim>& lhs, const mathVector<dim>& rhs) {
		return lhs.elements() == rhs.elements();
	}
	
	template <unsigned dim>
	bool operator!= (const mathVector<dim> & lhs, const mathVector<dim>& rhs) {
		return !(lhs == rhs);
	}
	
	template <unsigned dim>
	ostream& operator<< (ostream& os, const mathVector<dim>& vec) {
		os << "(";
		bool first = true;
		for (auto i : vec.elements()) {
			if (first) {
				os << i;
				first = !first;
			}else {
				os << ", " << i;
			}
		}
		os << ")";
		return os;
	}
	
	template<unsigned dim>
	mathVector<dim>& mathVector<dim>::operator+=(const mathVector<dim>& rhs) {
		for (size_t i = 0; i < dim; ++i) {
			data[i] += rhs.data[i];
		}
		return *this;
	}
	
	template<unsigned dim>
	mathVector<dim>& mathVector<dim>::operator-=(const mathVector<dim>& rhs) {
		for (int i = 0; i < dim; ++i) {
			data[i] -= rhs.data[i];
		}
		return *this;
	}
	
	template <unsigned dim>
	mathVector<dim>& mathVector<dim>::operator*= (double scale) {
		for (auto& i : data) {
			i *= scale;
		}
		return *this;
	}
	
	template <unsigned dim>
	mathVector<dim> mathVector<dim>::operator+(const mathVector<dim>& rhs) const {
		mathVector<dim> result(rhs);
		result += *this;
		return result;
	}
	
	template <unsigned dim>
	mathVector<dim> mathVector<dim>::operator-(const mathVector<dim>& rhs) const {
		mathVector<dim> result(rhs);
		result -= *this;
		return result;
	}
	
	template <unsigned dim>
	mathVector<dim> mathVector<dim>::operator*(double scale) const {
		mathVector<dim> result(*this);
		result *= scale;
		return result;
	}
	
	template <unsigned dim>
	double mathVector<dim>::operator*(const mathVector<dim>& rhs) const {
		double res = 0;
		for (size_t i = 0; i < dim; ++i) {
			res += data[i] * rhs.data[i];
		}
		return res;
	}
	
	template <unsigned dim>
	mathVector<dim> operator*(double scale, const mathVector<dim>& rhs) {
		return rhs * scale;
	}
	
	
	template <unsigned dim>
	double mathVector<dim>::length() const {
		double length = 0;
		for (auto i : data) {
			length += i * i;
		}
		return sqrt(length);
	}
		
}
#endif
