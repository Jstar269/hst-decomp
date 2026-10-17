/* HSTMATCH module=hstp_trans_main.prx start=0x002661e4 end=0x00266224 symbol=FUN_002661e4 lang=c99 */
/* Clone of src/eboot/FUN_00255d34.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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


void FUN_002661e4(int param_1,int param_2,int param_3,int param_4)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + param_2 * 0xa4 + param_3 * 4);
  if (iVar1 != 0) {
    *(int *)(iVar1 + 0x24) = *(int *)(iVar1 + 0x28) + param_4;
  }
  return;
}
