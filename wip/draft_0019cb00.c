/* HSTMATCH module=EBOOT.BIN start=0x0019cb00 end=0x0019cec4 symbol=FUN_0019cb00 lang=c99 */
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

extern undefined DAT_002c2ad8;
extern undefined DAT_002e1b44;
extern undefined DAT_00307f60;
extern undefined DAT_003091e8;
extern void FUN_000ffb3c();
extern void FUN_00100de8();
extern void FUN_001016f4();
extern undefined4 * FUN_00103d6c();
extern undefined4 * FUN_00103d80();
extern void FUN_0010b308();
extern void FUN_0010b76c();

int * FUN_0019cb00(int *param_1,undefined4 param_2)
{
  short sVar1;
  short sVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  FUN_00103d80(param_1,&DAT_002e1b44);
  *param_1 = (int)&DAT_00307f60;
  FUN_00103d6c(param_1 + 0x48);
  FUN_0010b308(param_1);
  *param_1 = (int)&DAT_003091e8;
  param_1[0x4d] = 0;
  param_1[0x4e] = 0;
  param_1[0x70] = 0;
  FUN_00100de8(param_1,param_2);
  FUN_001016f4(param_1,&DAT_002c2ad8,6);
  (**(code **)(*param_1 + 0x20))(0x4541c000,param_1);
  FUN_000ffb3c(*(undefined4 *)param_1[4],0);
  FUN_000ffb3c(*(undefined4 *)(param_1[4] + 4),0);
  FUN_000ffb3c(*(undefined4 *)(param_1[4] + 8),1);
  iVar5 = ((int *)param_1[4])[1];
  sVar1 = *(short *)(*(int *)param_1[4] + 10);
  sVar2 = *(short *)(iVar5 + 4);
  *(undefined2 *)(iVar5 + 4) = 0;
  *(short *)(iVar5 + 8) = *(short *)(iVar5 + 8) - sVar2;
  sVar2 = *(short *)(iVar5 + 6);
  *(short *)(iVar5 + 6) = sVar1;
  *(short *)(iVar5 + 10) = *(short *)(iVar5 + 10) + (sVar1 - sVar2);
  iVar5 = *(int *)(param_1[4] + 8);
  sVar1 = *(short *)(*(int *)(param_1[4] + 4) + 10);
  sVar2 = *(short *)(iVar5 + 4);
  *(undefined2 *)(iVar5 + 4) = 0;
  *(short *)(iVar5 + 8) = *(short *)(iVar5 + 8) - sVar2;
  sVar2 = *(short *)(iVar5 + 6);
  *(short *)(iVar5 + 6) = sVar1;
  *(short *)(iVar5 + 10) = *(short *)(iVar5 + 10) + (sVar1 - sVar2);
  param_1[0x35] = 3;
  param_1[0x36] = 2;
  *(undefined1 *)(param_1 + 0x45) = 1;
  iVar3 = *(int *)param_1[4];
  iVar5 = (int)(short)(*(short *)(iVar3 + 8) - *(short *)(iVar3 + 4));
  FUN_0010b76c(param_1,(int)(short)(4 - (short)(iVar5 / 4)),(int)(short)(*(short *)(iVar3 + 6) + 2)
               ,0,0,3);
  iVar3 = *(int *)(param_1[4] + 4);
  iVar5 = (int)(short)(*(short *)(iVar3 + 8) - *(short *)(iVar3 + 4));
  FUN_0010b76c(param_1,(int)(short)(4 - (short)(iVar5 / 4)),(int)(short)(*(short *)(iVar3 + 6) + 2)
               ,0,0,3);
  param_1[0xc] = 0x3f666666;
  param_1[0x11] = 0x3f666666;
  param_1[0x18] = 0x43320000;
  param_1[0x19] = 0x43380000;
  piVar4 = *(int **)param_1[4];
  param_1[0x4f] = *piVar4;
  *(short *)(param_1 + 0x50) = (short)piVar4[1];
  *(undefined2 *)((int)param_1 + 0x142) = *(undefined2 *)((int)piVar4 + 6);
  *(short *)(param_1 + 0x51) = (short)piVar4[2];
  *(undefined2 *)((int)param_1 + 0x146) = *(undefined2 *)((int)piVar4 + 10);
  *(short *)(param_1 + 0x52) = (short)piVar4[3];
  *(undefined2 *)((int)param_1 + 0x14a) = *(undefined2 *)((int)piVar4 + 0xe);
  param_1[0x53] = piVar4[4];
  param_1[0x54] = piVar4[5];
  param_1[0x55] = piVar4[6];
  param_1[0x56] = piVar4[7];
  param_1[0x57] = piVar4[8];
  param_1[0x58] = piVar4[9];
  param_1[0x59] = piVar4[10];
  piVar4 = *(int **)(param_1[4] + 4);
  param_1[0x5a] = *piVar4;
  *(short *)(param_1 + 0x5b) = (short)piVar4[1];
  *(undefined2 *)((int)param_1 + 0x16e) = *(undefined2 *)((int)piVar4 + 6);
  *(short *)(param_1 + 0x5c) = (short)piVar4[2];
  *(undefined2 *)((int)param_1 + 0x172) = *(undefined2 *)((int)piVar4 + 10);
  *(short *)(param_1 + 0x5d) = (short)piVar4[3];
  *(undefined2 *)((int)param_1 + 0x176) = *(undefined2 *)((int)piVar4 + 0xe);
  param_1[0x5e] = piVar4[4];
  param_1[0x5f] = piVar4[5];
  param_1[0x60] = piVar4[6];
  param_1[0x61] = piVar4[7];
  param_1[0x62] = piVar4[8];
  param_1[99] = piVar4[9];
  param_1[100] = piVar4[10];
  piVar4 = *(int **)(param_1[4] + 8);
  param_1[0x65] = *piVar4;
  *(short *)(param_1 + 0x66) = (short)piVar4[1];
  *(undefined2 *)((int)param_1 + 0x19a) = *(undefined2 *)((int)piVar4 + 6);
  *(short *)(param_1 + 0x67) = (short)piVar4[2];
  *(undefined2 *)((int)param_1 + 0x19e) = *(undefined2 *)((int)piVar4 + 10);
  *(short *)(param_1 + 0x68) = (short)piVar4[3];
  *(undefined2 *)((int)param_1 + 0x1a2) = *(undefined2 *)((int)piVar4 + 0xe);
  param_1[0x69] = piVar4[4];
  param_1[0x6a] = piVar4[5];
  param_1[0x6b] = piVar4[6];
  param_1[0x6c] = piVar4[7];
  param_1[0x6d] = piVar4[8];
  param_1[0x6e] = piVar4[9];
  param_1[0x6f] = piVar4[10];
  param_1[0x71] = 0x3f800000;
  param_1[0x72] = 0x3f800000;
  param_1[0x73] = 0x3f800000;
  return param_1;
}
// near miss from lane fm11 (unreviewed)
