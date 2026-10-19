/* HSTMATCH module=hstp_trans_main.prx start=0x001d0110 end=0x001d0158 symbol=FUN_001d0110 lang=c99 */
/* Clone of src/eboot/FUN_001c1efc.c (hstclone.py tag c192707): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern signed char DAT_003eb416[2][2];

void FUN_001d0110(int param_1, int param_2, signed char param_3)
{
  if (param_1 < 0)
    return;
  if (param_1 >= 2)
    return;
  if (param_2 < 0)
    return;
  if (param_2 >= 2)
    return;
  DAT_003eb416[param_1][param_2] = param_3;
}
