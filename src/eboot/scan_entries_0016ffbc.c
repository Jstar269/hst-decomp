/* HSTMATCH module=EBOOT.BIN start=0x0016ffbc end=0x00170068 symbol=FUN_0016ffbc lang=c99 */
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

extern void *DAT_00338b08;
extern int FUN_000d8c24(void *, int, int);

#pragma opt_strength_reduction off

undefined4 FUN_0016ffbc(int param_1)
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  
  uVar3 = 0;
  if (*(int *)(param_1 + 0x20c) != 0) {
LOOP_BODY:
      void *context = DAT_00338b08;
      int **entries = *(int ***)(param_1 + 0x208);
      piVar4 = entries[uVar3];
      iVar1 = FUN_000d8c24(context,3,*piVar4);
      if (iVar1 != 0) {
        if (*(signed char *)(iVar1 + 0x60) >= 0) {
          if (*(unsigned char *)(param_1 + *piVar4 + 0xb3b) == 4) {
            return 1;
          }
        }
      }
      uVar2 = *(uint *)(param_1 + 0x20c);
      uVar3 = uVar3 + 1;
    if (uVar3 < uVar2) goto LOOP_BODY;
  }
  return 0;
}
