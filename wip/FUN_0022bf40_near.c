/* HSTMATCH module=EBOOT.BIN start=0x0022bf40 end=0x0022bf74 symbol=FUN_0022bf40 lang=c99 */
extern signed char *DAT_003415a8;

void FUN_0022bf40(signed char v)
{
    int i;
    for (i = 0; i < 256; i++)
        DAT_003415a8[i + 0xC100] = v;
}
// NEAR (whole shape, 52 bytes): retail materialises the +0xC100 offset as `lui v1,0x1` (0x10000) plus a
// -0x3F00 displacement on the store, per iteration, and indexes `G + i`. Writing the offset as one
// constant made MWCC emit 58 words.
// near miss from lane dsn3 (unreviewed)
