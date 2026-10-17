/* HSTMATCH module=hstp_trans_main.prx start=0x00003778 end=0x000037f8 symbol=FUN_00003778 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: restored the dropped FUN_000030d0(param_1) argument and its int return; exact match verified; names and types await human review. */
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

extern undefined4 FUN_00003088();
extern int FUN_000030b0();
extern int FUN_000030d0(undefined4);
extern int FUN_00003148();
extern byte FUN_00003168();

void FUN_00003778(undefined4 param_1,undefined4 *param_2,uint *param_3)
{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint *puVar4;
  
  iVar1 = FUN_000030d0(param_1);
  if (iVar1 == 0) {
    uVar3 = FUN_000030b0(param_1);
    *param_2 = uVar3;
    uVar2 = FUN_00003168(param_1);
    *param_3 = uVar2 & 0xff;
  }
  else {
    uVar3 = FUN_00003088(param_1);
    *param_2 = uVar3;
    puVar4 = (uint *)FUN_00003148(param_1);
    *param_3 = *puVar4;
  }
  return;
}
