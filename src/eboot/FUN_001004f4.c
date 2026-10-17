/* HSTMATCH module=EBOOT.BIN start=0x001004f4 end=0x00100538 symbol=FUN_001004f4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
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

extern void FUN_00051478();

void FUN_001004f4(undefined4 param_1,int param_2)
{
  if ((*(ushort *)(param_2 + 0xe) & 0x600) != 0) {
    FUN_00051478(param_1,0xd4000000);
    FUN_00051478(param_1,0xd50441e0);
  }
  return;
}
