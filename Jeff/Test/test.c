#include <stdio.h>

struct key {
    char *word;
    int count;
};

int test(struct key list[]);

int main() {
    struct key keytab[3] = 
    {
        {"auto", 0},
        {"break", 0},
        {"case", 0}
    };
    test(keytab);
    return 0;
}

int test(struct key list[]) {
    printf("%s", list[2].word);
    return 0;
}