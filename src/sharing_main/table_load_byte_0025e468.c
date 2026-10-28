/* HSTMATCH module=hstp_trans_main.prx start=0x0025e468 end=0x0025e4a0 symbol=FUN_0025e468 lang=c99 */
/* Clone of src/eboot/table_load_byte_0024e230.c (hstclone.py tag c170007): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
signed char FUN_0025e468(int base,int a1,int a2,int a3)
{
  unsigned char b = !a1;
  char *p = (char *)(base + b * 96 + a2 * 6);
  return *(signed char *)(p + a3);
}
