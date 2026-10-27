/* HSTMATCH module=hstp_trans_main.prx start=0x001c437c end=0x001c4528 symbol=FUN_001c437c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: the gate keeps retail's materialised flag as `(DAT_003e1e84->b45 != 0) ^ 1` (a plain `|| b45 != 0` folds into branches); the 18-entry cell reset is a plain for loop that MWCC unrolls 6x. Same object layout as src/sharing_main/FUN_001c41bc.cpp. */
struct Cell {
    short a;
    short b;
    short c;
};

struct Global1e84 {
    char pad0[0x45];
    unsigned char b45;
};

extern "C" {
extern char DAT_003eaad8;
extern unsigned char DAT_003e19f8;
extern Global1e84 *DAT_003e1e84;
int FUN_001c0bb0(void *p, int mode);
void FUN_001c20b8(void *p);
void FUN_001c230c(void *p);
void FUN_001c251c(void *p);
void FUN_00063190(int a, int b, int c, int d);
}

struct Obj {
    char pad0[0x4c];
    int i4c;
    int i50;
    int i54;
    int i58;
    char pad1[0x78 - 0x5c];
    unsigned char b78;
    unsigned char b79;
    char pad7a[2];
    int i7c;
    int i80;
    int i84;
    int i88;
    char pad2[0x90 - 0x8c];
    unsigned char b90;
    unsigned char b91;
    unsigned char b92;
    unsigned char b93;
    unsigned char b94;
    char pad95[0xa0 - 0x95];
    Cell *cells[18];
};

extern "C" void FUN_001c437c(Obj *o)
{
    if (o->b90 != 0) {
        if (o->b93 != 0)
            o->i4c = FUN_001c0bb0(&DAT_003eaad8, 6);
        else if (o->b94 != 0)
            o->i4c = FUN_001c0bb0(&DAT_003eaad8, 5);
        else
            o->i4c = FUN_001c0bb0(&DAT_003eaad8, 4);
    } else if (o->b91 != 0) {
        o->i4c = FUN_001c0bb0(&DAT_003eaad8, 7);
    } else {
        o->i4c = FUN_001c0bb0(&DAT_003eaad8, 4);
    }
    FUN_001c20b8(&DAT_003eaad8);
    FUN_001c230c(&DAT_003eaad8);
    FUN_00063190(3, 0x80, 0x80, 0);
    o->b78 = 1;
    o->b79 = 1;
    o->i7c = 0;
    o->i84 = 0;
    o->i88 = 0;
    o->i58 = 0;
    if (!(DAT_003e19f8 != 0 && (DAT_003e1e84->b45 != 0) ^ 1))
        FUN_001c251c(&DAT_003eaad8);
    for (int i = 0; i < 18; i++) {
        Cell *c = o->cells[i];
        c->a = 0;
        c->b = 2;
        c->c = 0;
    }
}
