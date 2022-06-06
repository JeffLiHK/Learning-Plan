#include <stdio.h>

void strcpy_jeff(char *s, char *t);

int main() {
    char str[] = "hello world";
    int strSize = sizeof(str);
    char str2[strSize];
    // strcpy_jeff(str2, str);
    strcpy(str2, str);
    for (int i = 0; i < strSize; i++) {
        // printf("%c", str2[i]);
        printf("%c", str2[i]);
    }
    printf("\n");
    return 0;
}

void strcpy_jeff(char *s, char *t) {
    while (*s++ = *t++) {
        ;
    }
}