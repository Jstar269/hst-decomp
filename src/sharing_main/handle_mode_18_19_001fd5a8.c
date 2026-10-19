/* HSTMATCH module=hstp_trans_main.prx start=0x001fd5a8 end=0x001fd6d4 symbol=FUN_001fd5a8 lang=c99 */
/* Clone of src/eboot/handle_mode_18_19_001ef1ac.c (hstclone.py tag c192707): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: two-case switch on mode (cases 18 and 19), restored 3rd argument 1 to FUN_0020a040 and self argument to FUN_0020139c, and typed DAT_003e19f0; exact match verified; names and types await human review. */
typedef struct Game_001fd5a8 {
    char pad0[0x70];
    void *players[4];
    char pad1[0x88 - 0x80];
    char *ball;
} Game_001fd5a8;

typedef struct Obj_001fd5a8 {
    char pad0[0x3c];
    int sub;
    char pad1[0x514 - 0x40];
    unsigned char flag;
} Obj_001fd5a8;

extern Game_001fd5a8 *DAT_003e19f0;
extern void FUN_0001ef24(void *, int, int);
extern void FUN_0020139c(Obj_001fd5a8 *);
extern void FUN_0020a040(int *, int, int);

int FUN_001fd5a8(Obj_001fd5a8 *self, int mode)
{
    switch (mode) {
    case 18:
        self->flag = 1;
        FUN_0020a040(&self->sub, 0, 1);
        break;
    case 19:
        self->flag = 0;
        FUN_0020139c(self);
        for (int i = 0; i < 4; i++) {
            if (DAT_003e19f0->players[i] != 0) {
                FUN_0001ef24(DAT_003e19f0->players[i], 0, 1);
                FUN_0001ef24(DAT_003e19f0->players[i], 1, 1);
                FUN_0001ef24(DAT_003e19f0->players[i], 2, 1);
            }
        }
        FUN_0001ef24(DAT_003e19f0->ball + 0x1e0, 0, 1);
        FUN_0001ef24(DAT_003e19f0->ball + 0x1e0, 1, 1);
        FUN_0001ef24(DAT_003e19f0->ball + 0x1e0, 2, 1);
        break;
    }
    return 0;
}
