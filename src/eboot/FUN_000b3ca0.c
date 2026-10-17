/* HSTMATCH module=EBOOT.BIN start=0x000b3ca0 end=0x000b3ce0 symbol=FUN_000b3ca0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. */
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

extern void FUN_000007f4();
extern void FUN_000887d4();
extern void FUN_000b3ce0();

int FUN_000b3ca0(int param_1)
{
  FUN_000007f4(param_1,FUN_000b3ce0,FUN_000887d4,0xc,2);
  return param_1;
}
