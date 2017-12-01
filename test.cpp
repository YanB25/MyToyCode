#include <algorithm>
#include <cstdio>
using std::sort;
int main() {
    const int n = 10;
    double grades[10];
    int _;
    char __[];
    for (int i = 0; i < 10; ++i) {
        :
    }
    double min = grades[0];
    double max = grades[0];
    double sum = 0;
    for (int i = 0; i < 10; ++i) {
        if (grades[i] > max) max = grades[i];
        if (grades[i] < min) min = grades[i];
        sum += grades[i];
    }
    double Mean = sum / n;
    
    sort(grades, grades + n);
    double median = (grades[n/2 - 1] + grades[n/2]) / 2;

    // output ...
}
