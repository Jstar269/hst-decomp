/* HSTMATCH module=EBOOT.BIN start=0x0023b1e8 end=0x0023b43c symbol=FUN_0023b1e8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

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

/* Comparator functor (empty class, passed by value). */
struct KeyLess {
    int operator()(const int &x, const int &y) const {
        Entry *eX = FUN_0016bc30(x);
        Entry *eY = FUN_0016bc30(y);
        int isX = (eX->type - 4U) < 2;
        int isY = (eY->type - 4U) < 2;
        if (isX && isY) {
            return FUN_00238cc0(&eX->key, &eY->key);
        }
        if (isX && !isY) return 1;
        if (!isX && isY) return 1;
        return 0;
    }
};

/* One-pointer iterator passed by value: as a by-value class parameter MWCC gives a, b, c the
   callee-saved registers s0, s1, s2 (raw pointer parameters would get s2, s1, s0). */
struct Iter {
    int *p;
    int &operator*() const { return *p; }
};

static inline void IterSwap(Iter a, Iter b) {
    int t = *a;
    *a = *b;
    *b = t;
}

extern "C" void FUN_0023b1e8(Iter a, Iter b, Iter c, KeyLess comp) {
    bool ge13 = !comp(*c, *a);
    bool ge32 = !comp(*b, *c);

    if (!ge13 || !ge32) {
        if (!ge13 && !ge32) {
            IterSwap(a, b);
        } else {
            if (comp(*b, *a)) {
                IterSwap(a, b);
            }
            if (ge13) {
                IterSwap(b, c);
            } else {
                IterSwap(a, c);
            }
        }
    }
}
