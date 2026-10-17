/* HSTMATCH module=hstp_trans_main.prx start=0x00063810 end=0x00063854 symbol=FUN_00063810 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: used an early negative return and typed both helper prototypes; exact match verified; names and types await human review. */
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

extern void FUN_00063908(undefined4, int);
extern void FUN_00077c58(int);

void FUN_00063810(undefined4 param_1,int param_2)
{
  if (param_2 < 0) return;
  FUN_00077c58(param_2);
  FUN_00063908(param_1,param_2);
}
