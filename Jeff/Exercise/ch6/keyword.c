#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define NKEYS (sizeof keytab / sizeof(keytab[0]))
#define BUFSIZE 1000

char buf[BUFSIZE];
int bufp = 0;

int getch() {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int ch) {
    if (bufp > BUFSIZE) {
        printf("ungetch: buffer has been full");
    }
    else {
        buf[bufp++] = ch;
    }
}


struct key {
    char* word;
    int count;
};

int getword(char*, int);
struct key *binsearch(char *word, struct key *tab, int n);

int main() {
    struct key * n;
    char word[MAXWORD];

    struct key keytab[3] =
    {
        {"auto", 0},
        {"break", 0},
        {"case", 0}
    };

    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0])) {
            if ((n = binsearch(word, keytab, NKEYS)) != NULL) {
                n->count++;
            }
        }
    }

    for (int i = 0; i < NKEYS; i++) {
        if (keytab[i].count > 0) {
            printf("%4d %s\n", keytab[i].count, keytab[i].word);
        }
    }

    return 0;
}

struct key *binsearch(char *word, struct key *tab, int n) {
    int cond;
    struct key *low = &tab[0];
    struct key *high = &tab[n];
    struct key *mid;

    while (low < high) {
        mid = low + (high - low) / 2;
        if ((cond = strcmp(word, mid->word)) < 0)
            high = mid;
        else if (cond > 0) 
            low = mid;
        else
            return mid;
    }

    return NULL;
}

// int binsearch(char* word, struct key tab[], int n) {
//     int cond;
//     int low, high, mid;

//     low = 0;
//     high = n - 1;
//     while (low <= high) {
//         mid = (low + high) / 2;
//         if ((cond = strcmp(word, tab[mid].word)) < 0) {
//             high = mid - 1;
//         }
//         else if (cond > 0) {
//             low = mid + 1;
//         }
//         else {
//             return mid;
//         }
//     }
//     return -1;
// }

int getword(char* word, int lim) {
    int c, getch(void);
    void ungetch(int);
    char* w = word;

    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }
    for (; --lim > 0; w++) {
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    }
    *w = '\0';
    return word[0];
}