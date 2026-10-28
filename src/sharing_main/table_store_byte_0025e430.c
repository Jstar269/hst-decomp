/* HSTMATCH module=hstp_trans_main.prx start=0x0025e430 end=0x0025e468 symbol=FUN_0025e430 lang=c99 */
/* Clone of src/eboot/table_store_byte_0024e1f8.c (hstclone.py tag c170007): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
void FUN_0025e430(int base,int a1,int a2,int a3,unsigned char val)
{
  unsigned char b = !a1;
  char *p = (char *)(base + b * 96 + a2 * 6);
  *(unsigned char *)(p + a3) = val;
}
