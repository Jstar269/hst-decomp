/* HSTMATCH module=EBOOT.BIN start=0x0022cb04 end=0x0022cb40 symbol=FUN_0022cb04 lang=c99 */
extern unsigned char *DAT_003415a8;

void FUN_0022cb04(int a, int b, int c, int d, signed char v)
{
    DAT_003415a8[13568 + a * 384 + b * 64 + c * 8 + d + 36112] = v;
}
// NEAR (15/15 words, 60 bytes): twin of 0x22cad0 with a*384 (a*3<<7), b*64, c*8 and the stored byte in
// t0 (5th argument); same constant-materialisation difference (0x7fff then 0x10d1).
// near miss from lane dsn3 (unreviewed)
