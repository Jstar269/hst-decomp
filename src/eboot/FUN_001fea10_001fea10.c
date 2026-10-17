/* HSTMATCH module=EBOOT.BIN start=0x001fea10 end=0x001feac4 symbol=FUN_001fea10 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: materialized both range predicates and formed the indexed row address through an offset-first comma expression; exact match verified; names and types await human review. */
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
extern undefined1 * FUN_0018c9f4();

undefined * FUN_001fea10(undefined4 param_1,int param_2,int param_3)
{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  int row_ok;
  int col_ok;
  int row_offset;
  
  iVar1 = (int)(FUN_0018c9f4());
  if (*(int *)(iVar1 + 4) == 0) {
    puVar2 = &DAT_002c0e20;
  }
  else if ((param_2 < 0) || ((row_ok = param_2 < *(int *)(*(int *)(iVar1 + 8) + 8)) == 0)) {
    puVar2 = &DAT_002c0e1c;
  }
  else if ((param_3 < 0) ||
          (piVar3 = (int *)(row_offset = param_2 * 0xc, row_offset + *(int *)(iVar1 + 0xc)),
           (col_ok = param_3 < piVar3[1]) == 0)) {
    puVar2 = &DAT_002c0e18;
  }
  else {
    puVar2 = *(undefined **)(*piVar3 + param_3 * 4);
  }
  return puVar2;
}
