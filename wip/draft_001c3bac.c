/* HSTMATCH module=EBOOT.BIN start=0x001c3bac end=0x001c4170 symbol=FUN_001c3bac lang=c99 */
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

extern undefined4 DAT_002bc440;
extern undefined4 DAT_002bc444;
extern undefined4 DAT_002bc448;
extern undefined4 DAT_002bc44c;
extern undefined4 DAT_002ea2cc;
extern undefined4 DAT_002ea2d0;
extern undefined4 DAT_002ea420;
extern undefined DAT_00309320;
extern undefined4 DAT_00310fc4;
extern undefined * DAT_003415a8;
extern undefined DAT_00341d10;
extern undefined4 DAT_00341d34;
extern undefined4 DAT_00341d78;
extern undefined4 DAT_00341d7a;
extern undefined4 DAT_00341d7c;
extern undefined4 DAT_0034a110;
extern undefined4 DAT_0034a114;
extern int FUN_00000bcc();
extern uint * FUN_000114c0();
extern undefined4 * FUN_0001f06c();
extern void FUN_0001f21c();
extern void FUN_00042698();
extern int * FUN_000649c0();
extern undefined4 * FUN_00155ea4();
extern undefined4 * FUN_001b8d38();
extern undefined4 * FUN_001c2250();
extern void FUN_001c51c8();
extern void FUN_001ce598();
extern void FUN_001ce64c();
extern void FUN_001ce7b0();
extern int FUN_0022a930();
extern bool FUN_0022c0d4();
extern undefined4 * FUN_002636d8();
extern undefined4 * FUN_00289cd4();
extern undefined4 * FUN_0028ae30();
extern void FUN_002a4938();

