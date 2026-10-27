/* HSTMATCH module=EBOOT.BIN start=0x0015592c end=0x00155978 symbol=FUN_0015592c lang=c99 data=0x002dcb28 */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0) corrected by hand: the debug flag DAT_003402f0 is a byte (lbu), not a word; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dcb28-0x002dcb3a) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
typedef unsigned char undefined1;
typedef unsigned int undefined4;

extern undefined1 DAT_003402f0;
extern undefined4 DAT_0034a114;
extern void FUN_0014d044();
extern void FUN_0014fd94();
extern void FUN_001cd0d8();

undefined4 FUN_0015592c(undefined4 param_1,undefined4 param_2)
{
  if (DAT_003402f0 != 0) {
    FUN_0014d044(param_2);
    FUN_0014fd94("SetGameOverMatch\n");
  }
  FUN_001cd0d8(DAT_0034a114,1);
  return 0;
}
