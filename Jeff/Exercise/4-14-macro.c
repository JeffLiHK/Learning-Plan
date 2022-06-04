#include <stdio.h>
#define swap(t,x,y) {t a = x; x = y; y = a;}

int main() {
    int x = 10;
    int y = 7;
    swap(int, x, y);
    printf("x=%d, y=%d", x, y);
    return 0;
}