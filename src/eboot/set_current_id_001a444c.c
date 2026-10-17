/* HSTMATCH module=EBOOT.BIN start=0x001a444c end=0x001a44a4 symbol=FUN_001a444c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p128a) corrected by hand: FUN_0016baa0 takes an int first parameter (no seh, the short cast dropped); exact match verified; names and types await human review. */
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

extern int FUN_0016b534(void);
extern void FUN_0016baa0(int param_1,undefined1 param_2);

void FUN_001a444c(int param_1)
{
  bool bVar1;
  int iVar2;
  
  iVar2 = **(int **)(*(int *)(param_1 + 900) + *(int *)(param_1 + 0x300) * 4);
  bVar1 = iVar2 == -1;
  if (bVar1) {
    iVar2 = FUN_0016b534();
  }
  FUN_0016baa0(iVar2,(undefined1)(bVar1));
  return;
}
