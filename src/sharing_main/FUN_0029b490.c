/* HSTMATCH module=hstp_trans_main.prx start=0x0029b490 end=0x0029b4fc symbol=FUN_0029b490 lang=c99 */
/* Clone of src/eboot/FUN_00289cf4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_00000a00();
extern void FUN_0029b620();
extern int * FUN_0029e154();

int FUN_0029b490(int param_1,short param_2)
{
  if (param_1 != 0) {
    FUN_0029b620();
    if ((param_1 != 0) && (param_1 != 0)) {
      FUN_0029e154(param_1,0);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
