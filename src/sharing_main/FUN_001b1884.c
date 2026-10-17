/* HSTMATCH module=hstp_trans_main.prx start=0x001b1884 end=0x001b1900 symbol=FUN_001b1884 lang=c99 */
/* Clone of src/eboot/FUN_001a42b8.c (hstclone.py tag u4r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: inverted dispatch condition and widened comparison flag to int; exact match verified; names and types await human review. */
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

extern void FUN_00177c64();
extern int FUN_001b1900();

void FUN_001b1884(int param_1,int param_2)
{
  int bVar1;
  int iVar2;
  
  if (param_2 != 0) {
    iVar2 = **(int **)(*(int *)(param_1 + 900) + *(int *)(param_1 + 0x300) * 4);
    bVar1 = iVar2 == -1;
    if (bVar1) {
      iVar2 = FUN_001b1900();
    }
    FUN_00177c64(iVar2,bVar1);
  }
  else {
    *(undefined4 *)(param_1 + 0x2fc) = *(undefined4 *)(param_1 + 0x308);
    *(undefined4 *)(param_1 + 0x300) = *(undefined4 *)(param_1 + 0x30c);
    *(undefined4 *)(param_1 + 0x304) = *(undefined4 *)(param_1 + 0x310);
  }
  return;
}
