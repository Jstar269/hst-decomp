/* HSTMATCH module=hstp_trans_main.prx start=0x00057ad8 end=0x00057b2c symbol=FUN_00057ad8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: typed the helper result as unsigned char and reordered the callback arms; exact match verified; names and types await human review. */
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

extern bool FUN_00055c68();
extern void FUN_00057b58();
extern void FUN_00057bdc();

unsigned char FUN_00057ad8(undefined4 param_1)
{
  unsigned char cVar1;
  
  cVar1 = FUN_00055c68();
  if (cVar1 != 0) {
    FUN_00057b58(param_1);
  } else {
    FUN_00057bdc(param_1);
  }
  return cVar1;
}
