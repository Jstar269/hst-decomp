/* HSTMATCH module=EBOOT.BIN start=0x00238db0 end=0x00239008 symbol=FUN_00238db0 lang=c99 */
typedef unsigned char undefined1;
typedef unsigned int undefined4;

extern void FUN_0001f06c(void);
extern void FUN_0023b7b8(void *);
extern void FUN_000649c0(void *);
extern void FUN_0008c230(void *);
extern int FUN_002af920(int);
extern void FUN_002afa48(void *, void *, int);
extern void FUN_0001f21c(int, void *);
extern int DAT_003098b0;
extern int DAT_003070bc;
extern int DAT_0034a6bc;
extern int DAT_0034a678;
extern int DAT_003386c8;
extern int DAT_0034a114;

undefined4 *FUN_00238db0(undefined4 *param_1, undefined1 param_2)
{
  int uVar1;

  FUN_0001f06c();
  *param_1 = (int)&DAT_003098b0;
  FUN_0023b7b8(param_1 + 0x14);
  param_1[0x606] = 0;
  param_1[0x607] = 0;
  param_1[0x608] = 0;
  param_1[0x60b] = 0;
  param_1[0x60c] = 0;
  param_1[0x60d] = 0;
  param_1[0x60e] = 0;
  param_1[0x60f] = 0;
  param_1[0x610] = 0;
  param_1[0x611] = 0;
  param_1[0x612] = 0;
  param_1[0x613] = 0;
  FUN_000649c0(param_1 + 0x616);
  param_1[0x616] = (int)&DAT_003070bc;
  FUN_0008c230(param_1 + 0x61a);
  FUN_0008c230(param_1 + 0x61e);
  FUN_000649c0(param_1 + 0x622);
  param_1[0x622] = (int)&DAT_003070bc;
  FUN_0008c230(param_1 + 0x626);
  FUN_0008c230(param_1 + 0x62a);
  param_1[0x62e] = 0;
  param_1[0x62f] = 0;
  param_1[0x630] = 0;
  param_1[0x631] = 0;
  param_1[0x632] = 0;
  param_1[0x633] = 0;
  param_1[0x634] = 0;
  FUN_000649c0(param_1 + 0x635);
  param_1[0x635] = (int)&DAT_003070bc;
  FUN_0008c230(param_1 + 0x639);
  FUN_0008c230(param_1 + 0x63d);
  FUN_000649c0(param_1 + 0x641);
  param_1[0x641] = (int)&DAT_003070bc;
  FUN_0008c230(param_1 + 0x645);
  FUN_0008c230(param_1 + 0x649);
  DAT_0034a6bc = (int)param_1;
  param_1[0xf] = 0;
  param_1[0x12] = 0;
  param_1[0x10] = 1;
  param_1[0x11] = 0;
  param_1[0x5e9] = 0;
  param_1[0x5ea] = 0;
  param_1[0x5eb] = 0;
  param_1[0x5ec] = 0;
  param_1[0x5ed] = 0;
  param_1[0x5ee] = 0;
  param_1[0x5ef] = 0;
  param_1[0x5f0] = 0;
  param_1[0x5f1] = 0;
  param_1[0x5f2] = 0;
  param_1[0x5f3] = 0;
  param_1[0x5f8] = 0;
  param_1[0x5f4] = 0;
  param_1[0x5f9] = 0;
  param_1[0x5f5] = 0;
  param_1[0x5fa] = 0;
  param_1[0x5f6] = 0;
  param_1[0x5fb] = 0;
  param_1[0x5f7] = 0;
  param_1[0x5fc] = 0;
  param_1[0x614] = 0;
  param_1[0x615] = 0;
  *(undefined1 *)(param_1 + 0x64d) = param_2;
  param_1[0x5fd] = 0;
  param_1[0x5fe] = 0;
  param_1[0x5ff] = 0;
  param_1[0x600] = 0;
  param_1[0x601] = 0;
  param_1[0x602] = 0;
  param_1[0x603] = 0;
  param_1[0x604] = 0;
  param_1[0x605] = 0;
  uVar1 = FUN_002af920(0);
  FUN_002afa48(param_1 + 0x609, param_1 + 0x60a, uVar1);
  *(undefined1 *)(param_1 + 0x13) = 0;
  if (DAT_0034a678 != 0x23) {
    *(undefined1 *)(param_1 + 0x13) = 1;
  }
  if (DAT_003386c8 == 0) {
    if (DAT_0034a114 == 0) {
      FUN_0001f21c(0x30fe20, param_1);
    }
    else {
      FUN_0001f21c(DAT_0034a114, param_1);
    }
  }
  else {
    FUN_0001f21c(DAT_003386c8, param_1);
  }
  return param_1;
}
// NEAR (142/150). Mechanical translation of the pseudocode; the whole body is register-name noise:
// retail keeps the char parameter in s0 (`move s0,a1` at entry) and the object in s1, while this
// version keeps the object in s0 and the char in s2 (so every store's base register differs).
// Also 8 words short overall. Tried: local copy of param_2 at entry, moving the 0x1934 store to the
// top - neither changes the allocation.
// near miss from lane fm8 (unreviewed)
