/* HSTMATCH module=hstp_trans_main.prx start=0x001c1338 end=0x001c1394 symbol=FUN_001c1338 lang=c99 */
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

extern void FUN_001bdec0();
extern void FUN_001bdfd8();

void FUN_001c1338(undefined4 *param_1)
{
  undefined4 uVar1;
  
  uVar1 = *param_1;
  FUN_001bdfd8(uVar1,0);
  FUN_001bdec0(uVar1,3);
  FUN_001bdec0(uVar1,2);
  FUN_001bdec0(uVar1,1);
  FUN_001bdec0(uVar1,0);
  return;
}
