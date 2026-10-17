/* HSTMATCH module=EBOOT.BIN start=0x00117d38 end=0x00117d70 symbol=FUN_00117d38 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
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
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern undefined4 DAT_003386b0;
extern void FUN_0001f558();
extern void FUN_0008ac88();

void FUN_00117d38(void)
{
  FUN_0008ac88(DAT_003386b0);
  FUN_0001f558(DAT_003386b0,0x16,0,0);
  return;
}
