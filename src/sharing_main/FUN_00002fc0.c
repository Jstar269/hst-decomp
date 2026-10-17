/* HSTMATCH module=hstp_trans_main.prx start=0x00002fc0 end=0x00002fe8 symbol=FUN_00002fc0 lang=c99 */
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

extern int FUN_00002fe8();

void FUN_00002fc0(void)
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_00002fe8();
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  return;
}
