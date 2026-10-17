/* HSTMATCH module=EBOOT.BIN start=0x002862a8 end=0x0028637c symbol=FUN_002862a8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s256a); exact match verified; names and types await human review. */
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
extern undefined4 DAT_003415ac;
extern void FUN_00114168();
extern undefined1 * FUN_0018c9f4();

void FUN_002862a8(int param_1)
{
  int iVar1;
  undefined *puVar2;
  
  *(undefined1 *)(param_1 + 0xc5) = 1;
  if ((*(uchar *)(param_1 + 4) == '\0') &&
     (((*(ushort *)(**(int **)(*(int *)(DAT_003415ac + 0x54) + 0x10) + 0xe) & 3) != 0 ||
      (*(int *)(DAT_003415ac + 0x68) != 6)))) {
    iVar1 = (int)(FUN_0018c9f4(0x11));
    if (*(int *)(iVar1 + 4) == 0) {
      puVar2 = &DAT_002c0e20;
    }
    else if (*(int *)(*(int *)(iVar1 + 8) + 8) < 0x11) {
      puVar2 = &DAT_002c0e1c;
    }
    else if (*(int *)(*(int *)(iVar1 + 0xc) + 0xc4) < 0x13) {
      puVar2 = &DAT_002c0e18;
    }
    else {
      puVar2 = *(undefined **)(*(int *)(*(int *)(iVar1 + 0xc) + 0xc0) + 0x48);
    }
    FUN_00114168(DAT_003415ac,6,puVar2,0,0);
  }
  return;
}
