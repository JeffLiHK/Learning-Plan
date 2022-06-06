#include <stdio.h>

int strcmp_jeff (char *s, char *t);

int main() {
    char str1[] = "aac";
    char str2[] = "abc";
    printf("\n%d\n", strcmp_jeff(str1, str2));
    return 0;
}

int strcmp_jeff (char *s, char *t) {
    while (*s == *t) {
        if (*s == '\0') {
            return 0;
        }
        s++;
        t++;
    }
    return *s - *t;
}