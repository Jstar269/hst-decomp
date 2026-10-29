/* HSTMATCH module=EBOOT.BIN start=0x0021b434 end=0x0021b478 symbol=FUN_0021b434 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern int FUN_0022cd60(void);
extern void FUN_001031e8(int self);

/* Runs the base action only while the screen is not finished and the mode context field is 0. */
void FUN_0021b434(int self)
{
  if (*(unsigned char *)(self + 0x54) != 0)
    return;
  if (*(int *)(FUN_0022cd60() + 0x138) != 0)
    return;
  FUN_001031e8(self);
}
