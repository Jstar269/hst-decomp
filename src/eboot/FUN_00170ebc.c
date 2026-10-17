/* HSTMATCH module=EBOOT.BIN start=0x00170ebc end=0x00170f08 symbol=FUN_00170ebc lang=c99 */
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

extern int DAT_003415ac;

void FUN_00170ebc(void)
{
  int iVar1;
  
  iVar1 = DAT_003415ac;
  if (DAT_003415ac != 0) {
    *(undefined4 *)(DAT_003415ac + 0x74) = 0x3f800000;
    *(undefined4 *)(iVar1 + 0x78) = 0x3f800000;
    iVar1 = DAT_003415ac;
    *(undefined4 *)(**(int **)(DAT_003415ac + 4) + 0x60) = 0x43700000;
    *(undefined4 *)(**(int **)(iVar1 + 4) + 100) = 0x43080000;
  }
  return;
}
