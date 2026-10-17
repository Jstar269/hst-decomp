/* HSTMATCH module=EBOOT.BIN start=0x0015e704 end=0x0015e764 symbol=FUN_0015e704 lang=c99 */
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
extern void FUN_0001ebd4();
extern void FUN_0001efac();
extern bool FUN_0001efc0();
extern void FUN_0015e764();

void FUN_0015e704(undefined4 param_1)
{
  uchar cVar1;
  
  cVar1 = FUN_0001efc0();
  if (cVar1 != '\0') {
    FUN_0001efac();
  }
  FUN_0015e764(param_1,DAT_002cfc8c);
  if (cVar1 != '\0') {
    FUN_0001ebd4();
  }
  return;
}
