/* HSTMATCH module=hstp_trans_main.prx start=0x00209b70 end=0x00209c04 symbol=FUN_00209b70 lang=c99 */
/* Clone of src/eboot/handle_countdown_release_001fb458.c (hstclone.py tag c192707): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: restored the dropped handle argument to FUN_001c0010, swapped the != 0 / == 0 branches, changed -1 < handle to handle >= 0, typed the flag as unsigned char, and passed &DAT_003eaad8; exact match verified; names and types await human review. */
typedef struct Obj_00209b70 {
    char pad[0x12d0];
    int handle;
    int count;
    unsigned char flag;
} Obj_00209b70;

extern unsigned int DAT_003eaad8;
extern int FUN_001c0010(const void *, int);
extern int FUN_001c0018(const void *, int *);

void FUN_00209b70(Obj_00209b70 *self)
{
    if (self->handle >= 0) {
        if (FUN_001c0010(&DAT_003eaad8, self->handle) != 0) {
            self->count = self->count + 1;
        } else {
            self->count = 20;
        }
    }
    if (self->flag != 0 && self->count > 10 && self->handle >= 0) {
        FUN_001c0018(&DAT_003eaad8, &self->handle);
        self->handle = -1;
        self->flag = 0;
    }
}
