#include <stdio.h>

void strcat_test(char *s, char *t);

int main() {
    char str1[] = "hello ";
    char str2[] = "world";
    strcat_test(str1, str2);
    printf("%s", str1);
    return 0;
}

void strcat_test(char *s, char *t) {
    char *sp = s;
    while (*sp++) {
        ;
    }
    sp--;
    while (*sp++ = *t++) {
        ;
    }
}