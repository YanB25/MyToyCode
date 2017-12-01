#include <iostream>
#include <string.h>
using namespace std;

class Matrix {
    public:
        Matrix() {
            name = "";
            width = height = 0;
            param = NULL;
        }
        Matrix(string, int, int, int**);
        Matrix(const Matrix &);
        ~Matrix();
        void setName(string newName) {
            name = newName;
        }
        string getName() {
            return name;
        }
        void print() {
            cout << name << " = [\n";
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    if (j == width-1) cout << param[i][j];
                    else cout << param[i][j] << ", ";
                }
                cout << "\n";
            }
            cout << "]\n";
        }
        // overload operator
        bool operator ==(const Matrix&);
        bool operator !=(const Matrix&);
        void operator +=(const Matrix&);
        void operator -=(const Matrix&);
        Matrix operator *(const Matrix&);
    private:
        string name;
        int width, height, **param;
};

int main() {
    int h1, w1, h2, w2, n;
    string name1 = "Mat1";
    string name2 = "Mat2";
    cin >> h1 >> w1;
    int **mat1_arr = new int*[h1];
    for (int i = 0; i < h1; i++) {
        mat1_arr[i] = new int[w1];
        for (int j = 0; j < w1; j++) {
            cin >> mat1_arr[i][j];
        }
    }
    cin >> h2 >> w2;
    int **mat2_arr = new int*[h2];
    for (int i = 0; i < h2; i++) {
        mat2_arr[i] = new int[w2];
        for (int j = 0; j < w2; j++) {
            cin >> mat2_arr[i][j];
        }
    }
    Matrix mat1 = Matrix(name1, h1, w1, mat1_arr);
    mat1.print();
    Matrix mat2 = Matrix(name2, h2, w2, mat2_arr);
    mat2.print();
    cout << "\n(Mat1 += Mat2) addition result:\n";
    mat1 += mat2;
    mat1.print();
    cout << "\n(Mat1 -= Mat2) substraction result:\n";
    mat1 -= mat2;
    mat1.print();
    cout << "\n(Mat1 * Mat2) production result:\n";
    Matrix mat3 = mat1 * mat2;
    if (mat3.getName() != "") mat3.print();
    for (int i = 0; i < h1; i++) {
        delete [] mat1_arr[i];
    }
    delete [] mat1_arr;
    for (int i = 0; i < h2; i++) {
        delete [] mat2_arr[i];
    }
    delete []mat2_arr;
    return 0;
}

Matrix::Matrix(string _name, int m, int n, int** arr) {
	name = _name;
	height = m;
	width = n;
	param = new int*[height];
	for (int i = 0; i < height; ++i) {
		param[i] = new int[width];
	}
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			param[i][j] = arr[i][j];
		}
	}
}

Matrix::Matrix(const Matrix &rhs) {
	name = rhs.name;
	height = rhs.height;
	width = rhs.width;
	param = new int*[height];
	for (int i = 0; i < height; ++i) {
		param[i] = new int[width];
	}
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			param[i][j] = rhs.param[i][j];
		}
	}
}
		
Matrix::~Matrix() {
	for (int i = 0; i < height; ++i) {
		delete[] param[i];
		param[i] = nullptr;
	}
	delete[] param;
	param = nullptr;
	height = width = 0;
}
		
bool Matrix::operator ==(const Matrix& rhs) {
	if (width != rhs.width || height != rhs.height)
		return false;
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			if (param[i][j] != rhs.param[i][j]) {
				return false;
			}
		}
	}
	return true;
}

bool Matrix::operator !=(const Matrix& rhs) {
	return !(*this == rhs);
}

void Matrix::operator +=(const Matrix& rhs) {
	if (width != rhs.width || height != rhs.height) {
		cout << "invalid addition.\n";
		return;
	}
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			param[i][j] += rhs.param[i][j];
		}
	}
}

void Matrix::operator -=(const Matrix& rhs) {
	if (width != rhs.width || height != rhs.height) {
		cout << "invalid substraction.\n";
		return;
	}
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			param[i][j] -= rhs.param[i][j];
		}
	}
}

Matrix Matrix::operator *(const Matrix& rhs) {
	if (width != rhs.height) {
		cout << "invalid multiplication.\n";
		return Matrix();
	}
	
	int** arr = new int*[height];
	for (int i = 0; i < height; ++i) {
		arr[i] = new int[rhs.width];
	}
	
	for (int x = 0; x < height; ++x) {
		for (int y = 0; y < rhs.width; ++y) {
			int sum = 0;
			for (int i = 0; i < width; ++i) {
				sum += param[x][i] * rhs.param[i][y];
			}
			arr[x][y] = sum;
		}
	}
	Matrix ret("newMat", height, rhs.width, arr);
	
	for (int i = 0; i < height; ++i) {
		delete[] arr[i];
	}
	delete[] arr;
	
	return ret;
}
		
		







