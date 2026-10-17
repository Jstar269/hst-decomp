/* HSTMATCH module=EBOOT.BIN start=0x0015cce8 end=0x0015ced4 symbol=FUN_0015cce8 lang=c99 rodata=0x002c1d28 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct { char b[0x28]; } Ent;
extern Ent DAT_002dcc24[];
extern Ent DAT_002dd50c[];
extern Ent DAT_002dd854[];
extern Ent DAT_002ddbc4[];
extern Ent DAT_002dde1c[];
extern Ent DAT_002ddf5c[];
extern Ent DAT_002ddf84[];
extern Ent DAT_002dd494[];
extern Ent DAT_002dda0c[];
extern void FUN_0015cbc4(int, int *, unsigned *);

int FUN_0015cce8(int unused, int param_2)
{
    int kind = 0;
    unsigned idx = 0;
    int r = 0;
    FUN_0015cbc4(param_2, &kind, &idx);
    switch (kind) {
    case 0:
        if (idx < 54) {
            r = (int)&DAT_002dcc24[idx];
        }
        break;
    case 1:
        if (idx < 21) {
            r = (int)&DAT_002dd50c[idx];
        }
        break;
    case 2:
        if (idx < 11) {
            r = (int)&DAT_002dd854[idx];
        }
        break;
    case 3:
        if (idx < 15) {
            r = (int)&DAT_002ddbc4[idx];
        }
        break;
    case 4:
        if (idx < 8) {
            r = (int)&DAT_002dde1c[idx];
        }
        break;
    case 5:
        if (idx == 0) {
            r = (int)&DAT_002ddf5c[idx];
        }
        break;
    case 6:
        if (idx < 5) {
            r = (int)&DAT_002ddf84[idx];
        }
        break;
    case 7:
    case 8:
    case 9:
        break;
    case 10:
        if (idx < 3) {
            r = (int)&DAT_002dd494[idx];
        }
        break;
    case 11:
        if (idx < 11) {
            r = (int)&DAT_002dda0c[idx];
        }
        break;
    }
    return r;
}
