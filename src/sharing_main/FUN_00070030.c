/* HSTMATCH module=hstp_trans_main.prx start=0x00070030 end=0x000700a0 symbol=FUN_00070030 lang=c99 */
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

extern void FUN_00051e30();
extern void FUN_000522c0();
extern void FUN_0005b540();

void FUN_00070030(undefined4 *param_1,undefined4 param_2)
{
  if (param_1[1] != 0) {
    FUN_00051e30(*param_1,0,0,0x1e0,0x110,0,0);
    FUN_0005b540(param_1[1],*param_1,param_2,0);
    FUN_000522c0(*param_1);
  }
  return;
}
