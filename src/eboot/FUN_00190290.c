/* HSTMATCH module=EBOOT.BIN start=0x00190290 end=0x001902d0 symbol=FUN_00190290 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
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

extern undefined4 FUN_00003e04();
extern uint * FUN_00190880();

int FUN_00190290(int param_1,int param_2)
{
  FUN_00003e04();
  FUN_00190880(param_1 + 0xc,param_2 + 0xc);
  return param_1;
}
