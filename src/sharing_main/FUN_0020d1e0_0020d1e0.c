/* HSTMATCH module=hstp_trans_main.prx start=0x0020d1e0 end=0x0020d294 symbol=FUN_0020d1e0 lang=c99 */
/* Clone of src/eboot/FUN_001fea10_001fea10.c (hstclone.py tag u4r4s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_002d10cc;
extern undefined DAT_002d10d0;
extern undefined DAT_002d10d4;
extern undefined1 * FUN_001991d4();

undefined * FUN_0020d1e0(undefined4 param_1,int param_2,int param_3)
{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  int row_ok;
  int col_ok;
  int row_offset;
  
  iVar1 = (int)(FUN_001991d4());
  if (*(int *)(iVar1 + 4) == 0) {
    puVar2 = &DAT_002d10d4;
  }
  else if ((param_2 < 0) || ((row_ok = param_2 < *(int *)(*(int *)(iVar1 + 8) + 8)) == 0)) {
    puVar2 = &DAT_002d10d0;
  }
  else if ((param_3 < 0) ||
          (piVar3 = (int *)(row_offset = param_2 * 0xc, row_offset + *(int *)(iVar1 + 0xc)),
           (col_ok = param_3 < piVar3[1]) == 0)) {
    puVar2 = &DAT_002d10cc;
  }
  else {
    puVar2 = *(undefined **)(*piVar3 + param_3 * 4);
  }
  return puVar2;
}
