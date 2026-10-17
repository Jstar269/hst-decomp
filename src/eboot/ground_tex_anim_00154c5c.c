/* HSTMATCH module=EBOOT.BIN start=0x00154c5c end=0x00154cc0 symbol=FUN_00154c5c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed FUN_00020f5c float->long long, FUN_0012d868 float parameter; exact match verified; names and types await human review. */

extern unsigned char DAT_003402f0;
extern int DAT_0033b574;
extern const char DAT_002dc9d0;
extern void FUN_0014d044(int);
extern long long FUN_00020f5c(float);
extern void FUN_0014fd94(const void *, ...);
extern void FUN_0012d868(int, float);

int FUN_00154c5c(int param_1, int param_2)
{
  if (DAT_003402f0 != 0) {
    FUN_0014d044(param_2);
    long long v = FUN_00020f5c(*(float *)(param_1 + 8));
    FUN_0014fd94(&DAT_002dc9d0, v);
  }
  FUN_0012d868(DAT_0033b574, *(float *)(param_1 + 8));
  return 0;
}
