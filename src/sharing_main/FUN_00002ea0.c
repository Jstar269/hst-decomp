/* HSTMATCH module=hstp_trans_main.prx start=0x00002ea0 end=0x00002ee0 symbol=FUN_00002ea0 lang=c99 */
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

extern void FUN_00002e7c();
extern undefined4 FUN_00002ee0();
extern undefined4 FUN_00002ee8();

void FUN_00002ea0(int param_1)
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = FUN_00002ee8(param_1 + 0xc);
  puVar2 = (undefined4 *)FUN_00002ee0(param_1 + 0xc);
  FUN_00002e7c(uVar1,*puVar2);
  return;
}
