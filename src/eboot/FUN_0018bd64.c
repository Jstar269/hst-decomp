/* HSTMATCH module=EBOOT.BIN start=0x0018bd64 end=0x0018bd80 symbol=FUN_0018bd64 lang=c99 */
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

extern undefined4 DAT_00310ff8;
extern void FUN_0018b7a0();

void FUN_0018bd64(int param_1)
{
  *(undefined1 *)(param_1 + 0x44) = 1;
  DAT_00310ff8 = (unsigned int)(FUN_0018b7a0);
  return;
}
