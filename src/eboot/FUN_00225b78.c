/* HSTMATCH module=EBOOT.BIN start=0x00225b78 end=0x00225c34 symbol=FUN_00225b78 lang=c99 rodata=0x002c9a04 */
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

extern undefined DAT_0034179c;
extern char DAT_002f1280[];
extern char DAT_002f1290[];
extern char DAT_002f12a0[];
extern char DAT_002f12b0[];
extern char DAT_002f12c0[];
extern void FUN_001b28f0();

void FUN_00225b78(undefined4 param_1,undefined4 param_2)
{
  switch(param_2) {
  case 0:
  case 2:
  case 3:
  case 9:
    FUN_001b28f0((int)&DAT_0034179c,DAT_002f1280);
    break;
  case 1:
  case 4:
  case 5:
    FUN_001b28f0((int)&DAT_0034179c,DAT_002f1290);
    break;
  case 6:
  case 7:
    FUN_001b28f0((int)&DAT_0034179c,DAT_002f12a0);
    break;
  case 8:
    FUN_001b28f0((int)&DAT_0034179c,DAT_002f12b0);
    break;
  case 10:
    FUN_001b28f0((int)&DAT_0034179c,DAT_002f12c0);
  }
  return;
}
