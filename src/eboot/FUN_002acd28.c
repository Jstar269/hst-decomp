/* HSTMATCH module=EBOOT.BIN start=0x002acd28 end=0x002acd60 symbol=FUN_002acd28 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a1), refined by hstperm.py tag p4 random mutation from try/gen-a1/v0/FUN_002acd28.c; exact match verified; names and types await human review. */
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

extern undefined DAT_002cc2cc;

bool FUN_002acd28(int param_1)
{
  bool bVar1;
  
  if (param_1 >= 0 && (param_1 < 0x28)) {
    bVar1 = (&DAT_002cc2cc)[param_1] != '\0';
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}
