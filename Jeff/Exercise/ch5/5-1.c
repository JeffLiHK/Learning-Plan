#include <stdio.h>
#include <ctype.h>
#include "getch.h"
#define SIZE 1000

// not done

int main() {
    int n, array[SIZE], getint(int *);

    for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++) {
        ;
    }

    for (int i = 0; i < n; i++) {
        printf("the %d ele: %d\n", i, array[i]);
    }
}

int getint (int *pn) {
    int c, sign;
    
    while (isspace(c = getch())) {
    }
    if (!isdigit(c) && c != EOF & c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        c = getch();
    }
    for (*pn = 0; isdigit(c); c = getch()) {
        *pn = 10 * *pn + (c - '0');
    }
    *pn *= sign;
    if (c != EOF) {
        ungetch(c);
    }
    return c;
}