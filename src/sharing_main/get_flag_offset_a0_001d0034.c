/* HSTMATCH module=hstp_trans_main.prx start=0x001d0034 end=0x001d0074 symbol=FUN_001d0034 lang=c99 */
/* Clone of src/eboot/get_flag_offset_a0_001c1e20.c (hstclone.py tag s10170158a1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Derived from: try/gen-a1/v0/FUN_001d0034.c (tag: a1) */
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

int FUN_001d0034(void)
{
    int iVar1 = 0;
    if (DAT_003e1a08 != 0 && DAT_003e1e04 != 0) {
        int b = DAT_003e1a08->base;
        if (DAT_003e1e04->flag != 0) {
            iVar1 = b + 0x3184;
        } else {
            iVar1 = b + 0x1bac;
        }
    }
    return iVar1;
}
