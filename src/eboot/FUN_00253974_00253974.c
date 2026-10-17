/* HSTMATCH module=EBOOT.BIN start=0x00253974 end=0x00253a68 symbol=FUN_00253974 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0c) corrected by hand: reused the loaded count as the range predicate and materialized the row offset before base addition; exact match verified; names and types await human review. */
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

extern undefined DAT_002c0e18;
extern undefined DAT_002c0e1c;
extern undefined DAT_002c0e20;
extern undefined DAT_002ca6c4;
extern undefined DAT_002ca6c0;
extern undefined1 * FUN_0018c9f4();

undefined * FUN_00253974(int param_1,int param_2)
{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  switch (param_1) {
    case 5:
    case 6:
      param_2 = param_2 + 1;
      break;
  }
  iVar4 = *(int *)(&DAT_002ca6c4 + param_1 * 8);
  iVar1 = (int)(FUN_0018c9f4(*(undefined4 *)(param_1 * 8 + (int)&DAT_002ca6c0)));
  if (*(int *)(iVar1 + 4) == 0) {
    puVar2 = &DAT_002c0e20;
  }
  else if ((iVar4 < 0) || (iVar6 = *(int *)(*(int *)(iVar1 + 8) + 8), (iVar6 = iVar4 < iVar6) == 0)) {
    puVar2 = &DAT_002c0e1c;
  }
  else if ((param_2 < 0) ||
          (iVar5 = iVar4 * 0xc, piVar3 = (int *)(iVar5 + *(int *)(iVar1 + 0xc)), iVar6 = piVar3[1], iVar6 = param_2 < iVar6, iVar6 == 0)) {
    puVar2 = &DAT_002c0e18;
  }
  else {
    puVar2 = *(undefined **)(*piVar3 + param_2 * 4);
  }
  return puVar2;
}




