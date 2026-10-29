/* HSTMATCH module=EBOOT.BIN start=0x0022bf74 end=0x0022bf94 symbol=FUN_0022bf74 lang=c99 */
extern unsigned char *DAT_003415a8;
struct Big { char pad[0x3500]; unsigned char arr[1]; };
int FUN_0022bf74(int a0)
{
  return ((struct Big *)DAT_003415a8)->arr[a0 + 0x8c00] != 0;
}
// near miss from lane dsn3 (unreviewed)
