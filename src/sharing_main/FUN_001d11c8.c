/* HSTMATCH module=hstp_trans_main.prx start=0x001d11c8 end=0x001d1234 symbol=FUN_001d11c8 lang=c99 */
/* Clone of src/eboot/FUN_001c2e3c.c (hstclone.py tag u6cr4s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: use the raw integer helper result and explicit early return; exact match verified; names and types await human review. */
typedef unsigned int undefined4;
extern undefined4 DAT_003ea8ec;
extern void FUN_00108f54();
extern int FUN_001204dc();
extern undefined4 FUN_001205f0();
extern void FUN_001dbf68();
void FUN_001d11c8(int param_1)
{
  int iVar1;
  iVar1 = FUN_001204dc(DAT_003ea8ec);
  if (iVar1 == 0) return;
  FUN_00108f54(DAT_003ea8ec, 1);
  iVar1 = FUN_001205f0(DAT_003ea8ec);
  *(unsigned char *)(param_1 + 0xb0) = iVar1 == 0;
  FUN_001dbf68(param_1, 0, 1);
}
