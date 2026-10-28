/* HSTMATCH module=EBOOT.BIN start=0x001ec518 end=0x001ec564 symbol=FUN_001ec518 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p128a); exact match verified; names and types await human review. */

extern void FUN_001e88c0();
extern void FUN_001eb960();

void FUN_001ec518(int *param_1,int param_2)
{
  if (*param_1 != 0) {
    FUN_001eb960(*param_1);
    FUN_001e88c0(*(int *)param_1[2],param_2);
  }
}
