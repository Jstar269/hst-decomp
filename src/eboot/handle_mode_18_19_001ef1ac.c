/* HSTMATCH module=EBOOT.BIN start=0x001ef1ac end=0x001ef2d8 symbol=FUN_001ef1ac lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: two-case switch on mode (cases 18 and 19), restored 3rd argument 1 to FUN_001fb928 and self argument to FUN_001f2f08, and typed DAT_003386b0; exact match verified; names and types await human review. */
typedef struct Game_001ef1ac {
    char pad0[0x70];
    void *players[4];
    char pad1[0x88 - 0x80];
    char *ball;
} Game_001ef1ac;

typedef struct Obj_001ef1ac {
    char pad0[0x3c];
    int sub;
    char pad1[0x514 - 0x40];
    unsigned char flag;
} Obj_001ef1ac;

extern Game_001ef1ac *DAT_003386b0;
extern void FUN_0001f20c(void *, int, int);
extern void FUN_001f2f08(Obj_001ef1ac *);
extern void FUN_001fb928(int *, int, int);

int FUN_001ef1ac(Obj_001ef1ac *self, int mode)
{
    switch (mode) {
    case 18:
        self->flag = 1;
        FUN_001fb928(&self->sub, 0, 1);
        break;
    case 19:
        self->flag = 0;
        FUN_001f2f08(self);
        for (int i = 0; i < 4; i++) {
            if (DAT_003386b0->players[i] != 0) {
                FUN_0001f20c(DAT_003386b0->players[i], 0, 1);
                FUN_0001f20c(DAT_003386b0->players[i], 1, 1);
                FUN_0001f20c(DAT_003386b0->players[i], 2, 1);
            }
        }
        FUN_0001f20c(DAT_003386b0->ball + 0x1e0, 0, 1);
        FUN_0001f20c(DAT_003386b0->ball + 0x1e0, 1, 1);
        FUN_0001f20c(DAT_003386b0->ball + 0x1e0, 2, 1);
        break;
    }
    return 0;
}
