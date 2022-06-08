#include <stdio.h>

#define min(x,y) ((x<y) ? x : y)
#define max(x,y) ((x>y) ? x : y)

struct point {
    int x, y;
};

struct rect {
    struct point pt1;
    struct point pt2;
};

int main() {
    struct rect screen;
    struct point middle;
    struct point makepoint(int x, int y);
    void addpoint(struct point*, struct point*);
    int ptinrect(struct point, struct rect);

    screen.pt1 = makepoint(0, 60);
    screen.pt2 = makepoint(120, 100);
    addpoint(&screen.pt2, &screen.pt1);

    middle = makepoint(
        (screen.pt1.x + screen.pt2.x) / 2,
        (screen.pt1.y + screen.pt2.y) / 2
    );

    struct point *middlep = &middle;
    printf("m.x:%d, m.y:%d\n", middlep->x, middlep->y);

    struct point p3 = {25, 88};
    struct point p4 = {125, 89};
    struct point p5 = {15, 29};

    printf("p3 in r: %d\n", ptinrect(p3, screen));
    printf("p4 in r: %d\n", ptinrect(p4, screen));
    printf("p5 in r: %d\n", ptinrect(p5, screen));
    return 0;
}

struct point makepoint(int x, int y) {
    struct point temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

void addpoint(struct point *p1, struct point *p2) {
    p1->x += p2->x;
    p1->y += p2->y;
}

// return 1 if p in r, 0 if not
int ptinrect(struct point p, struct rect r) {
    return p.x >= r.pt1.x && p.x <= r.pt2.x &&
        p.y >= r.pt1.y && p.y <= r.pt2.y;
}

struct rect canonrect(struct rect r) {
    struct rect temp;
    temp.pt1.x = min(r.pt1.x, r.pt2.x);
    temp.pt1.y = min(r.pt1.y, r.pt2.y);
    temp.pt2.x = max(r.pt1.x, r.pt2.x);
    temp.pt2.y = max(r.pt1.y, r.pt2.y);
    return temp;
}