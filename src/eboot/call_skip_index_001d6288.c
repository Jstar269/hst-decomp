/* HSTMATCH module=EBOOT.BIN start=0x001d6288 end=0x001d62f8 symbol=FUN_001d6288 lang=c99 */
/* Hand-written reconstruction from the disassembly (rolled i*4 dispatch loop kept by pragmas); exact match verified; names and types await human review. */
#pragma opt_strength_reduction off
#pragma opt_unroll_loops off

extern void FUN_000ffb3c();

void FUN_001d6288(int param_1,int param_2)
{
  for (int i = 0; i < *(int *)(param_1 + 0x14); i++) {
    FUN_000ffb3c(*(int *)(*(int *)(param_1 + 0x10) + i * 4), i != param_2);
  }
}
