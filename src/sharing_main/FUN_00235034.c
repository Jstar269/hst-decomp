/* HSTMATCH module=hstp_trans_main.prx start=0x00235034 end=0x00235074 symbol=FUN_00235034 lang=c99 */
/* Clone of src/eboot/FUN_00225ac0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_000fc200();

void FUN_00235034(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x3c);
  FUN_000fc200(*(undefined4 *)(iVar1 + 0x30),0);
  iVar1 = *(int *)(iVar1 + 0x20);
  *(undefined4 *)(iVar1 + 0x78) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x7c) = 0;
  *(undefined4 *)(iVar1 + 0x80) = 0;
  return;
}
