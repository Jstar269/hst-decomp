/* HSTMATCH module=hstp_trans_main.prx start=0x00051b88 end=0x00051c58 symbol=FUN_00051b88 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag sh2/v0) corrected by hand: restored the receiver argument; matching idiom: volatile reload of the just-stored +4 field before FUN_000507f0; exact match verified; names and types await human review. */
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

extern int FUN_0004fe78(void *,int,int,int,int,int);
extern int FUN_000507f0(void *,int,int);
extern int FUN_00050848(void *,int,int);
extern void FUN_00051c6c(undefined4);
extern undefined4 DAT_003ba4b0;

void FUN_00051b88(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, undefined4 param_5)
{
  undefined4 uVar1;
  
  FUN_00051c6c(param_1);
  uVar1 = FUN_0004fe78(&DAT_003ba4b0,param_2,param_3,0,param_4,param_5);
  *(undefined4 *)(param_1 + 4) = uVar1;
  {
    int value = *(volatile int *)(param_1 + 4);
    uVar1 = FUN_000507f0(&DAT_003ba4b0,value,0);
  }
  *(undefined4 *)(param_1 + 8) = uVar1;
  uVar1 = FUN_00050848(&DAT_003ba4b0,*(undefined4 *)(param_1 + 4),0);
  *(undefined4 *)(param_1 + 0xc) = uVar1;
  *(float *)(param_1 + 0x10) = 1.0f / (float)*(int *)(param_1 + 8);
  *(float *)(param_1 + 0x14) = 1.0f / (float)*(int *)(param_1 + 0xc);
  return;
}
