/* HSTMATCH module=EBOOT.BIN start=0x00118304 end=0x0011835c symbol=FUN_00118304 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern int FUN_0011cc1c();

int FUN_00118304(int param_1,short param_2)
{
  if (param_1 != 0) {
    if (param_1 != 0) {
      FUN_0011cc1c(param_1,0);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
