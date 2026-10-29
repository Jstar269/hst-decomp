/* HSTMATCH module=hstp_trans_main.prx start=0x0023ce78 end=0x0023ced0 symbol=FUN_0023ce78 lang=c99 */
/* Clone of src/eboot/copy_block_0022cd78.c (hstclone.py tag c064507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int DAT_002da0f8[];
extern int DAT_003f3648[];

void FUN_0023ce78(void)
{
  int i;
  for (i = 0; i < 15; i++)
    DAT_003f3648[i] = DAT_002da0f8[i];
}
