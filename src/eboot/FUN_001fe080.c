/* HSTMATCH module=EBOOT.BIN start=0x001fe080 end=0x001fe0dc symbol=FUN_001fe080 lang=c99 */
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

extern undefined4 DAT_002cfc8c;
extern bool FUN_0001ea64();

undefined1 FUN_001fe080(undefined4 param_1,undefined4 param_2,uint param_3)
{
  undefined1 uVar1;
  
  uVar1 = FUN_0001ea64(DAT_002cfc8c,param_1,param_2,2,9);
  if ((*(uint *)(DAT_002cfc8c + 0x80) & param_3) != 0) {
    uVar1 = 0;
  }
  return uVar1;
}
