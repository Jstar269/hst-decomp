/* HSTMATCH module=hstp_trans_main.prx start=0x002320bc end=0x0023212c symbol=FUN_002320bc lang=c99 */
/* Clone of src/eboot/timer_threshold_check_00222b48.c (hstclone.py tag c192707): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag p128a) corrected by hand: typed DAT_0039835c as int and DAT_00399314 as float, placed (float)self->timer on the left of >=, and typed the flag as unsigned char; exact match verified; names and types await human review. */
typedef struct Obj_002320bc {
    char pad60[0x60];
    int timer;
    char pad64[0xb0 - 0x64];
    unsigned char flag;
} Obj_002320bc;

extern int DAT_0039835c;
extern float DAT_00399314;

int FUN_002320bc(Obj_002320bc *self)
{
    int res = 0;
    int ok = 0;
    if (self->timer >= 0 && (float)self->timer >= (float)DAT_0039835c + DAT_00399314 + 20.0f) {
        ok = 1;
    }
    if (ok != 0 && self->flag != 0) {
        res = 1;
    }
    return res;
}
