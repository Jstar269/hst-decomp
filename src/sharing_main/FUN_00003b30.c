/* HSTMATCH module=hstp_trans_main.prx start=0x00003b30 end=0x00003b5c symbol=FUN_00003b30 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
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

extern int FUN_00003064();
extern int FUN_00003b5c();

int FUN_00003b30(void)
{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = FUN_00003064();
  uVar2 = FUN_00003b5c(uVar1);
  return (uVar2 >> 1) - 1;
}
