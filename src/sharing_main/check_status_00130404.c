/* HSTMATCH module=hstp_trans_main.prx start=0x00130404 end=0x001304a4 symbol=FUN_00130404 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern void *DAT_003e1e84;
extern void *DAT_003e95c4;
extern int FUN_000dfc24(void *);
extern int FUN_000e31a0(void *);

int FUN_00130404(void)
{
    int b = FUN_000dfc24(DAT_003e1e84) != 0;
    if (!b) {
        b = ((unsigned char *)DAT_003e1e84)[0x5e] != 0;
    }
    if (!b) {
        b = FUN_000e31a0(DAT_003e1e84) != 0;
    }
    if (!b) {
        b = ((unsigned char *)DAT_003e1e84)[0x85] != 0;
    }
    if (!b) {
        b = ((unsigned char *)DAT_003e1e84)[0x62] != 0;
    }
    if (!b) {
        b = ((unsigned char *)DAT_003e95c4)[0xf1] != 0;
    }
    return b ^ 1;
}
