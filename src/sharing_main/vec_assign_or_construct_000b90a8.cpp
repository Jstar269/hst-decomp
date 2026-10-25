/* HSTMATCH module=hstp_trans_main.prx start=0x000b90a8 end=0x000b91c4 symbol=FUN_000b90a8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

#include <stddef.h>

inline void *operator new(size_t, void *p) { return p; }

struct Rec {
    float m[16];
    int n;

    Rec() {}
    Rec(const Rec &s) {
        m[0] = s.m[0]; m[1] = s.m[1]; m[2] = s.m[2]; m[3] = s.m[3];
        m[4] = s.m[4]; m[5] = s.m[5]; m[6] = s.m[6]; m[7] = s.m[7];
        m[8] = s.m[8]; m[9] = s.m[9]; m[10] = s.m[10]; m[11] = s.m[11];
        m[12] = s.m[12]; m[13] = s.m[13]; m[14] = s.m[14]; m[15] = s.m[15];
        n = s.n;
    }
};

struct Item {
    Rec rec;
    char pad[12];
};

struct Container {
    int unk0;
    int size;
    Item *start;
};

struct Helper {
    Item *cur;
    Container *c;
};

extern "C" Item *FUN_000b90a8(Helper *it, const Rec *val)
{
    if (it->cur - it->c->start < it->c->size) {
        it->cur->rec = *val;
    } else {
        new (it->cur) Rec(*val);
        it->c->size++;
    }
    return it->cur;
}
