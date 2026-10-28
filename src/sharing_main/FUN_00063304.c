/* HSTMATCH module=hstp_trans_main.prx start=0x00063304 end=0x00063354 symbol=FUN_00063304 lang=c99 */
/* Clone of src/eboot/FUN_0021aa6c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern void FUN_00063544();

int FUN_00063304(int param_1,short param_2)
{
  if ((param_1 != 0) && (FUN_00063544(), 0 < param_2)) {
    FUN_00000a00(param_1);
  }
  return param_1;
}
