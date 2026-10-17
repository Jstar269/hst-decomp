/* HSTMATCH module=hstp_trans_main.prx start=0x0006ceb0 end=0x0006cf54 symbol=FUN_0006ceb0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
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

extern undefined1 DAT_003772d0;
extern undefined1 DAT_003772d1;
extern undefined4 * FUN_0006d5d0();
extern undefined4 * FUN_0006dd2c();

void FUN_0006ceb0(int *param_1,undefined4 param_2,int *param_3)
{
  undefined4 uVar1;
  int iVar2;
  undefined1 local_1;
  undefined1 local_2;
  int local_8;
  
  uVar1 = (unsigned int)(FUN_0006d5d0(param_2,param_3,&local_8,&local_1,&local_2));
  if ((local_8 == 0) || (*(int *)(local_8 + 0xc) < *param_3)) {
    iVar2 = (int)(FUN_0006dd2c(param_2,uVar1,local_1,local_2,param_3));
    *param_1 = iVar2;
    *(undefined1 *)(param_1 + 1) = DAT_003772d0;
  }
  else {
    *param_1 = local_8;
    *(undefined1 *)(param_1 + 1) = DAT_003772d1;
  }
  return;
}
