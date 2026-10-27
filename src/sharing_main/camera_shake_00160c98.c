/* HSTMATCH module=hstp_trans_main.prx start=0x00160c98 end=0x00160d1c symbol=FUN_00160c98 lang=c99 data=0x00383e44 */
/* Clone of src/eboot/camera_shake_001548e0.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00383e44-0x00383e5f) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Ghidra pseudocode (hstgen.py tag a3) corrected by hand: typed FUN_00020f84 float->long long, aligned 64-bit arg to even register pair, typed FUN_00299b48 float parameter in f12; exact match verified; names and types await human review. */

extern unsigned char DAT_003e9630;
extern long long FUN_00020f84(float);
extern void FUN_00158b2c(int);
extern void FUN_0015bb68(const void *, ...);
extern void FUN_00299b48(int, float, int, int);

int FUN_00160c98(int param_1, int param_2)
{
  if (DAT_003e9630 != 0) {
    FUN_00158b2c(param_2);
    long long v = FUN_00020f84(*(float *)(param_1 + 8));
    FUN_0015bb68("CameraShake [%.3f(%d,%d)]\n", v, *(int *)(param_1 + 0xc), *(int *)(param_1 + 0x10));
  }
  int a = *(int *)(param_2 + 0xc);
  if (a != 0) {
    FUN_00299b48(a, *(float *)(param_1 + 8), *(int *)(param_1 + 0xc), *(int *)(param_1 + 0x10));
  }
  return 0;
}
