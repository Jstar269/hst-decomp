/* HSTMATCH module=hstp_trans_main.prx start=0x0017c0b0 end=0x0017c15c symbol=FUN_0017c0b0 lang=c99 */
/* Clone of src/eboot/scan_entries_0016fe64.c (hstclone.py tag km3): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: hold the call context and table base in locals before indexed access. */
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

extern void *DAT_003e1e48;
extern int FUN_000dca74(void *, int, int);

#pragma opt_strength_reduction off

undefined4 FUN_0017c0b0(int param_1)
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  
  uVar3 = 0;
  if (*(int *)(param_1 + 0x1e8) != 0) {
LOOP_BODY:
      void *context = DAT_003e1e48;
      int **entries = *(int ***)(param_1 + 0x1e4);
      piVar4 = entries[uVar3];
      iVar1 = FUN_000dca74(context,1,*piVar4);
      if (iVar1 != 0) {
        if (*(signed char *)(iVar1 + 0x60) >= 0) {
          if (*(unsigned char *)(param_1 + *piVar4 + 0x63b) == 4) {
            return 1;
          }
        }
      }
      uVar2 = *(uint *)(param_1 + 0x1e8);
      uVar3 = uVar3 + 1;
    if (uVar3 < uVar2) goto LOOP_BODY;
  }
  return 0;
}
