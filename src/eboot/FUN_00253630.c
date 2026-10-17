/* HSTMATCH module=EBOOT.BIN start=0x00253630 end=0x002536f0 symbol=FUN_00253630 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag t0), refined by hstperm.py random mutation from try/gen-s256b/v0/FUN_00253630.c; exact match verified; names and types await human review. */
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

extern undefined DAT_002fcc70;
extern char DAT_002fcc4c[];
extern int * FUN_000649c0();
extern int * FUN_00064a08();
extern undefined4 FUN_00064bf4();
extern undefined4 FUN_000650e0();
extern int FUN_00065104();

undefined4 * FUN_00253630(undefined4 *param_1)
{
  int iVar1;
  int iVar2;
  undefined1 auStack_10 [16];
  
  *param_1 = 0;
  FUN_000649c0(auStack_10);
  FUN_00064bf4(auStack_10,DAT_002fcc4c,0,&DAT_002fcc70);
  param_1[6] = 0;
  iVar2 = 0;
  iVar1 = FUN_000650e0(auStack_10);
  if (0 < iVar1) {
    do {
      iVar1 = FUN_00065104(auStack_10,iVar2,3);
      if (iVar1 != 0) {
        iVar1 = param_1[6];
        param_1[6] = iVar1 + 1;
        param_1[iVar1 + 7] = iVar2;
      }
      iVar2 = 1 + iVar2;
      iVar1 = FUN_000650e0(auStack_10);
    } while (iVar2 < iVar1);
  }
  FUN_00064a08(auStack_10,0xffffffff);
  return param_1;
}
