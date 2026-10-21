/* HSTMATCH module=hstp_trans_main.prx start=0x001d341c end=0x001d3560 symbol=FUN_001d341c lang=c99 rodata=0x002d68fc */
/* Clone of src/eboot/pred_switch_001c5084.c (hstclone.py tag c21sn1s): addresses substituted; exact match verified; names and types await human review. */
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
extern int DAT_003f39a8;
extern int DAT_003f39ac;
void FUN_001d4674(Obj *);
void FUN_001d4720(Obj *);
void FUN_001d474c(Obj *);
void FUN_001d4a00(Obj *);
void FUN_0001ef24(int, int, int);

static inline _Bool Inner(int k)
{
    if ((unsigned)(DAT_003f39a8 - 0x23) < 2) {
        return 0;
    }
    if (k == 0x20 && (unsigned)(DAT_003f39ac - 0x23) < 2) {
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

void FUN_001d341c(Obj *o)
{
    _Bool ok = Pred(o);
    if (o->f0f0 != 0) {
        ok = 0;
    }
    if (ok) {
        switch (o->fc4) {
        case 0:
            FUN_001d4674(o);
            break;
        case 1:
            FUN_001d4720(o);
            break;
        case 2:
        case 3:
        case 4:
            FUN_001d474c(o);
            break;
        case 5:
            FUN_001d4a00(o);
            ok = 0;
        }
    }
    int h = o->f164;
    if (h != 0) {
        FUN_0001ef24(h, 2, ok && o->fc4 != 1);
    }
}
