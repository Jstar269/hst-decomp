/* HSTMATCH module=EBOOT.BIN start=0x002798e8 end=0x002799a8 symbol=FUN_002798e8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s256a); exact match verified; names and types await human review. */
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
extern void FUN_0001dfe8();
extern void FUN_0001e23c();

void FUN_002798e8(int param_1)
{
  FUN_0001dfe8(DAT_002cfc8c,0x2000);
  FUN_0001e23c(DAT_002cfc8c,0x2000,1);
  FUN_0001dfe8(DAT_002cfc8c,0x4000);
  FUN_0001e23c(DAT_002cfc8c,0x4000,1);
  *(undefined1 *)(param_1 + 0x176) = 0;
  *(undefined1 *)(param_1 + 0x177) = 0;
  FUN_0001dfe8(DAT_002cfc8c,0x20);
  FUN_0001e23c(DAT_002cfc8c,0x20,1);
  FUN_0001dfe8(DAT_002cfc8c,0x80);
  FUN_0001e23c(DAT_002cfc8c,0x80,1);
  *(undefined1 *)(param_1 + 0x17a) = 0;
  *(undefined1 *)(param_1 + 0x17b) = 0;
  return;
}
