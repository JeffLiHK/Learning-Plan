#include <stdio.h>

void reverse(char *s);
void swap(char *i, char *j);

int main() {
    char str[] = "hello world";
    reverse(str);
    printf("%s", str);
    return 0;
}


void reverse(char *s) {
    char *i = s, *j = s;    // i point to the head of s, j point to the end of s
    while (*s++)
        ;
    j = s-2;   // not include '\0'
    for (; i < j; i++, j--) 
        swap(i, j);
}

void swap(char *i, char *j) {
    char t = *i;
    *i = *j;
    *j = t;
}