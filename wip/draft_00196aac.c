/* HSTMATCH module=EBOOT.BIN start=0x00196aac end=0x00196c6c symbol=FUN_00196aac lang=c99 */
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

extern void FUN_000ffb3c();

void FUN_00196aac(int param_1,int *param_2,int *param_3,int param_4,int param_5,int param_6)
{
  int iVar1;
  int iVar2;
  
  if (*param_2 < 6) {
    iVar2 = (*param_2 + 0xc) * 4;
    iVar1 = *(int *)(iVar2 + param_1 + 4);
    FUN_000ffb3c(iVar1,0);
    if (param_4 == 3) {
      param_4 = 2;
    }
    else if (param_4 == 2) {
      param_4 = 3;
    }
    param_4 = *(int *)(iVar2 + param_1 + 0x7c) + param_4;
    *(int *)(iVar1 + 0x24) = param_4;
    *(int *)(iVar1 + 0x28) = param_4;
    *(short *)(iVar1 + 4) = (short)*(undefined4 *)(param_6 + 4);
    *(short *)(iVar1 + 6) = (short)*(undefined4 *)(param_6 + 8) + -3;
    *(short *)(iVar1 + 8) = *(short *)(iVar1 + 4) + (short)(int)(*(float *)(param_6 + 0xc) * 20.0f);
    *(short *)(iVar1 + 10) = *(short *)(iVar1 + 6) + (short)(int)(*(float *)(param_6 + 0x10) * 20.0f)
    ;
    *param_2 = *param_2 + 1;
  }
  if (*param_3 < 0xc) {
    iVar2 = (*param_3 + 0x12) * 4;
    iVar1 = *(int *)(iVar2 + param_1 + 4);
    FUN_000ffb3c(iVar1,0);
    param_5 = *(int *)(iVar2 + param_1 + 0x7c) + param_5;
    *(int *)(iVar1 + 0x24) = param_5;
    *(int *)(iVar1 + 0x28) = param_5;
    *(short *)(iVar1 + 4) = (short)*(undefined4 *)(param_6 + 4);
    *(short *)(iVar1 + 6) = (short)*(undefined4 *)(param_6 + 8) + -3;
    *(short *)(iVar1 + 8) = *(short *)(iVar1 + 4) + (short)(int)(*(float *)(param_6 + 0xc) * 20.0f);
    *(short *)(iVar1 + 10) = *(short *)(iVar1 + 6) + (short)(int)(*(float *)(param_6 + 0x10) * 20.0f)
    ;
    *param_3 = *param_3 + 1;
  }
  return;
}
// near miss from lane fm9 (unreviewed)
