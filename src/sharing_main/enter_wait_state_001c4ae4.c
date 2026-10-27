/* HSTMATCH module=hstp_trans_main.prx start=0x001c4ae4 end=0x001c4c28 symbol=FUN_001c4ae4 lang=c99 */
/* Hand-written reconstruction (port of src/eboot/enter_wait_state_001b6e24.c, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
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

extern undefined4 DAT_003e1e84;
extern int DAT_003eaad8;
extern int FUN_000e3144(int param_1);
extern int FUN_001c0bb0(int *param_1,int param_2);
extern void FUN_001c2130(int *param_1,float param_2);
extern void FUN_001c2280(int *param_1,float param_2,float param_3);
extern void FUN_001c2384(int *param_1,float param_2);
extern void FUN_001c2670(int *param_1,float param_2);
extern void FUN_001c6408();
extern void FUN_001c64d4(int param_1,int param_2,int param_3);
extern void FUN_001c6834(int param_1,undefined4 param_2,int param_3);

void FUN_001c4ae4(int param_1)
{
  int iVar1;
  undefined4 uVar2;
  
  FUN_001c6408();
  iVar1 = FUN_000e3144((int)(DAT_003e1e84));
  if (iVar1 == 0) {
    if (*(uint *)(DAT_003e1e84 + 0xa4) < 2) {
      FUN_001c64d4((int)(param_1),(int)(0),(int)(0));
      FUN_001c2280(&DAT_003eaad8,0.0f,0.5f);
      uVar2 = FUN_001c0bb0(&DAT_003eaad8,(int)(2));
      *(undefined4 *)(param_1 + 0x54) = uVar2;
      *(int *)(param_1 + 0x84) = *(int *)(param_1 + 0x84) + 1;
    }
    else if (*(uint *)(DAT_003e1e84 + 0xa0) < 2) {
      FUN_001c64d4((int)(param_1),(int)(0),(int)(0));
      FUN_001c2280(&DAT_003eaad8,0.0f,0.5f);
      uVar2 = FUN_001c0bb0(&DAT_003eaad8,(int)(1));
      *(undefined4 *)(param_1 + 0x54) = uVar2;
      *(int *)(param_1 + 0x84) = *(int *)(param_1 + 0x84) + 1;
    }
  }
  else {
    *(undefined1 *)(param_1 + 0x78) = 1;
    FUN_001c2130(&DAT_003eaad8,0.5f);
    FUN_001c2384(&DAT_003eaad8,0.5f);
    FUN_001c2670(&DAT_003eaad8,0.5f);
    FUN_001c6834((int)(param_1),(undefined4)(0x9a),(int)(0x18));
  }
  return;
}
