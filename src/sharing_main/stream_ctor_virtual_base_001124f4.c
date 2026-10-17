/* HSTMATCH module=hstp_trans_main.prx start=0x001124f4 end=0x001125a0 symbol=FUN_001124f4 lang=c99 */
/* Clone of src/eboot/stream_ctor_virtual_base_0010c17c.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the virtual-base constructor argument is the base sub-object pointer plus 0x120 (not this+400), and the vbase back-pointer store is the pointer difference (this+0x70)-*this; exact match verified; names and types await human review. */
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

extern undefined DAT_0037ffe4;
extern undefined DAT_003b11d0;
extern undefined DAT_003b11e4;
extern undefined DAT_003b122c;
extern undefined4 * FUN_00109698();
extern undefined4 * FUN_001096ac();
extern void FUN_00111414();
extern void FUN_0011262c();

int * FUN_001124f4(int *param_1,short param_2)
{
  int *piVar1;
  
  if (param_2 != 0) {
    piVar1 = param_1 + 0x1c;
    *param_1 = (int)piVar1;
    FUN_001096ac(piVar1,&DAT_0037ffe4);
    *piVar1 = (int)&DAT_003b122c;
    FUN_00109698(piVar1 + 0x48);
    FUN_00111414(piVar1);
  }
  param_1[1] = (int)&DAT_003b11d0;
  *(undefined **)*param_1 = &DAT_003b11e4;
  *(int *)(*param_1 + 0x130) = (int)(param_1 + 0x1c) - *param_1;
  param_1[2] = 0;
  param_1[3] = 0;
  *(undefined1 *)(param_1 + 0x1b) = 0;
  *(undefined1 *)((int)param_1 + 0x6d) = 0;
  FUN_0011262c(param_1);
  return param_1;
}
