/* HSTMATCH module=hstp_trans_main.prx start=0x001ccc6c end=0x001ccd50 symbol=FUN_001ccc6c lang=c99 */
/* Clone of src/eboot/clear_byte_arrays_001bef18.c (hstclone.py tag c192707): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
void FUN_001ccc6c(char *o, int flag)
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
