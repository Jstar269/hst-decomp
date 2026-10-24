/* HSTMATCH module=EBOOT.BIN start=0x00132180 end=0x00132390 symbol=FUN_00132180__FPUi lang=c99 */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned long long undefined8;
typedef int code();
#define true 1
#define false 0
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern undefined DAT_0030820c;
extern undefined DAT_00308228;
extern undefined DAT_003386b8;
extern undefined4 DAT_003402a0;
extern undefined4 DAT_003417c4;
extern undefined1 DAT_003417cc;
extern void FUN_000133f4(unsigned int);
extern uint FUN_0001342c();
extern undefined4 * FUN_0001f06c();
extern void FUN_000c4040(unsigned int *, int);
extern void FUN_0012ca4c(unsigned int *, int);
extern bool FUN_0013293c(unsigned int *, unsigned int);
extern undefined4 * FUN_0013fb58(unsigned int *);
extern int FUN_002b78f8();

undefined4 * FUN_00132180(undefined4 *param_1)
{
  uint uVar1;
  undefined4 uVar2;
  
  FUN_0001f06c();
  FUN_0013fb58(param_1 + 0x10);
  *param_1 = (unsigned int)(&DAT_0030820c);
  param_1[0x10] = (unsigned int)(&DAT_00308228);
  param_1[0x4d8] = 1;
  param_1[0x4d9] = 1;
  *(undefined1 *)(param_1 + 0x4da) = 0;
  param_1[0x4db] = 0;
  param_1[0x4dc] = 0xffffffff;
  param_1[0x4dd] = 0xffffffff;
  param_1[0x4de] = 0xffffffff;
  param_1[0x4df] = 0xffffffff;
  param_1[0x4e0] = 0xffffffff;
  param_1[0x4e1] = 0;
  param_1[0x4e2] = 0;
  param_1[0x4e3] = 0;
  param_1[0x4e4] = 0;
  param_1[0x4e5] = 0;
  param_1[0x4e6] = 0;
  param_1[0x4e7] = 0;
  param_1[0x4e8] = 0;
  param_1[0x4e9] = 0;
  param_1[0x4ea] = 0;
  param_1[0x4eb] = 0;
  param_1[0x4ec] = 0;
  param_1[0x4ed] = 0;
  param_1[0x4ee] = 0;
  param_1[0x4ef] = 0;
  param_1[0x4f0] = 0;
  param_1[0x4f1] = 0;
  param_1[0x4f3] = 0;
  param_1[0x4f4] = 0;
  param_1[0x4f5] = 0;
  param_1[0x4f6] = 0;
  param_1[0x4f7] = 0;
  param_1[0x4f8] = 0;
  param_1[0x4f9] = 0;
  param_1[0x4fa] = 0;
  param_1[0x4fb] = 0;
  param_1[0x4fc] = 0;
  param_1[0x4fd] = 0;
  param_1[0x4fe] = 0;
  param_1[0x4ff] = 0;
  param_1[0x500] = 0;
  param_1[0x501] = 0;
  param_1[0x502] = 0;
  param_1[0x503] = 0;
  param_1[0x504] = 0;
  *(undefined1 *)(param_1 + 0x505) = 1;
  *(undefined1 *)((int)param_1 + 0x1415) = 1;
  param_1[0x506] = 0;
  *(undefined1 *)(param_1 + 0x507) = 0;
  *(undefined1 *)((int)param_1 + 0x141d) = 1;
  *(undefined1 *)((int)param_1 + 0x141e) = 0;
  *(undefined1 *)((int)param_1 + 0x141f) = 1;
  *(undefined1 *)(param_1 + 0x50b) = 0;
  param_1[0x50c] = 0;
  param_1[0x50d] = 0;
  param_1[0x50e] = 0;
  param_1[0x50f] = 0;
  *(undefined1 *)(param_1 + 0x510) = 1;
  param_1[0x511] = 0;
  param_1[0x512] = 0xffffffff;
  param_1[0x513] = 0xffffffff;
  param_1[0x514] = 0;
  param_1[0x515] = 0;
  param_1[0x516] = 0;
  param_1[0x517] = 0xffffffff;
  *(undefined1 *)(param_1 + 0x52c) = 0;
  *(undefined1 *)((int)param_1 + 0x14b1) = 0;
  *(undefined1 *)((int)param_1 + 0x14b2) = 0;
  param_1[0x52d] = 0;
  DAT_003402a0 = (unsigned int)(param_1);
  if ((uint)param_1[0x501] < 0x10) {
    FUN_000c4040(param_1 + 0x4ff,0x10);
  }
  if ((uint)param_1[0x50e] < 0x10) {
    FUN_0012ca4c(param_1 + 0x50c,0x10);
  }
  if (DAT_003386b8 == '\0') {
    uVar2 = FUN_002b78f8();
    FUN_000133f4(uVar2);
    uVar2 = FUN_0001342c();
    param_1[0x4d8] = uVar2;
  }
  else {
    param_1[0x4d8] = DAT_003417c4;
  }
  uVar1 = (uint)DAT_003417cc;
  param_1[0x4d9] = uVar1;
  if ((uVar1 == 0) || (uVar1 - 10 < 3)) {
    param_1[0x4d9] = 1;
  }
  uVar2 = param_1[0x4d9];
  FUN_0013293c(param_1,uVar2);
  *(undefined1 *)(param_1 + 0x4f2) = 0;
  return param_1;
}

// Best result: 24 differing words out of 132; first mismatch at +0x15c.
// Remaining differences are branch layout around the two small-buffer init checks and the global initialization choice.
// Ruled out volatile length reads, goto forms, condition polarity changes, C/C++ modes, and strength-reduction toggles.
// near miss from lane km4 (unreviewed)
// improved by lane fm10 (unreviewed): no comparable result -> 24 differing words
