/* HSTMATCH module=EBOOT.BIN start=0x000d0cfc end=0x000d0f2c symbol=FUN_000d0cfc lang=c99 */
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

extern undefined4 DAT_002c049c;
extern undefined2 DAT_002c049e;
extern int DAT_002c04a0;
extern int DAT_002c04a4;
extern int DAT_002c04a8;
extern int DAT_002c04ac;
extern undefined4 DAT_002c04b0;
extern undefined2 DAT_002c04b4;
extern int DAT_002c04b8;
extern int DAT_002c04bc;
extern int DAT_002c04c0;
extern int DAT_002c04c4;
extern undefined4 DAT_002c04c8;
extern int DAT_002c04cc;
extern undefined2 DAT_002c04d0;
extern int DAT_002c04d4;
extern undefined DAT_002c04e0;
extern undefined DAT_003074a0;
extern void FUN_000d5480();
extern undefined4 * FUN_000e5580();

int * FUN_000d0cfc(int *param_1)
{
  undefined2 uVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  
  FUN_000e5580();
  *param_1 = (int)&DAT_003074a0;
  param_1[0x32] = 0;
  param_1[0x33] = 0;
  param_1[0x34] = 0;
  param_1[0x60] = 0;
  param_1[0x61] = 0;
  param_1[0x62] = 0;
  *(undefined1 *)(param_1 + 0x66) = 0;
  param_1[0x67] = 0;
  param_1[0x6a] = 0;
  param_1[0x6b] = 0;
  param_1[0x6c] = 0;
  param_1[0x6d] = 0;
  param_1[0x6e] = 0;
  param_1[0x6f] = 0;
  *(undefined1 *)(param_1 + 0x70) = 0;
  param_1[0x71] = 0;
  param_1[0x73] = 0;
  param_1[0x33] = 0;
  if ((uint)param_1[0x6c] < 0x10) {
    FUN_000d5480(param_1 + 0x6a,0x10);
  }
  (**(code **)(*param_1 + 0x2c))(param_1);
  iVar5 = 0;
  piVar4 = (int *)(&DAT_002c04e0);
  piVar3 = param_1;
  do {
    iVar5 = iVar5 + 5;
    piVar3[0x38] = *piVar4;
    piVar3[0x39] = piVar4[1];
    piVar3[0x3a] = piVar4[2];
    piVar3[0x3b] = piVar4[3];
    piVar3[0x3c] = piVar4[4];
    piVar3[0x3d] = piVar4[5];
    piVar3[0x3e] = piVar4[6];
    piVar3[0x3f] = piVar4[7];
    piVar3[0x40] = piVar4[8];
    piVar3[0x41] = piVar4[9];
    piVar3[0x42] = piVar4[10];
    piVar3[0x43] = piVar4[0xb];
    piVar3[0x44] = piVar4[0xc];
    piVar3[0x45] = piVar4[0xd];
    piVar3[0x46] = piVar4[0xe];
    piVar3[0x47] = piVar4[0xf];
    piVar3[0x48] = piVar4[0x10];
    piVar3[0x49] = piVar4[0x11];
    piVar3[0x4a] = piVar4[0x12];
    piVar3[0x4b] = piVar4[0x13];
    uVar1 = DAT_002c049e;
    piVar4 = piVar4 + 0x14;
    piVar3 = piVar3 + 0x14;
  } while (iVar5 < 10);
  *(undefined1 *)(param_1 + 0x21) = DAT_002c049c;
  iVar5 = DAT_002c04a0;
  *(undefined2 *)((int)param_1 + 0x86) = uVar1;
  iVar2 = DAT_002c04a4;
  param_1[0x22] = iVar5;
  iVar5 = DAT_002c04a8;
  param_1[0x23] = iVar2;
  iVar2 = DAT_002c04ac;
  param_1[0x24] = iVar5;
  param_1[0x25] = iVar2;
  uVar1 = DAT_002c04b4;
  param_1[0x26] = DAT_002c04b0;
  iVar5 = DAT_002c04b8;
  *(undefined2 *)(param_1 + 0x27) = uVar1;
  iVar2 = DAT_002c04bc;
  param_1[0x28] = iVar5;
  iVar5 = DAT_002c04c0;
  param_1[0x29] = iVar2;
  iVar2 = DAT_002c04c4;
  param_1[0x2a] = iVar5;
  param_1[0x2b] = iVar2;
  iVar5 = DAT_002c04cc;
  param_1[0x2c] = DAT_002c04c8;
  uVar1 = DAT_002c04d0;
  param_1[0x2d] = iVar5;
  iVar5 = DAT_002c04d4;
  *(undefined2 *)(param_1 + 0x2e) = uVar1;
  param_1[0x2f] = iVar5;
  return param_1;
}
// near miss from lane fm9 (unreviewed)
