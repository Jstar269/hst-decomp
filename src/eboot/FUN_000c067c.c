/* HSTMATCH module=EBOOT.BIN start=0x000c067c end=0x000c06b0 symbol=FUN_000c067c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
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
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern uint FUN_000ff678();

void FUN_000c067c(int param_1,undefined4 param_2,undefined4 *param_3)
{
  undefined4 uVar1;
  
  uVar1 = FUN_000ff678(*(undefined4 *)(param_1 + 0x18),param_2,*param_3,0);
  *param_3 = uVar1;
  return;
}
