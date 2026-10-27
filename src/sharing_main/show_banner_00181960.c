/* HSTMATCH module=hstp_trans_main.prx start=0x00181960 end=0x001819fc symbol=FUN_00181960 lang=c99 */
/* Hand-written reconstruction from the disassembly (adapted from the exact EBOOT sibling src/eboot/show_banner_0017551c.c, same instruction shape with this module's addresses): FUN_001781f0 returns unsigned char (andi 0xff in the caller), the two calls are `if (c != 0) {call} else if (DAT_003f39a8 == 3) {call}` so the zero case is the out-of-line block, the first argument is float 0.33333334f in $f12; exact match verified; names and types await human review. */
extern int DAT_003f39a8;
extern char DAT_003eaad8[];
extern int DAT_003ea8ec;
extern unsigned char FUN_001781f0(int);
extern void FUN_001c2130(float, char *);
extern void FUN_0020c8c4(int);
extern void FUN_00108f54(int, int);
extern void FUN_0017803c(int);

void FUN_00181960(int param_1)
{
    unsigned char cVar1;

    *(int *)(param_1 + 0x74) = 0x24;
    cVar1 = FUN_001781f0(1);
    if (cVar1 != 0) {
        FUN_001c2130(0.33333334f, DAT_003eaad8);
    } else if (DAT_003f39a8 == 3) {
        FUN_001c2130(0.33333334f, DAT_003eaad8);
    }
    FUN_0020c8c4(1);
    FUN_00108f54(DAT_003ea8ec, 1);
    FUN_0017803c(0x24);
}
