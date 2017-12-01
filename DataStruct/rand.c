#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main() {
    srand(time(0));
    int i = 1000*rand()/(RAND_MAX);
    int j = 1000*rand()/(RAND_MAX);
    printf("%d\n", i);
    while (i--) {
        int data, pos;
        data = 100*rand()/(RAND_MAX);
        pos = 100*rand()/(RAND_MAX);
        printf("%d %d\n", pos, data);
    }
    printf("%d\n", j);
    while (j--) {
        int pos;
        pos = 1000*rand()/(RAND_MAX);
        printf("%d\n", pos);
    }
    return 0;
}
