/* HSTMATCH module=EBOOT.BIN start=0x001b3244 end=0x001b32e0 symbol=FUN_001b3244 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag not recorded in lane candidate inputs/generated/FUN_001b3244.c) corrected by hand: reused the range-check result as an int and reordered the loop counter declaration; exact match verified; names and types await human review. */
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

extern undefined DAT_002e598c;
extern int FUN_00062418();

void FUN_001b3244(int *param_1)
{
  int iVar2;
  int iVar3;
  int iVar5;
  int *piVar4;
  int *piVar6;
  int valid;
  
  iVar3 = *param_1;
  iVar5 = 0;
  piVar4 = (int *)(&DAT_002e598c);
  do {
    iVar2 = *piVar4;
    valid = iVar2 < 0x1da;
    if (valid) {
      valid = *(int *)(iVar3 + iVar2 * 4) != 0;
    }
    if (valid) {
      piVar6 = (int *)(iVar3 + iVar2 * 4);
      iVar2 = *piVar6;
      if (iVar2 != 0) {
        FUN_00062418(iVar2,1);
        *piVar6 = 0;
      }
    }
    iVar5 = iVar5 + 1;
    piVar4 = piVar4 + 1;
  } while (iVar5 < 0x1a);
  return;
}
