/* HSTMATCH module=EBOOT.BIN start=0x001c1efc end=0x001c1f44 symbol=FUN_001c1efc lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern signed char DAT_003420de[2][2];

void FUN_001c1efc(int param_1, int param_2, signed char param_3)
{
  if (param_1 < 0)
    return;
  if (param_1 >= 2)
    return;
  if (param_2 < 0)
    return;
  if (param_2 >= 2)
    return;
  DAT_003420de[param_1][param_2] = param_3;
}
