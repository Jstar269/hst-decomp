/* HSTMATCH module=EBOOT.BIN start=0x0017bce8 end=0x0017bd64 symbol=FUN_0017bce8 lang=c99 */
/* Hand-written reconstruction from the disassembly (constant-trip i*4 loop keeps its multiplies via pragmas); exact match verified; names and types await human review. */
#pragma opt_strength_reduction off
#pragma opt_unroll_loops off

extern void FUN_0005743c();

void FUN_0017bce8(int param_1,int param_2)
{
  int t = *(int *)(*(int *)(*(int *)(param_1 + 8) + param_2 * 4) + 0x68);
  if (t != 0) {
    for (int i = 0; i < 6; i++) {
      FUN_0005743c(t, i, *(int *)(*(int *)(param_1 + 0x14) + i * 4), 0);
    }
  }
}
