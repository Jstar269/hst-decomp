/* HSTMATCH module=EBOOT.BIN start=0x001548e0 end=0x00154964 symbol=FUN_001548e0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a3) corrected by hand: typed FUN_00020f5c float->long long, aligned 64-bit arg to even register pair, typed FUN_00288414 float parameter in f12; exact match verified; names and types await human review. */

extern unsigned char DAT_003402f0;
extern const char DAT_002dc95c;
extern long long FUN_00020f5c(float);
extern void FUN_0014d044(int);
extern void FUN_0014fd94(const void *, ...);
extern void FUN_00288414(int, float, int, int);

int FUN_001548e0(int param_1, int param_2)
{
  if (DAT_003402f0 != 0) {
    FUN_0014d044(param_2);
    long long v = FUN_00020f5c(*(float *)(param_1 + 8));
    FUN_0014fd94(&DAT_002dc95c, v, *(int *)(param_1 + 0xc), *(int *)(param_1 + 0x10));
  }
  int a = *(int *)(param_2 + 0xc);
  if (a != 0) {
    FUN_00288414(a, *(float *)(param_1 + 8), *(int *)(param_1 + 0xc), *(int *)(param_1 + 0x10));
  }
  return 0;
}
