/* HSTMATCH module=hstp_trans_main.prx start=0x001fa7c8 end=0x001fa858 symbol=FUN_001fa7c8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: the EBOOT twin src/eboot/helper_001ec488.c (positive-count fast path, named address symbol) with this module's addresses and typed structs; exact match verified; names and types await human review. */
typedef struct Game {
    char pad[0x3c];
    int mode;
} Game;

typedef struct Obj {
    char pad[0x14];
    int count;
} Obj;

extern Game *DAT_003e19f0;
extern char DAT_003eaad8[];
extern void FUN_001bfc3c(void *, int);
extern void FUN_001fa8a4(Obj *, int, int);

void FUN_001fa7c8(Obj *self, int count, int notify)
{
    self->count = count;
    if (count > 0) {
        FUN_001fa8a4(self, 1, 0);
    } else {
        if ((DAT_003e19f0 == 0 || (DAT_003e19f0->mode != 9 && DAT_003e19f0->mode != 2)) && notify != 0)
            FUN_001bfc3c(DAT_003eaad8, 11);
        FUN_001fa8a4(self, 0, 0);
    }
}
