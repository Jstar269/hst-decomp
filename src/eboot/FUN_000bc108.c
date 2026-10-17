/* HSTMATCH module=EBOOT.BIN start=0x000bc108 end=0x000bc13c symbol=FUN_000bc108 lang=c99 */
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

extern undefined4 DAT_00338ac4;
extern void FUN_000bc434();

void FUN_000bc108(undefined4 param_1,undefined4 param_2)
{
  if (DAT_00338ac4 != 0) {
    FUN_000bc434(DAT_00338ac4,param_1,param_2);
  }
  return;
}
