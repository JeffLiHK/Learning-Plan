#include <stdio.h>

void test();

int main() {
    test();
    test();
    test();
    return 0;
}

void test() {
    static int a = 0;
    a++;
    printf("%d", a);
}
