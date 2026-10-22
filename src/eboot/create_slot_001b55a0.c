/* HSTMATCH module=EBOOT.BIN start=0x001b55a0 end=0x001b5640 symbol=FUN_001b55a0 lang=c99 */
/* Hand-written reconstruction from the disassembly (sibling of 0x1b5764); exact match verified; names and types await human review. */
extern int DAT_0034179c[];
extern float DAT_002e9960;
extern void FUN_001b2040(int *, int *, float);
extern int FUN_001b4a70(int *, int, int);

int FUN_001b55a0(int param_1, int param_2, int param_3, unsigned char param_4)
{
  int *slot = (int *)(*(int *)(param_1 + 0x5c) + param_2 * 4);

  if (*slot >= 0)
    FUN_001b2040(DAT_0034179c, slot, DAT_002e9960);
  *slot = FUN_001b4a70(DAT_0034179c, param_2, param_3);
  *(char *)(*(int *)(param_1 + 0x60) + param_2) = param_4;
  return *slot;
}
