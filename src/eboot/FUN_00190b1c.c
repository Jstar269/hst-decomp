/* HSTMATCH module=EBOOT.BIN start=0x00190b1c end=0x00190ba0 symbol=FUN_00190b1c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p1), refined by hstperm.py random mutation (perm-p1/r00/f0307_00190b1c_m03.c); exact match verified; names and types await human review. */
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
extern uint * FUN_00190ba0();
extern void FUN_00191000();
extern void FUN_00191840();

int FUN_00190b1c(int param_1,short param_2)
{
  undefined1 auStack_18 [24];
  undefined1 auStack_30 [24];
  
  if (0 != param_1) {
    FUN_00191840(auStack_30,param_1,*(undefined4 *)(param_1 + 0x14));
    FUN_00191840(auStack_18,param_1,0);
    FUN_00191000(param_1,auStack_18,auStack_30);
    FUN_00190ba0(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
