/* HSTMATCH module=EBOOT.BIN start=0x00051274 end=0x00051344 symbol=FUN_00051274 lang=c99 */
/* Clone of src/sharing_main/FUN_00051b88_00051b88.c (hstclone.py tag u1r2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag sh2/v0) corrected by hand: restored the receiver argument; matching idiom: volatile reload of the just-stored +4 field before FUN_0004ff14; exact match verified; names and types await human review. */
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

extern int FUN_0004f5f0(void *,int,int,int,int,int);
extern int FUN_0004ff14(void *,int,int);
extern int FUN_0004ff6c(void *,int,int);
extern void FUN_00051358(undefined4);
extern undefined4 DAT_00311170;

void FUN_00051274(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, undefined4 param_5)
{
  undefined4 uVar1;
  
  FUN_00051358(param_1);
  uVar1 = FUN_0004f5f0(&DAT_00311170,param_2,param_3,0,param_4,param_5);
  *(undefined4 *)(param_1 + 4) = uVar1;
  {
    int value = *(volatile int *)(param_1 + 4);
    uVar1 = FUN_0004ff14(&DAT_00311170,value,0);
  }
  *(undefined4 *)(param_1 + 8) = uVar1;
  uVar1 = FUN_0004ff6c(&DAT_00311170,*(undefined4 *)(param_1 + 4),0);
  *(undefined4 *)(param_1 + 0xc) = uVar1;
  *(float *)(param_1 + 0x10) = 1.0f / (float)*(int *)(param_1 + 8);
  *(float *)(param_1 + 0x14) = 1.0f / (float)*(int *)(param_1 + 0xc);
  return;
}
