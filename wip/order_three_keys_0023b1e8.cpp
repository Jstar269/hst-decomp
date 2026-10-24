/* HSTMATCH module=EBOOT.BIN start=0x0023b1e8 end=0x0023b43c symbol=FUN_0023b1e8 lang=c++ */

struct Key {
    unsigned short s[6];
    unsigned int w;
};

struct Entry {
    unsigned char type;
    char pad[3];
    Key key;
};

extern "C" {
extern Entry *FUN_0016bc30(int);
extern unsigned char FUN_00238cc0(Key *, Key *);
}

struct Tag {};

typedef int Elem;

static inline int Compare(Elem *x, Elem *y) {
    Entry *eX = FUN_0016bc30(*x);
    Entry *eY = FUN_0016bc30(*y);
    int isX = (eX->type - 4U) < 2;
    int isY = (eY->type - 4U) < 2;
    if (isX && isY) {
        return FUN_00238cc0(&eX->key, &eY->key);
    }
    if (isX && !isY) return 1;
    if (!isX && isY) return 1;
    return 0;
}

static inline void SwapI(Elem *a, Elem *b) {
    int *pa = (int *)a;
    int *pb = (int *)b;
    int t = *pa;
    *pa = *pb;
    *pb = t;
}

extern "C" void FUN_0023b1e8(Elem *a, Elem *b, Elem *c, Tag) {
    bool ge13 = !Compare(c, a);
    bool ge32 = !Compare(b, c);

    if (!ge13 || !ge32) {
        if (!ge13 && !ge32) {
            SwapI(a, b);
        } else {
            if (Compare(b, a)) {
                SwapI(a, b);
            }
            if (ge13) {
                SwapI(b, c);
            } else {
                SwapI(a, c);
            }
        }
    }
}
// near miss: 15 words differ (0x23b204..0x23b418), pure s0/s2 register colouring swap for parameters a0 and a2.
// Retail assigns s0 to a0 and s2 to a2; MWCC assigns s2 to a0 and s0 to a2.
// Ruled out: parameter ordering, local variable declaration order, functor vs inline function, references vs pointers, bool vs int comparator returns.
// near miss from lane ag3 (unreviewed)
