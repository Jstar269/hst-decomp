/* HSTMATCH module=EBOOT.BIN start=0x0020ebb0 end=0x0020edac symbol=FUN_0020ebb0 lang=c99 */
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

extern float DAT_002efa74;
extern uint FUN_0001342c();
extern int FUN_0020edac();
extern int FUN_00215a20();
extern int FUN_00215a58();

void FUN_0020ebb0(int param_1,int *param_2,int *param_3,int *param_4,int *param_5,int *param_6, undefined *param_7)
{
  int iVar1;
  uint uVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  int aiStack_400 [256];
  
  iVar3 = 0;
  iVar1 = FUN_00215a58(param_1);
  fVar4 = *(float *)(iVar1 + 0x98);
  iVar1 = FUN_00215a20(param_1);
  fVar4 = fVar4 + *(float *)(iVar1 + 0x98);
  fVar5 = DAT_002efa74;
  fVar5 = (fVar5 > fVar4) ? fVar5 : fVar4;
  uVar2 = FUN_0001342c();
  if ((float)(int)(uVar2 & 0xfffff800) * 4.656613e-10f < fVar5 * 0.01f) {
    iVar3 = FUN_0020edac(param_1,(int)aiStack_400,1,param_4,param_5,param_6,param_7);
  }
  if (iVar3 == 0) {
    iVar3 = FUN_0020edac(param_1,(int)aiStack_400,0,param_4,param_5,param_6,param_7);
  }
  uVar2 = FUN_0001342c();
  *param_2 = (int)*(short *)aiStack_400
                            [(int)((float)iVar3 * (float)(int)(uVar2 & 0xfffff800) * 4.656613e-10f)];
  iVar1 = (int)*(short *)(aiStack_400
                          [(int)((float)iVar3 * (float)(int)(uVar2 & 0xfffff800) * 4.656613e-10f)] +
                         10);
  *param_3 = iVar1;
  if (iVar1 == 0) {
    uVar2 = FUN_0001342c();
    *param_3 = (int)((float)(int)(uVar2 & 0xfffff800) * 2.3283064e-09f + 1.0f);
  }
  return;
}
// near miss from lane km4 (unreviewed)
