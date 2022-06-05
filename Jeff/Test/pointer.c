#include <stdio.h>

void test1();
void test2();

int main() {
    // test1();
    // test2();
    int a[] = {7,2,5};
    int *pa = &a[1];
    printf("0: %d, 1: %d, 2:%d", *(pa-1), *pa, *(pa+1));
    return 0;
}

void test1() {
    int x = 1, y = 2, z[10];
    int *ip;  // ip is a pointer point to int
    printf("pre x = %d, pre y = %d\n", x, y);
    ip = &x;
    y = *ip;
    printf("mid x = %d, mid y = %d\n", x, y);
    *ip = z[0];
    printf("post x = %d, post y = %d\n", x, y);
    return;
}

void swap(int *a, int *b);

void test2() {
    int a[] = {1,2,3};
    int b[] = {11,22,33};
    printf("Before swap: a[1]=%d, b[2]=%d\n", a[1], b[2]);
    swap(&a[1],&b[2]);
    printf("After swap: a[1]=%d, b[2]=%d\n", a[1], b[2]);
}

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}