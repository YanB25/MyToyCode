#include <stdio.h>
void foo(auto int i);
int main() {
    foo(10);
}
void foo(auto int i) {
    printf("%d\n", i);
}
