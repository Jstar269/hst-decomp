/* HSTMATCH module=hstp_trans_main.prx start=0x00093860 end=0x000938e0 symbol=FUN_00093860 lang=c99 */
/* Clone of src/eboot/FUN_00091bc8_00091bc8.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1/v0c) corrected by hand: loop form and local declaration order; exact match verified; names and types await human review. */
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

extern undefined DAT_002ceac0;
extern void FUN_000006e8();
extern void FUN_0009378c();
extern void FUN_00094a98();
extern void FUN_00094c5c();
extern void FUN_0006f6ec();

void FUN_00093860(int param_1)
{
  int iVar2;
  undefined4 *puVar1;
  
  FUN_00094c5c();
  iVar2 = 5;
  puVar1 = (unsigned int *)(&DAT_002ceac0);
  for (; iVar2 >= 0; iVar2--, puVar1--) {
    FUN_00094a98(param_1,*puVar1);
  }
  if (*(int *)(param_1 + 0x24) != 0) {
    FUN_000006e8(*(int *)(param_1 + 0x24),FUN_0006f6ec);
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  FUN_0009378c(param_1);
  return;
}
