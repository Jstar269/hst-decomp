/* HSTMATCH module=EBOOT.BIN start=0x00283358 end=0x00283660 symbol=FUN_00283358 lang=c++ */
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

extern "C" {
extern undefined DAT_002caab8;
extern undefined DAT_002caac4;
extern undefined1 DAT_003417b8;
extern undefined1 DAT_003417b9;
extern undefined1 DAT_003417ba;
extern undefined1 DAT_003417bb;
extern undefined1 DAT_003417bc;
extern undefined1 DAT_003417bd;
extern undefined1 DAT_003417c1;
extern undefined1 DAT_003417c2;
extern undefined4 DAT_003417c4;
extern undefined1 DAT_003417c8;
extern undefined1 DAT_003417cc;
extern undefined1 DAT_00341c50;
extern undefined1 DAT_00341c51;
extern undefined1 DAT_00341c52;
extern undefined DAT_00341c54;
extern undefined2 DAT_00341c78;
extern undefined2 DAT_00341cbc;
extern undefined2 DAT_00341cbe;
extern char DAT_002c6a78[];
extern void FUN_0000d518();
extern undefined * FUN_0000fe3c();
extern uint * FUN_000114c0(void *, int, int);
extern void FUN_002803d8(int, const char *);
}

struct FrameTag {};

extern "C" void FUN_00283358(int param_1, FrameTag)
{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint popCount;
  uint bitIndex;
  
  DAT_003417b8 = 0;
  DAT_003417b9 = 1;
  DAT_003417ba = 2;
  DAT_003417bb = 0;
  DAT_003417c1 = '\0';
  DAT_003417c2 = '\0';
  DAT_003417c8 = 0;
  DAT_003417b8 = (undefined1)*(undefined4 *)(param_1 + 0x5c);
  DAT_003417b9 = (undefined1)*(undefined4 *)(&DAT_002caab8 + *(int *)(param_1 + 100) * 4);
  DAT_003417ba = (undefined1)*(undefined4 *)(&DAT_002caac4 + *(int *)(param_1 + 0x68) * 4);
  DAT_003417bb = (undefined1)*(undefined4 *)(param_1 + 0x6c);
  uVar4 = *(uint *)(param_1 + 0x70);
  uVar3 = uVar4 - (uVar4 >> 1 & 0x55555555);
  uVar3 = (uVar3 & 0x33333333) + (uVar3 >> 2 & 0x33333333);
  uVar3 = uVar3 + (uVar3 >> 4) & 0xf0f0f0f;
  uVar3 = uVar3 + (uVar3 >> 8);
  uVar3 = uVar3 + (uVar3 >> 0x10) & 0xff;
  popCount = uVar3;
  switch (popCount) {
  case 0:
    DAT_003417c1 = '\0';
    DAT_003417c2 = '\0';
    break;
  case 1:
  {
    bVar1 = true;
    bitIndex = 0;
    while( true ) {
      if (bitIndex >= 0x20) {
        iVar2 = (int)(FUN_0000fe3c());
        FUN_002803d8(*(undefined4 *)(iVar2 + 0xc),DAT_002c6a78);
        FUN_0000d518();
      }
      if ((uVar4 & (1 << bitIndex)) == 0) {
        bitIndex = bitIndex + 1;
        if (0x14 < (int)bitIndex) goto LAB_002834ec;
      }
      else {
        DAT_003417c1 = (unsigned char)(bitIndex + 1);
        break;
      }
    }
LAB_002834ec:
    DAT_003417c2 = '\0';
    break;
  }
  case 2:
  {
    bitIndex = 0;
    while( true ) {
      if (bitIndex >= 0x20) {
        iVar2 = (int)(FUN_0000fe3c());
        FUN_002803d8(*(undefined4 *)(iVar2 + 0xc),DAT_002c6a78);
        FUN_0000d518();
      }
      switch (uVar4 & (1 << bitIndex)) {
      case 0:
        bitIndex = bitIndex + 1;
        if (0x14 < (int)bitIndex) goto joined_r0x00283558;
        continue;
      }
      DAT_003417c1 = (unsigned char)(bitIndex + 1);
      break;
    }
joined_r0x00283558:
    for (;;) {
      bitIndex = bitIndex + 1;
      if (0x14 < (int)bitIndex) goto LAB_002835bc;
      if (0x1f < bitIndex) {
        iVar2 = (int)(FUN_0000fe3c());
        FUN_002803d8(*(undefined4 *)(iVar2 + 0xc),DAT_002c6a78);
        FUN_0000d518();
      }
      if ((uVar4 & (1 << bitIndex)) == 0) continue;
      DAT_003417c2 = (unsigned char)(bitIndex + 1);
      break;
    }
    break;
  }
  default:
    DAT_003417cc = (undefined1)*(undefined4 *)(param_1 + 0x60);
    goto LAB_002835c0;
  }
LAB_002835bc:
  DAT_003417cc = (undefined1)*(undefined4 *)(param_1 + 0x60);
LAB_002835c0:
  DAT_00341c50 = 0;
  DAT_00341c51 = 0;
  FUN_000114c0(&DAT_00341c54,0,0x6c);
  DAT_00341cbc = 0xffff;
  DAT_00341cbe = 0xffff;
  DAT_00341c78 = 0xffff;
  DAT_003417c4 = *(undefined4 *)(param_1 + 0x10);
  DAT_003417bd = (char)*(undefined4 *)(param_1 + 0x58);
  DAT_00341c50 = (char)*(undefined4 *)(param_1 + 0x4d4);
  DAT_00341c51 = (char)*(undefined4 *)(param_1 + 0x4d8);
  DAT_00341c52 = 0;
  DAT_003417bc = 0;
  return;
}
// Near miss: 105 differing words remain; retail prologue, reset stores, bit count sequence, and switch dispatch are aligned.
// Remaining differences center on the bounded bit scan loops and final global-field updates.
// Tried MWCC and GCC profiles, byte-width globals, switch case order, separate scan index, and loop condition variants.
// near miss from lane km5 (unreviewed)
