/* HSTMATCH module=EBOOT.BIN start=0x001feec4 end=0x001fef04 symbol=FUN_001feec4 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Derived from: try/gen-a1/v0/FUN_001feec4.c (tag: a1) */
struct G1 {
    char pad[0x40];
    int base;
};
struct G2 {
    char pad[0x178];
    unsigned char flag;
};

extern struct G1 *DAT_003386c8;
extern struct G2 *DAT_00338ac4;

int FUN_001feec4(void)
{
    int iVar1 = 0;
    if (DAT_003386c8 != 0 && DAT_00338ac4 != 0) {
        int b = DAT_003386c8->base;
        if (DAT_00338ac4->flag != 0) {
            iVar1 = b + 0x1ef8;
        } else {
            iVar1 = b + 0x1aa0;
        }
    }
    return iVar1;
}
