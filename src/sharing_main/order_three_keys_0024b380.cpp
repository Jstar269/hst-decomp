/* HSTMATCH module=hstp_trans_main.prx start=0x0024b380 end=0x0024b5d4 symbol=FUN_0024b380 lang=c++ */
/* Clone of src/eboot/order_three_keys_0023b1e8.cpp (hstclone.py tag c072907): addresses substituted; exact match verified; names and types await human review. */
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
extern Entry *FUN_00177e58(int);
extern unsigned char FUN_00248df8(Key *, Key *);
}

/* Comparator functor (empty class, passed by value). */
struct KeyLess {
    int operator()(const int &x, const int &y) const {
        Entry *eX = FUN_00177e58(x);
        Entry *eY = FUN_00177e58(y);
        int isX = (eX->type - 4U) < 2;
        int isY = (eY->type - 4U) < 2;
        if (isX && isY) {
            return FUN_00248df8(&eX->key, &eY->key);
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

extern "C" void FUN_0024b380(Iter a, Iter b, Iter c, KeyLess comp) {
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