undefined4 * FUN_001c3bac(undefined4 *param_1)
{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 *puVar5;
  ushort uVar6;
  undefined4 local_4;
  undefined4 local_8;
  undefined4 local_c;
  
  FUN_0001f06c();
  *param_1 = (unsigned int)(&DAT_00309320);
  iVar2 = FUN_00000bcc(4);
  if (iVar2 == 0) {
    param_1[0xf] = 0;
  }
  else {
    uVar3 = (unsigned int)(FUN_00155ea4(iVar2));
    param_1[0xf] = uVar3;
  }
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  param_1[0x1f] = 0;
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  param_1[0x26] = 0;
  param_1[0x53] = 0;
  iVar2 = FUN_00000bcc(0x110);
  if (iVar2 == 0) {
    param_1[0x57] = 0;
  }
  else {
    uVar3 = (unsigned int)(FUN_001c2250(iVar2,param_1));
    param_1[0x57] = uVar3;
  }
  param_1[0x58] = 0;
  param_1[0x59] = 0;
  param_1[0x5b] = 0;
  param_1[0x5c] = 0;
  iVar2 = FUN_00000bcc(0x10);
  if (iVar2 == 0) {
    param_1[0x5e] = 0;
  }
  else {
    uVar3 = (unsigned int)(FUN_000649c0(iVar2));
    param_1[0x5e] = uVar3;
  }
  iVar2 = FUN_00000bcc(0x28);
  if (iVar2 == 0) {
    param_1[0x5f] = 0;
  }
  else {
    uVar3 = (unsigned int)(FUN_0028ae30(iVar2));
    param_1[0x5f] = uVar3;
  }
  FUN_00289cd4(param_1 + 0x60);
  FUN_002a4938();
  FUN_000114c0(&DAT_00341d10,0,0x6c);
  DAT_00341d78 = 0xffff;
  DAT_00341d7a = 0xffff;
  DAT_00341d34 = 0xffff;
  DAT_00341d7c = 0;
  iVar2 = FUN_0022a930();
  if (-1 < *(int *)(iVar2 + 0xab40)) {
    iVar2 = FUN_0022c0d4();
    if (iVar2 != 0) {
      iVar2 = FUN_0022a930();
      uVar1 = *(ushort *)(iVar2 + 0xab40);
      if ((int)(uint)uVar1 < DAT_002ea2cc) {
        *(short *)(DAT_003415a8 + 0x10b4) = (short)DAT_002ea2cc;
      }
      else {
        uVar6 = (ushort)DAT_002ea2d0;
        if ((int)(uint)uVar1 <= DAT_002ea2d0) {
          uVar6 = uVar1;
        }
        *(ushort *)(DAT_003415a8 + 0x10b4) = uVar6;
      }
    }
    iVar2 = FUN_0022a930();
    *(undefined4 *)(iVar2 + 0xab40) = 0xffffffff;
  }
  FUN_00042698(DAT_00310fc4,0x200,0x200);
  DAT_0034a114 = (unsigned int)(param_1);
  FUN_0001f21c(0x30fe20,param_1);
  param_1[0x11] = 0;
  if ((uint)param_1[0x12] < 0x80) {
    FUN_001ce64c(param_1 + 0x10,0x80);
  }
  param_1[0x17] = 0;
  if ((uint)param_1[0x18] < 0x20) {
    FUN_001ce64c(param_1 + 0x16,0x20);
  }
  local_4 = 0;
  uVar4 = param_1[0x14];
  if (uVar4 < 0x28) {
    FUN_001ce598(param_1 + 0x13,0x28 - uVar4,&local_4,0);
  }
  else if (0x28 < uVar4) {
    param_1[0x14] = 0x28;
  }
  local_8 = 0;
  uVar4 = param_1[0x1a];
  if (uVar4 < 0x28) {
    FUN_001ce7b0(param_1 + 0x19,0x28 - uVar4,&local_8,0);
  }
  else if (0x28 < uVar4) {
    param_1[0x1a] = 0x28;
  }
  local_c = 0;
  uVar4 = param_1[0x20];
  if (uVar4 < 0x40) {
    FUN_001ce598(param_1 + 0x1f,0x40 - uVar4,&local_c,0);
  }
  else if (0x40 < uVar4) {
    param_1[0x20] = 0x40;
  }
  param_1[0x1d] = 0;
  if ((uint)param_1[0x1e] < 0x20) {
    FUN_001ce64c(param_1 + 0x1c,0x20);
  }
  param_1[0x23] = 0;
  if ((uint)param_1[0x24] < 0x20) {
    FUN_001ce64c(param_1 + 0x22,0x20);
  }
  param_1[0x28] = DAT_002bc440;
  param_1[0x29] = DAT_002bc444;
  param_1[0x2a] = DAT_002bc448;
  param_1[0x2b] = DAT_002bc44c;
  param_1[0x2c] = DAT_002bc440;
  param_1[0x2d] = DAT_002bc444;
  param_1[0x2e] = DAT_002bc448;
  param_1[0x2f] = DAT_002bc44c;
  param_1[0x30] = 0xffffffff;
  param_1[0x31] = 1;
  param_1[0x32] = 0;
  param_1[0x33] = DAT_002ea420;
  param_1[0x34] = DAT_0034a110;
  param_1[0x35] = 0xffffffff;
  param_1[0x36] = 0xffffffff;
  param_1[0x37] = 0xffffffff;
  *(undefined1 *)(param_1 + 0x38) = 0;
  *(undefined1 *)((int)param_1 + 0xe1) = 0;
  *(undefined1 *)((int)param_1 + 0xe2) = 0;
  param_1[0x39] = 0xffffffff;
  param_1[0x3a] = 0xffffffff;
  param_1[0x3b] = 0xffffffff;
  iVar2 = FUN_0022a930();
  if (*(int *)(iVar2 + 0xab20) < 0) {
    *(undefined1 *)(param_1 + 0x3c) = 0;
  }
  else {
    FUN_001c51c8(param_1,1);
    iVar2 = FUN_0022a930();
    param_1[0x33] = *(undefined4 *)(iVar2 + 0xab20);
    iVar2 = FUN_0022a930();
    param_1[0x34] = *(undefined4 *)(iVar2 + 0xab24);
    *(undefined1 *)(param_1 + 0x3c) = 0;
  }
  *(undefined1 *)((int)param_1 + 0xf1) = 0;
  *(undefined1 *)((int)param_1 + 0xf2) = 0;
  *(undefined1 *)((int)param_1 + 0xf3) = 0;
  *(undefined1 *)(param_1 + 0x3d) = 0;
  *(undefined1 *)((int)param_1 + 0xf5) = 0;
  *(undefined1 *)((int)param_1 + 0xf6) = 0;
  *(undefined1 *)((int)param_1 + 0xf7) = 0;
  *(undefined1 *)(param_1 + 0x3e) = 0;
  *(undefined1 *)((int)param_1 + 0xf9) = 0;
  *(undefined1 *)((int)param_1 + 0xfa) = 0;
  *(undefined1 *)((int)param_1 + 0xfb) = 0;
  *(undefined1 *)(param_1 + 0x3f) = 0;
  *(undefined1 *)((int)param_1 + 0xfd) = 0;
  *(undefined1 *)((int)param_1 + 0xfe) = 0;
  param_1[0x40] = 0xffffffff;
  FUN_000114c0(param_1 + 0x41,0,0x10);
  FUN_000114c0(param_1 + 0x45,0,0x10);
  FUN_000114c0(param_1 + 0x49,0,0x10);
  uVar4 = 0;
  puVar5 = param_1;
  do {
    uVar4 = uVar4 + 1;
    puVar5[0x4d] = 0xffffffff;
    puVar5 = puVar5 + 1;
  } while (uVar4 < 6);
  param_1[0x54] = 0xffffffff;
  param_1[0x55] = 5;
  param_1[0x56] = 0;
  iVar2 = FUN_00000bcc(0x4c);
  if (iVar2 == 0) {
    param_1[0x58] = 0;
    uVar3 = 0;
  }
  else {
    uVar3 = (unsigned int)(FUN_001b8d38(iVar2));
    param_1[0x58] = uVar3;
  }
  FUN_0001f21c(param_1,uVar3);
  iVar2 = FUN_00000bcc(0x4c);
  if (iVar2 == 0) {
    param_1[0x59] = 0;
    uVar3 = 0;
  }
  else {
    uVar3 = (unsigned int)(FUN_002636d8(iVar2));
    param_1[0x59] = uVar3;
  }
  FUN_0001f21c(param_1,uVar3);
  param_1[0x5a] = 0x59;
  *(undefined1 *)(param_1 + 99) = 1;
  *(undefined1 *)((int)param_1 + 0x18d) = 1;
  *(undefined1 *)((int)param_1 + 0x18e) = 1;
  return param_1;
}
// near miss from lane fm11 (unreviewed)
