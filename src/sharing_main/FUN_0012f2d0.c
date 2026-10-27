/* HSTMATCH module=hstp_trans_main.prx start=0x0012f2d0 end=0x0012f40c symbol=FUN_0012f2d0 lang=c99 */
/* Hand-written reconstruction (port of src/eboot/FUN_001240fc_001240fc.c, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
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
typedef signed char undefined1;
typedef short undefined2;
typedef int undefined4;

extern undefined4 DAT_0038118c;
extern float DAT_003811ac;
extern float DAT_003811b0;
extern float DAT_003811b4;
extern float DAT_003811b8;
extern unsigned char DAT_003e19f8;
extern undefined * DAT_003e1e04;
extern undefined * DAT_003e95c4;
extern void FUN_0001ef14();
extern int FUN_001304d0();
extern void FUN_00130af0();
extern undefined1 * FUN_0013d6dc();
extern void FUN_0022520c();

void FUN_0012f2d0(int param_1,int param_2,int param_3)
{
  int iVar1;
  float fVar2;
  float local_10 [4];
  int local_14;
  
  *(undefined4 *)(param_1 + 0x60) = 0;
  *(undefined4 *)(param_1 + 100) = 0;
  FUN_0022520c(*(undefined4 **)(param_1 + 0x54));
  iVar1 = 0;
  local_10[0] = DAT_003811ac;
  local_10[1] = DAT_003811b0;
  local_10[2] = DAT_003811b4;
  local_10[3] = DAT_003811b8;
  if (DAT_003e19f8 != 0) {
    if (DAT_003e1e04 != 0) {
      iVar1 = *(int *)(DAT_003e1e04 + 0x198);
    }
  }
  *(int *)(DAT_003e95c4 + 0x128) = iVar1;
  fVar2 = local_10[iVar1];
  iVar1 = 400;
  *(int *)(DAT_003e95c4 + 300) = (int)fVar2;
  if (param_2 != 0) {
    iVar1 = 500;
  }
  else if (param_3 != 0) {
    iVar1 = 600;
  }
  FUN_0013d6dc(iVar1,&local_14);
  iVar1 = FUN_001304d0(param_1,local_14);
  *(undefined4 *)(param_1 + 0x58) = 0xffffffff;
  FUN_00130af0(param_1,iVar1);
  DAT_0038118c = iVar1;
  *(undefined4 *)(param_1 + 0x90) = 1;
  *(undefined4 *)(param_1 + 100) = 0x3f800000;
  FUN_0001ef14(param_1,1);
  *(undefined1 *)(param_1 + 0x78) = 1;
  return;
}
