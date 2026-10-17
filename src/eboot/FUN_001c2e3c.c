/* HSTMATCH module=EBOOT.BIN start=0x001c2e3c end=0x001c2ea8 symbol=FUN_001c2e3c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: use the raw integer helper result and explicit early return; exact match verified; names and types await human review. */
typedef unsigned int undefined4;
extern undefined4 DAT_003415ac;
extern void FUN_00103628();
extern int FUN_001155c0();
extern undefined4 FUN_001156d4();
extern void FUN_001cd88c();
void FUN_001c2e3c(int param_1)
{
  int iVar1;
  iVar1 = FUN_001155c0(DAT_003415ac);
  if (iVar1 == 0) return;
  FUN_00103628(DAT_003415ac, 1);
  iVar1 = FUN_001156d4(DAT_003415ac);
  *(unsigned char *)(param_1 + 0xb0) = iVar1 == 0;
  FUN_001cd88c(param_1, 0, 1);
}
