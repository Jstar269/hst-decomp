/* HSTMATCH module=hstp_trans_main.prx start=0x0001f1cc end=0x0001f224 symbol=FUN_0001f1cc lang=c99 */
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

extern void FUN_0001f224();

void FUN_0001f1cc(undefined4 param_1,undefined4 param_2)
{
  int iVar1;
  
  iVar1 = 0;
  do {
    FUN_0001f224(param_1,param_2,iVar1);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 2);
  return;
}
