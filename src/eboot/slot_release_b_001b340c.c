/* HSTMATCH module=EBOOT.BIN start=0x001b340c end=0x001b34b4 symbol=FUN_001b340c lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py draft inputs/generated/FUN_001b340c.c) corrected by hand: single load of the 0x7a8 field, `idx >= 0` instead of `-1 < idx`, and the bounds test assigned to the bool before the short-circuit load; exact match verified; names and types await human review. */
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

extern int FUN_00062418();
extern void FUN_001b0ef8();

void FUN_001b340c(int *param_1,int param_2)
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  iVar3 = *param_1;
  if (*(int *)(iVar3 + 0x7a8) >= 0) {
    iVar2 = *(int *)(iVar3 + 0x7a8) + 0xb4;
    bVar1 = iVar2 < 0x1da;
    if (bVar1) {
      bVar1 = *(int *)(iVar3 + iVar2 * 4) != 0;
    }
    if (bVar1) {
      piVar4 = (int *)(iVar3 + iVar2 * 4);
      iVar2 = *piVar4;
      if (iVar2 != 0) {
        FUN_00062418(iVar2,1);
        *piVar4 = 0;
      }
    }
    *(undefined4 *)(iVar3 + 0x7a8) = 0xffffffff;
  }
  *(int *)(iVar3 + 0x7a8) = param_2;
  FUN_001b0ef8(iVar3,param_2 + 0xb4,0,0,0);
  return;
}
