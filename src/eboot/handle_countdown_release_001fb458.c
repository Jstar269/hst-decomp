/* HSTMATCH module=EBOOT.BIN start=0x001fb458 end=0x001fb4ec symbol=FUN_001fb458 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: restored the dropped handle argument to FUN_001b1f7c, swapped the != 0 / == 0 branches, changed -1 < handle to handle >= 0, typed the flag as unsigned char, and passed &DAT_0034179c; exact match verified; names and types await human review. */
typedef struct Obj_001fb458 {
    char pad[0x12d0];
    int handle;
    int count;
    unsigned char flag;
} Obj_001fb458;

extern unsigned int DAT_0034179c;
extern int FUN_001b1f7c(const void *, int);
extern int FUN_001b1f84(const void *, int *);

void FUN_001fb458(Obj_001fb458 *self)
{
    if (self->handle >= 0) {
        if (FUN_001b1f7c(&DAT_0034179c, self->handle) != 0) {
            self->count = self->count + 1;
        } else {
            self->count = 20;
        }
    }
    if (self->flag != 0 && self->count > 10 && self->handle >= 0) {
        FUN_001b1f84(&DAT_0034179c, &self->handle);
        self->handle = -1;
        self->flag = 0;
    }
}
