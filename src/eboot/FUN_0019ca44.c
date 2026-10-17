/* HSTMATCH module=EBOOT.BIN start=0x0019ca44 end=0x0019ca84 symbol=FUN_0019ca44 lang=c99 */
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
typedef float undefined4;

extern float FUN_0000c000(float param_1);

void FUN_0019ca44(undefined4 param_1,int param_2)
{
  undefined4 uVar1;
  
  *(undefined4 *)(param_2 + 0x200) = param_1;
  uVar1 = FUN_0000c000(*(float *)(param_2 + 0x200) * 0.008726646f);
  *(undefined4 *)(param_2 + 0x214) = uVar1;
  return;
}
