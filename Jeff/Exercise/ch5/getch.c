#include <stdio.h>
#include "getch.h"

char buf[BUFSIZE];
int bufp = 0;

int getch() {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int ch) {
    if (bufp > BUFSIZE) {
        printf("ungetch: buffer has been full");
    } else {
        buf[bufp++] = ch;
    }
}
