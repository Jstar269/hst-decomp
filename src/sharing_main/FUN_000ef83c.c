/* HSTMATCH module=hstp_trans_main.prx start=0x000ef83c end=0x000ef9c8 symbol=FUN_000ef83c lang=c99 */
/* Clone of src/eboot/FUN_000ea62c.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
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
typedef float undefined4;


void FUN_000ef83c(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4, undefined4 *param_5,undefined4 *param_6,undefined4 *param_7,undefined4 *param_8)
{
  int iVar1;
  
  iVar1 = param_1 + *(int *)(param_1 + 0x11d0) * 0x70;
  *(undefined4 *)(iVar1 + 0x50) = *param_2;
  *(undefined4 *)(iVar1 + 0x54) = param_2[1];
  *(undefined4 *)(iVar1 + 0x58) = param_2[2];
  *(undefined4 *)(iVar1 + 0x5c) = param_2[3];
  iVar1 = param_1 + *(int *)(param_1 + 0x11d0) * 0x70;
  *(undefined4 *)(iVar1 + 0x60) = *param_3;
  *(undefined4 *)(iVar1 + 100) = param_3[1];
  *(undefined4 *)(iVar1 + 0x68) = param_3[2];
  *(undefined4 *)(iVar1 + 0x6c) = param_3[3];
  iVar1 = param_1 + *(int *)(param_1 + 0x11d0) * 0x70;
  *(undefined4 *)(iVar1 + 0x70) = *param_4;
  *(undefined4 *)(iVar1 + 0x74) = param_4[1];
  *(undefined4 *)(iVar1 + 0x78) = param_4[2];
  *(undefined4 *)(iVar1 + 0x7c) = param_4[3];
  iVar1 = param_1 + *(int *)(param_1 + 0x11d0) * 0x70;
  *(undefined4 *)(iVar1 + 0x80) = *param_5;
  *(undefined4 *)(iVar1 + 0x84) = param_5[1];
  *(undefined4 *)(iVar1 + 0x88) = param_5[2];
  *(undefined4 *)(iVar1 + 0x8c) = param_5[3];
  iVar1 = param_1 + *(int *)(param_1 + 0x11d0) * 0x70;
  *(undefined4 *)(iVar1 + 0x90) = *param_6;
  *(undefined4 *)(iVar1 + 0x94) = param_6[1];
  *(undefined4 *)(iVar1 + 0x98) = param_6[2];
  *(undefined4 *)(iVar1 + 0x9c) = param_6[3];
  iVar1 = param_1 + *(int *)(param_1 + 0x11d0) * 0x70;
  *(undefined4 *)(iVar1 + 0xa0) = *param_7;
  *(undefined4 *)(iVar1 + 0xa4) = param_7[1];
  *(undefined4 *)(iVar1 + 0xa8) = param_7[2];
  *(undefined4 *)(iVar1 + 0xac) = param_7[3];
  iVar1 = param_1 + *(int *)(param_1 + 0x11d0) * 0x70;
  *(undefined4 *)(iVar1 + 0xb0) = *param_8;
  *(undefined4 *)(iVar1 + 0xb4) = param_8[1];
  *(undefined4 *)(iVar1 + 0xb8) = param_8[2];
  *(undefined4 *)(iVar1 + 0xbc) = param_8[3];
  iVar1 = *(int *)(param_1 + 0x11d0) + 1;
  *(int *)(param_1 + 0x11d0) = iVar1;
  *(int *)(param_1 + 0x11d0) = iVar1 % 0x28;
  return;
}
