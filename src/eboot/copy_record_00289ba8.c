/* HSTMATCH module=EBOOT.BIN start=0x00289ba8 end=0x00289c3c symbol=FUN_00289ba8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: typed the copied record fields as floats; exact match verified; names and types await human review. */
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


int FUN_00289ba8(int *param_1,float *param_2)
{
  int iVar1;
  float *puVar2;
  
  puVar2 = (float *)*param_1;
  iVar1 = (int)puVar2 - *(int *)(param_1[1] + 8);
  if (iVar1 / 16 < *(int *)(param_1[1] + 4)) {
    *puVar2 = *param_2;
    puVar2[1] = param_2[1];
    puVar2[2] = param_2[2];
    puVar2[3] = param_2[3];
  }
  else {
    if (puVar2 != (float *)0x0) {
      *puVar2 = *param_2;
      puVar2[1] = param_2[1];
      puVar2[2] = param_2[2];
      puVar2[3] = param_2[3];
    }
    iVar1 = param_1[1];
    *(int *)(iVar1 + 4) = *(int *)(iVar1 + 4) + 1;
  }
  return *param_1;
}
