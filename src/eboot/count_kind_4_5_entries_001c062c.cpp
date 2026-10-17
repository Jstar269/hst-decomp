/* HSTMATCH module=EBOOT.BIN start=0x001c062c end=0x001c0684 symbol=FUN_001c062c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Ent {
    int pad0;
    unsigned char kind;
    char pad1[0x33];
};

struct Obj {
    Ent ents[15];
};

static inline unsigned char *KindAt(Obj *o, int i)
{
    if (i >= 0 && i < 15) return &o->ents[i].kind;
    return 0;
}

extern "C" int FUN_001c062c(Obj *o)
{
    int n = 0;
    for (int i = 0; i < 15; i++) {
        unsigned char *p = KindAt(o, i);
        if ((unsigned)(*p - 4) < 2) n++;
    }
    return n;
}
