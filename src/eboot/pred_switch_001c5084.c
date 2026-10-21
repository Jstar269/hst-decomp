/* HSTMATCH module=EBOOT.BIN start=0x001c5084 end=0x001c51c8 symbol=FUN_001c5084 lang=c99 rodata=0x002c63ec */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Obj {
    char pad0[0xc4];
    unsigned fc4;
    char pad1[0xf0 - 0xc8];
    unsigned char f0f0;
    char pad2[0x164 - 0xf1];
    int f164;
    int f168;
    int f16c;
} Obj;
extern int DAT_0034a678;
extern int DAT_0034a67c;
void FUN_001c627c(Obj *);
void FUN_001c6328(Obj *);
void FUN_001c6354(Obj *);
void FUN_001c6608(Obj *);
void FUN_0001f20c(int, int, int);

static inline _Bool Inner(int k)
{
    if ((unsigned)(DAT_0034a678 - 0x23) < 2) {
        return 0;
    }
    if (k == 0x20 && (unsigned)(DAT_0034a67c - 0x23) < 2) {
        return 0;
    }
    return 1;
}

static inline _Bool Pred(Obj *o)
{
    _Bool r = !o->f16c;
    if (!r) {
        r = Inner(o->f168);
    }
    return r;
}

void FUN_001c5084(Obj *o)
{
    _Bool ok = Pred(o);
    if (o->f0f0 != 0) {
        ok = 0;
    }
    if (ok) {
        switch (o->fc4) {
        case 0:
            FUN_001c627c(o);
            break;
        case 1:
            FUN_001c6328(o);
            break;
        case 2:
        case 3:
        case 4:
            FUN_001c6354(o);
            break;
        case 5:
            FUN_001c6608(o);
            ok = 0;
        }
    }
    int h = o->f164;
    if (h != 0) {
        FUN_0001f20c(h, 2, ok && o->fc4 != 1);
    }
}
