/* HSTMATCH module=hstp_trans_main.prx start=0x00177434 end=0x00177478 symbol=FUN_00177434 lang=c99 */
/* Clone of src/eboot/FUN_0016b270.c (hstclone.py tag c192707): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern char DAT_003eb004[];

int FUN_00177434(unsigned short param_1)
{
  int r;

  if (0 <= param_1 && param_1 < 0xf)
    r = (int)&DAT_003eb004[param_1 * 0x38] + 0xc8;
  else
    r = 0;
  return r;
}
