/* HSTMATCH module=EBOOT.BIN start=0x001f4c04 end=0x001f4c54 symbol=FUN_001f4c04 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p128a) corrected by hand: split the byte guard so the dependent object load fills its delay slot before the global-pointer check; exact match verified; names and types await human review. */
typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned int undefined4;

extern undefined4 DAT_00338714;
extern void FUN_0005c7a4(int param_1, int param_2, float *param_3);

void FUN_001f4c04(int param_1)
{
  int child;
  int value;
  undefined4 global;

  if (*(uchar *)(param_1 + 0x514) == 0) return;
  child = *(int *)(param_1 + 0x584);
  global = DAT_00338714;
  if (global == 0) return;
  value = *(int *)(child + 0x94);
  if (value != 1) return;
  FUN_0005c7a4(global, 0, (float *)(child + 0x110));
}
