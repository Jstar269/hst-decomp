/* HSTMATCH module=hstp_trans_main.prx start=0x001dfe8c end=0x001dff1c symbol=FUN_001dfe8c lang=c99 */
/* Clone of src/eboot/copy_float_fields_001d2088.c (hstclone.py tag u4r4s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed the copied fields as float; exact match verified; names and types await human review. */
typedef unsigned int uint;
extern void FUN_00105470(uint, int);

void FUN_001dfe8c(char *self)
{
    *(float *)(self + 0x270) = *(float *)(self + 0x274);
    *(int *)(self + 0xd4) = (*(int *)(self + 0xd8) + 6) % 6;
    **(uint **)(self + 0x6c) = 0x80808080;
    **(uint **)(self + 0x70) = 0x80808080;
    **(uint **)(self + 0x74) = 0x80808080;
    **(uint **)(self + 0x78) = 0x80808080;
    **(uint **)(self + 0x7c) = 0x80808080;
    **(uint **)(self + 0x80) = 0x80808080;
    FUN_00105470(*(uint *)(self + 0x84), 1);
    FUN_00105470(*(uint *)(self + 0x88), 1);
}
