/* HSTMATCH module=EBOOT.BIN start=0x0014d0b4 end=0x0014d14c symbol=FUN_0014d0b4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag t0), refined by hstperm.py random mutation from try/gen-s256b/v0c/FUN_0014d0b4.c; exact match verified; names and types await human review. */
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

extern undefined DAT_003083b0;
extern undefined DAT_0030840c;
extern int FUN_00000a90();
extern char * FUN_00014b74();
extern undefined2 FUN_0014f050();

undefined4 * FUN_0014d0b4(undefined4 *param_1,int *param_2)
{
  uint uVar1;
  int uVar2;
  
  *param_1 = (unsigned int)(&DAT_0030840c);
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = (unsigned int)(&DAT_003083b0);
  param_1[2] = 0;
  uVar1 = FUN_0014f050(param_2);
  uVar1 = uVar1 & 0xffff;
  uVar2 = FUN_00000a90(uVar1 + 1);
  param_1[2] = uVar2;
  FUN_00014b74(uVar2,*param_2,uVar1);
  *(undefined1 *)(param_1[2] + uVar1) = 0;
  *param_2 = *param_2 + uVar1;
  return param_1;
}
