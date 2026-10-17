/* HSTMATCH module=hstp_trans_main.prx start=0x00100c0c end=0x00100c40 symbol=FUN_00100c0c lang=c99 */
/* Clone of src/eboot/FUN_000fb4d0.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_000fc08c(int param_1,int param_2,float *param_3);

void FUN_00100c0c(int param_1,int param_2,float *param_3)
{
  int iVar1;
  
  if ((*(int *)(param_1 + 0x3c) != 0) &&
     (iVar1 = *(int *)(*(int *)(param_1 + 0x3c) + 0x90), iVar1 != 0)) {
    FUN_000fc08c(iVar1,param_2,param_3);
  }
  return;
}
