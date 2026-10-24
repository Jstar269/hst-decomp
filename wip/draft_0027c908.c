/* HSTMATCH module=EBOOT.BIN start=0x0027c908 end=0x0027caa0 symbol=FUN_0027c908 lang=c99 */
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

extern undefined4 DAT_0034a7e0;
extern undefined * DAT_0034a7e4;
extern void FUN_0027c328(int param_1,int param_2,float *param_3);
extern int FUN_0027c774();
extern undefined4 FUN_0027dc84();
extern int FUN_0027dc90();

void FUN_0027c908(int param_1,int param_2)
{
  int iVar1;
  int iVar2;
  float *pfVar3;
  float *pfVar4;
  int local_4;
  
  if (param_2 != *(int *)(param_1 + 0x54)) {
    *(int *)(param_1 + 0x54) = param_2;
    *(undefined4 *)(param_1 + 0x58) = 0;
    if (*(int *)(param_1 + 0x78) < 0) {
      iVar1 = *(int *)(*(int *)(param_1 + 0x54) * 0x40 + DAT_0034a7e4 + 0x24);
    }
    else {
      iVar1 = *(int *)(param_1 + 0x7c);
    }
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x6c) = 0xbf800000;
      *(undefined4 *)(param_1 + 0x70) = 0;
      pfVar3 = (float *)(DAT_0034a7e4 + *(int *)(param_1 + 0x54) * 0x40);
      *(float **)(param_1 + 0x48) = pfVar3;
      FUN_0027c328(param_1,0,pfVar3);
    }
    else {
      iVar1 = FUN_0027dc84(DAT_0034a7e0);
      iVar2 = *(int *)(param_1 + 0x78);
      iVar1 = (int)((*(float *)(*(int *)(param_1 + 0x54) * 0x40 + DAT_0034a7e4 + 0x2c) +
                    (float)iVar1) - (float)*(int *)(param_1 + 0x74));
      if (iVar2 < 0) {
        iVar2 = *(int *)(*(int *)(param_1 + 0x54) * 0x40 + DAT_0034a7e4 + 0x34);
      }
      FUN_0027dc90(iVar2,&local_4);
      iVar2 = FUN_0027c774(param_1,local_4);
      if (iVar1 < 1) {
        FUN_0027c908(param_1,iVar2);
      }
      else {
        pfVar4 = (float *)(DAT_0034a7e4 + iVar2 * 0x40);
        pfVar3 = (float *)(DAT_0034a7e4 + *(int *)(param_1 + 0x54) * 0x40);
        *(undefined4 *)(param_1 + 0x48) = 0;
        FUN_0027c328(param_1,1,pfVar3);
        FUN_0027c328(param_1,2,pfVar4);
        *(undefined4 *)(param_1 + 0x6c) = 0;
        *(float *)(param_1 + 0x70) = (float)iVar1;
      }
    }
  }
  return;
}
// near miss from lane fm9 (unreviewed)
