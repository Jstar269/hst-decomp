/* HSTMATCH module=EBOOT.BIN start=0x002af0a4 end=0x002af0b4 symbol=FUN_002af0a4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p64a); exact match verified; names and types await human review. */
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

extern undefined4 DAT_003415a8;
extern undefined8 FUN_001bc630(float param_1);

undefined8 FUN_002af0a4(void)
{
  undefined8 uVar1;
  
  uVar1 = FUN_001bc630(*(float *)(DAT_003415a8 + 0x1414));
  return uVar1;
}
