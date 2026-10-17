/* HSTMATCH module=EBOOT.BIN start=0x001240fc end=0x00124238 symbol=FUN_001240fc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v1) corrected by hand: float globals, byte flag, and mode branch; exact match verified; names and types await human review. */
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

extern undefined4 DAT_002da1ac;
extern float DAT_002da1cc;
extern float DAT_002da1d0;
extern float DAT_002da1d4;
extern float DAT_002da1d8;
extern unsigned char DAT_003386b8;
extern undefined * DAT_00338ac4;
extern undefined * DAT_00340284;
extern void FUN_0001f1fc();
extern int FUN_001252fc();
extern void FUN_001258bc();
extern undefined1 * FUN_00132124();
extern void FUN_00216208();

void FUN_001240fc(int param_1,int param_2,int param_3)
{
  int iVar1;
  float fVar2;
  float local_10 [4];
  int local_14;
  
  *(undefined4 *)(param_1 + 0x60) = 0;
  *(undefined4 *)(param_1 + 100) = 0;
  FUN_00216208(*(undefined4 **)(param_1 + 0x54));
  iVar1 = 0;
  local_10[0] = DAT_002da1cc;
  local_10[1] = DAT_002da1d0;
  local_10[2] = DAT_002da1d4;
  local_10[3] = DAT_002da1d8;
  if (DAT_003386b8 != 0) {
    if (DAT_00338ac4 != 0) {
      iVar1 = *(int *)(DAT_00338ac4 + 0x198);
    }
  }
  *(int *)(DAT_00340284 + 0x128) = iVar1;
  fVar2 = local_10[iVar1];
  iVar1 = 400;
  *(int *)(DAT_00340284 + 300) = (int)fVar2;
  if (param_2 != 0) {
    iVar1 = 500;
  }
  else if (param_3 != 0) {
    iVar1 = 600;
  }
  FUN_00132124(iVar1,&local_14);
  iVar1 = FUN_001252fc(param_1,local_14);
  *(undefined4 *)(param_1 + 0x58) = 0xffffffff;
  FUN_001258bc(param_1,iVar1);
  DAT_002da1ac = iVar1;
  *(undefined4 *)(param_1 + 0x90) = 1;
  *(undefined4 *)(param_1 + 100) = 0x3f800000;
  FUN_0001f1fc(param_1,1);
  *(undefined1 *)(param_1 + 0x78) = 1;
  return;
}
