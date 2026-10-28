/* HSTMATCH module=hstp_trans_main.prx start=0x000982b0 end=0x000982d4 symbol=FUN_000982b0 lang=c99 */
/* Clone of src/eboot/flag_and_field_00096178.c (hstclone.py tag c170007): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern unsigned char DAT_003e19f8;
int FUN_000982b0(int a0)
{
  return DAT_003e19f8 != 0 && *(unsigned char *)(a0 + 0x1b4) != 0;
}
