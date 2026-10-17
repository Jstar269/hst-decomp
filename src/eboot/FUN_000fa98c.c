/* HSTMATCH module=EBOOT.BIN start=0x000fa98c end=0x000fa9d4 symbol=FUN_000fa98c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p2), refined by hstperm.py random mutation from try/gen-p128a/v0/FUN_000fa98c.c; exact match verified; names and types await human review. */
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


void FUN_000fa98c(int param_1)
{
  uint uVar3;
  int iVar2;
  int iVar1;
  
  uVar3 = 0;
  iVar2 = param_1;
  do {
    iVar1 = *(int *)(param_1 + 0x9c);
    if (iVar1 != 0) {
      *(undefined4 *)(iVar2 + 200) = 0;
      *(undefined4 *)(iVar1 + 0x60) = 0;
      *(undefined4 *)(iVar2 + 0xcc) = 0;
      *(undefined4 *)(iVar1 + 100) = 0;
      *(undefined4 *)(iVar2 + 0xd0) = 0;
      *(undefined4 *)(iVar1 + 0x78) = 0;
    }
    uVar3 = uVar3 + 1;
    param_1 += 4;
    iVar2 = iVar2 + 0xc;
  } while (uVar3 < 0xb);
  return;
}
