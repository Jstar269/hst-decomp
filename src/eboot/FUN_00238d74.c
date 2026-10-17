/* HSTMATCH module=EBOOT.BIN start=0x00238d74 end=0x00238db0 symbol=FUN_00238d74 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
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

extern int FUN_00000bcc();
extern undefined4 * FUN_00238db0();

void FUN_00238d74(undefined4 param_1)
{
  int iVar1;
  
  iVar1 = FUN_00000bcc(0x1938);
  if (iVar1 != 0) {
    FUN_00238db0(iVar1,param_1);
  }
  return;
}
