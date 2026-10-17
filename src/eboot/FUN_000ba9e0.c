/* HSTMATCH module=EBOOT.BIN start=0x000ba9e0 end=0x000baa34 symbol=FUN_000ba9e0 lang=c99 */
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

extern undefined DAT_002d4a98;
extern undefined DAT_002d4aa8;

void FUN_000ba9e0(undefined4 param_1,undefined4 *param_2)
{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0x5a4;
    param_2[1] = 0x5a4;
    param_2[2] = 1;
    param_2[3] = 0x10;
    param_2[4] = 0x20000;
    param_2[5] = 0x8000;
    param_2[6] = (unsigned int)(&DAT_002d4a98);
    param_2[7] = (unsigned int)(&DAT_002d4aa8);
  }
  return;
}
