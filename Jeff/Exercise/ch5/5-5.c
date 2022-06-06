#include <stdio.h>

void strncpy_jeff (char *s, char *t, int n);
void strncat_jeff (char *s, char *t, int n);
int strcmp_jeff (char *s, char *t, int n);

int main() {
    int strSize = 5;
    char str1[] = "hello world";
    char str2[strSize+1];   // +1 for '\0'
    strncpy_jeff(str2, str1, strSize);
    printf("%s\n", str2);
    
    char str1_1[] = "by jeff";
    strncat_jeff(str1, str1_1, 4);
    printf("%s\n", str1);

    int s = 2;
    char str7[] = "aac";
    char str8[] = "abc";
    printf("-1: %d\n", strcmp_jeff(str7, str8, s));
    char str3[] = "abc";
    char str4[] = "aac";
    printf("1: %d\n", strcmp_jeff(str3, str4, s));
    char str5[] = "aac";
    char str6[] = "aac";
    printf("0: %d\n", strcmp_jeff(str5, str6, s));
    return 0;
}

void strncpy_jeff (char *s, char *t, int n) {
    while (n-- > 0 && (*s++ = *t++)) 
        ;
    *s = '\0';
}

void strncat_jeff (char *s, char *t, int n) {
    char *sp = s;
    while (*sp++) {
        ;
    }
    sp--;
    while (n-- > 0 && (*sp++ = *t++)) {
        ;
    }
    *sp = '\0';
}

int strcmp_jeff (char *s, char *t, int n) {
    while (--n > 0 && (*s == *t)) {
        if (*s == '\0') {
            return 0;
        }
        s++;
        t++;
    }
    return *s - *t;
}