#include <stdio.h>

int strend(char *s, char *t);

int main() {
    char str1[] = "hello";
    char str2[] = "llo";
    printf("%d", strend(str1, str2));
    return 0;
}

int strend(char *s, char *t) {
    int tlen = 0;   // the len of t string
    while (printf("t: %c\n", *t) && *t++) {     // point to the end of the string
        tlen++;
    }
    t--;    // go back to the end ele '\0' to avoid overrun
    while (printf("s: %c\n", *s) && *s++)       // point to the end of the string
        ;
    s--;    // go back to the end ele '\0' to avoid overrun
    printf("tlen: %d\n", tlen);
    int i = 0;
    while (*--s == *--t) {      // count the number of same elements
        i++;
    }
    printf("tlen: %d\n", tlen);
    printf("i: %d\n", i);
    return i == tlen;       // compare whether the num of same ele equal to the len of t string
}