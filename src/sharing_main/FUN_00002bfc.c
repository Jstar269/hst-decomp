/* HSTMATCH module=hstp_trans_main.prx start=0x00002bfc end=0x00002c34 symbol=FUN_00002bfc lang=c99 */
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

extern undefined4 FUN_00002c34();

undefined4 FUN_00002bfc(undefined4 param_1)
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)FUN_00002c34();
  uVar2 = *puVar1;
  puVar1 = (undefined4 *)FUN_00002c34(param_1);
  *puVar1 = 0;
  return uVar2;
}
