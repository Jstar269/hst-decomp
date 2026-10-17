/* HSTMATCH module=hstp_trans_main.prx start=0x001251d8 end=0x0012524c symbol=FUN_001251d8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p1), refined by hstperm.py random mutation (perm-p1/r00/f0499_001251d8_m08.c); exact match verified; names and types await human review. */
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

extern undefined4 DAT_0037c440;
extern void FUN_0005ffd8();

void FUN_001251d8(int param_1)
{
  int iVar2;
  int iVar1;
  
  if ((DAT_0037c440 & 0x800) != 0) {
    iVar2 = 0;
    iVar1 = param_1;
    do {
      if (*(uchar *)(param_1 + iVar2 + 0xb4) != '\0') {
        FUN_0005ffd8(*(undefined4 *)(iVar1 + 0x48),*(undefined4 *)(0xec + param_1));
      }
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 4;
    } while (iVar2 < 0x1b);
  }
  return;
}
