#include <stdio.h>
#include <stdlib.h>

void itos(int num);

int main(){
    itos(5782);
    return 0;
}

void itos(int num) {
    char ch;
    if (num < 0) {
        ch = '-';
        putchar(ch);
    }
    if (num/10) {
        itos(num/10);
    }
    // itoa(num%10, ch, 10);
    printf("%d", num%10);
}