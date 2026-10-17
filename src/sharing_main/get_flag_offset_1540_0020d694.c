/* HSTMATCH module=hstp_trans_main.prx start=0x0020d694 end=0x0020d6d4 symbol=FUN_0020d694 lang=c99 */
/* Clone of src/eboot/get_flag_offset_1540_001feec4.c (hstclone.py tag s10170158a1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Derived from: try/gen-a1/v0/FUN_0020d694.c (tag: a1) */
struct G1 {
    char pad[0x40];
    int base;
};
struct G2 {
    char pad[0x178];
    unsigned char flag;
};

extern struct G1 *DAT_003e1a08;
extern struct G2 *DAT_003e1e04;

int FUN_0020d694(void)
{
    int iVar1 = 0;
    if (DAT_003e1a08 != 0 && DAT_003e1e04 != 0) {
        int b = DAT_003e1a08->base;
        if (DAT_003e1e04->flag != 0) {
            iVar1 = b + 0x1ef8;
        } else {
            iVar1 = b + 0x1aa0;
        }
    }
    return iVar1;
}
