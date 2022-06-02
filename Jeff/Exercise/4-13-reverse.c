#include <stdio.h>

void reverse(char* rev, char* str, int len, int i);

int main() {
    char str[] = "hello world";
    char new[12];
    reverse(new, str, 11, 0);
    printf("\nOriginal String: %s\n", str);
    printf("Reversed String: %s\n", new);
    return 0;
}

void reverse(char* rev, char* str, int len, int i) {
    rev[i++] = str[len-i-1];
    if (i < len) {
        reverse(rev, str, len, i);
    } else {
        rev[i] = '\0';
        return;
    }
}
