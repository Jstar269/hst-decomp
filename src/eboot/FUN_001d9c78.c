/* HSTMATCH module=EBOOT.BIN start=0x001d9c78 end=0x001d9cc4 symbol=FUN_001d9c78 lang=c99 */
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

extern void FUN_001d0624();
extern void FUN_001d57f0();

void FUN_001d9c78(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x3c);
  *(undefined4 *)(iVar1 + 0xd4) = 3;
  *(undefined4 *)(iVar1 + 0x520) = 4;
  FUN_001d0624(iVar1 + 0x1110,8);
  FUN_001d57f0(iVar1,5,0);
  return;
}
