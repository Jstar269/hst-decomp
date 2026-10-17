/* HSTMATCH module=hstp_trans_main.prx start=0x001bfb44 end=0x001bfbd8 symbol=FUN_001bfb44 lang=c99 */
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

extern void FUN_00000a00(void *object);
extern int FUN_00063304(void *object, int mode);
extern void FUN_001bd2a8(void *object);

int * FUN_001bfb44(int *param_1,short param_2)
{
  int iVar1;
  
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
    if (iVar1 == 0) {
      *param_1 = 0;
    }
    else {
        FUN_001bd2a8((void *)iVar1);
        if (*(int *)(iVar1 + 0x160) != 0) {
          FUN_00063304((void *)*(int *)(iVar1 + 0x160),1);
          *(undefined4 *)(iVar1 + 0x160) = 0;
        }
        FUN_00000a00((void *)iVar1);
        *param_1 = 0;
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
// Near miss: 4 words differ at the nested null-resource control flow; retail has two beqzl checks and stores zero in the second delay slot, while this source uses a bnezl cleanup arm and an unconditional branch.
// A shared-store form and a goto form were tried; the shared-store form moved the branch layout substantially and the goto form removed the duplicate test without matching the retail branch polarity.
// near miss from lane u5cr2-2 (unreviewed)
