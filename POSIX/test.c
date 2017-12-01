#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void count(int* arr) {
    arr[0] = 1;
    arr[1] = 1;
    for (int i = 2; i < 25; ++i) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
}
int getData(int i) {
    if (i <= 2) return 1;
    return getData(i - 1) + getData(i - 2);
}
int main() {
    int fildes[2];
    const int BSIZE = 100;
    char buf[BSIZE];
    ssize_t nbytes;
    int status;
    status = pipe(fildes);
    if (status == -1 ) {
        /* an error occurred */
    }


    switch (fork()) {
        case -1: /* Handle error */
            break;
        case 0:  /* Child - reads from pipe */
            //close(fildes[1]);                       /* Write end is unused */
            for (int i = 0; i < 60; ++i) {
                printf("start get\n");
                nbytes = read(fildes[0], buf, BSIZE);   /* Get data from pipe */
            /* At this point, a further read would see end-of-file ... */
                printf("%s\n", buf);
                printf("end get\n");
            }
            //close(fildes[0]);                       /* Finished with pipe */
            exit(EXIT_SUCCESS);
        default:{  /* Parent - writes to pipe */
            for (int i = 0; i < 60; ++i) {
                char s[20];
                int data = getData(i);
                sprintf(s, "%d", data);
                printf("test:: %s\n", s);
                write(fildes[1], s, BSIZE);  /* Write data on pipe */
            }

            exit(EXIT_SUCCESS);
        }
    }
}
