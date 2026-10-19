/* HSTMATCH module=EBOOT.BIN start=0x0021b434 end=0x0021b478 symbol=FUN_0021b434 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern int FUN_0022cd60(void);
extern void FUN_001031e8(int param_1);

void FUN_0021b434(int param_1)
{
  if (*(unsigned char *)(param_1 + 0x54) != 0)
    return;
  if (*(int *)(FUN_0022cd60() + 0x138) != 0)
    return;
  FUN_001031e8(param_1);
}
