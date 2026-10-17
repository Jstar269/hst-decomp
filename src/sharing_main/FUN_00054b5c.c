/* HSTMATCH module=hstp_trans_main.prx start=0x00054b5c end=0x00054ba4 symbol=FUN_00054b5c lang=c99 */
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

extern int FUN_0002e7f8();
extern void FUN_00054ba4();

void FUN_00054b5c(int param_1,undefined4 param_2)
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_0002e7f8(*(int *)(param_1 + 8) + 0x10);
  FUN_00054ba4(param_1,param_2,*puVar1);
  return;
}
