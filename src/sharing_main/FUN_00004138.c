/* HSTMATCH module=hstp_trans_main.prx start=0x00004138 end=0x000041d0 symbol=FUN_00004138 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: typed FUN_000030d0 as returning int; exact match verified; names and types await human review. */
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
extern int FUN_000030d0();
extern int FUN_000031b0();
extern void FUN_00003900();
extern int FUN_00003994();
extern uint FUN_00003c50();

int FUN_00004138(int param_1,short param_2)
{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  if (param_1 != 0) {
    iVar1 = FUN_000030d0();
    if (iVar1 != 0) {
      uVar2 = FUN_00003994(param_1);
      puVar3 = (undefined4 *)FUN_000031b0(param_1);
      uVar4 = FUN_00003c50(param_1);
      FUN_00003900(uVar2,*puVar3,uVar4);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
