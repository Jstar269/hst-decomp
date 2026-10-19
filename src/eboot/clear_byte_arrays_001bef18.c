/* HSTMATCH module=EBOOT.BIN start=0x001bef18 end=0x001beffc symbol=FUN_001bef18 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
void FUN_001bef18(char *o, int flag)
{
  int i;
  for (i = 0; i < 10; i++) {
    o[0xfe9 + i] = 0;
    if (flag) o[0xfe9 + i] = 4;
  }
  for (i = 0; i < 10; i++) {
    o[0xff3 + i] = 0;
    if (flag) o[0xff3 + i] = 4;
  }
  for (i = 0; i < 15; i++) {
    o[0xffd + i] = 0;
    if (flag) o[0xffd + i] = 4;
  }
  for (i = 0; i < 10; i++) {
    o[0x100c + i] = 0;
    if (flag) o[0x100c + i] = 4;
  }
  for (i = 0; i < 10; i++) {
    o[0x1016 + i] = 0;
    if (flag) o[0x1016 + i] = 4;
  }
  o[0x1024] = 0;
}
