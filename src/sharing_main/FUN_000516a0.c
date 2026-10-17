/* HSTMATCH module=hstp_trans_main.prx start=0x000516a0 end=0x000516e4 symbol=FUN_000516a0 lang=c99 */
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

extern undefined4 FUN_00004f78();
extern void FUN_00048fb8();
extern void FUN_00049020();
extern void FUN_000516e4();
extern void FUN_0005b024();

void FUN_000516a0(undefined4 param_1,int param_2)
{
  if (param_2 != 0) {
    FUN_000516e4();
  }
  FUN_00048fb8();
  FUN_00004f78(0,0);
  FUN_00049020();
  FUN_0005b024();
  return;
}
