/* HSTMATCH module=EBOOT.BIN start=0x002345bc end=0x002345f8 symbol=FUN_002345bc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p2), refined by hstperm.py random mutation from try/gen-p64a/v0/FUN_002345bc.c; exact match verified; names and types await human review. */
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


void FUN_002345bc(undefined4 *param_1,undefined4 param_2)
{
  int iVar2;
  undefined4 *puVar1;
  
  iVar2 = 9;
  puVar1 = param_1 + 9;
  do {
    iVar2 = iVar2 + -3;
    puVar1[1] = *puVar1;
    *puVar1 = puVar1[-1];
    puVar1[-1] = puVar1[-2];
    puVar1 = puVar1 + -3;
  } while (iVar2 > 0);
  param_1[1] = *param_1;
  *param_1 = param_2;
  return;
}
