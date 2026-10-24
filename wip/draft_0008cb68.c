/* HSTMATCH module=EBOOT.BIN start=0x0008cb68 end=0x0008cd9c symbol=FUN_0008cb68 lang=c99 */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned char bool;
typedef unsigned long long undefined8;
typedef int code();
#define true 1
#define false 0
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern undefined2 DAT_002d2442;
extern undefined DAT_002d26b4;
extern undefined DAT_003071f4;
extern undefined4 DAT_003386b8;
extern undefined4 DAT_003386c8;
extern undefined2 DAT_003417be;
extern undefined4 DAT_0034a678;
extern undefined4 DAT_0034a67c;
extern void FUN_00000010();
extern void FUN_00000018();
extern void FUN_00000788();
extern void FUN_000007f4();
extern void FUN_00000a00();
extern int FUN_00000bcc();
extern uint * FUN_000114c0();
extern undefined4 * FUN_0001f06c();
extern void FUN_0001f21c();
extern int * FUN_0008be64();
extern void FUN_0008cd9c();
extern undefined4 * FUN_0008cea4();
extern int FUN_0008d47c();
extern int FUN_0008d6cc();
extern int FUN_0008d72c();
extern void FUN_002a4938();
extern void FUN_002b7960();

undefined4 * FUN_0008cb68(undefined4 *param_1)
{
  undefined4 uVar1;
  int iVar2;
  
  FUN_0001f06c();
  *param_1 = (unsigned int)(&DAT_003071f4);
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  *(undefined1 *)(param_1 + 0x11) = 0;
  FUN_00000010(&DAT_002d26b4);
  FUN_002b7960(0,0x28);
  if ((DAT_0034a67c == 2) || (DAT_0034a67c == 0x20)) {
    if ((DAT_0034a678 != 0x26) && ((DAT_0034a678 != 0x25 && (DAT_0034a678 != 0x24)))) {
      FUN_002a4938();
    }
  }
  else {
    FUN_002a4938();
  }
  DAT_002d2442 = 1;
  DAT_003386b8 = 0;
  DAT_003417be = 0;
  iVar2 = param_1[0x10];
  DAT_003386c8 = (unsigned int)(param_1);
  if (iVar2 != 0) {
    if (iVar2 != 0) {
      FUN_0008d72c(iVar2 + 0x3078,0xffffffff);
      FUN_0008d72c(iVar2 + 0x2c20,0xffffffff);
      FUN_00000788(iVar2 + 0x1aa0,FUN_0008d72c,0x458,4);
      FUN_00000788(iVar2 + 0x940,FUN_0008d72c,0x458,4);
      FUN_0008d72c(iVar2 + 0x4e8,0xffffffff);
      FUN_0008d6cc(iVar2,0xffffffff);
      FUN_00000a00(iVar2);
    }
    param_1[0x10] = 0;
  }
  iVar2 = FUN_00000bcc(0x38e0);
  if (iVar2 != 0) {
    FUN_0008d47c(iVar2);
    FUN_0008cea4(iVar2 + 0x4e8);
    FUN_000007f4(iVar2 + 0x940,FUN_0008cea4,FUN_0008d72c,0x458,4);
    FUN_000007f4(iVar2 + 0x1aa0,FUN_0008cea4,FUN_0008d72c,0x458,4);
    FUN_0008cea4(iVar2 + 0x2c20);
    FUN_0008cea4(iVar2 + 0x3078);
    FUN_000114c0(iVar2,0,0x38e0);
    FUN_0008cd9c(iVar2);
  }
  param_1[0x10] = iVar2;
  iVar2 = FUN_00000bcc(0x9e0);
  uVar1 = 0;
  if (iVar2 != 0) {
    uVar1 = (unsigned int)(FUN_0008be64(iVar2));
  }
  param_1[0xf] = uVar1;
  FUN_0001f21c(0x30fe20,param_1);
  FUN_00000018();
  return param_1;
}
// near miss from lane fm9 (unreviewed)
