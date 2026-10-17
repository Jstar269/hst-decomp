/* HSTMATCH module=hstp_trans_main.prx start=0x001dbb1c end=0x001dbb6c symbol=FUN_001dbb1c lang=c99 */
/* Clone of src/eboot/dispatch_mode_callback_001cd440.c (hstclone.py tag u4r4s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: ordered the threshold arms as mode greater than one; exact match verified; names and types await human review. */
extern unsigned int DAT_003e48c0;
extern void FUN_0013936c(unsigned int, int, unsigned int, int);

void FUN_001dbb1c(int *object, unsigned int value, int mode)
{
    *(unsigned char *)(*(int *)((char *)object + 0x15c) + 0x60) = 1;
    if (DAT_003e48c0 != 0) {
        int code;
        if (mode > 1) {
            code = 3;
        } else {
            code = 2;
        }
        FUN_0013936c(DAT_003e48c0, code, value, 0);
    }
}
