/* HSTMATCH module=EBOOT.BIN start=0x0004ae08 end=0x0004ae58 symbol=FUN_0004ae08 lang=c99 */
/* Clone of src/eboot/FUN_0021aa6c.c (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern void FUN_0004af60();

int FUN_0004ae08(int param_1,short param_2)
{
  if ((param_1 != 0) && (FUN_0004af60(), 0 < param_2)) {
    FUN_00000a00(param_1);
  }
  return param_1;
}
