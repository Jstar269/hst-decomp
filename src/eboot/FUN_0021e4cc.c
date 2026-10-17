/* HSTMATCH module=EBOOT.BIN start=0x0021e4cc end=0x0021e520 symbol=FUN_0021e4cc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p1), refined by hstperm.py random mutation (perm-p1/r00/f0082_0021e4cc_m00.c); exact match verified; names and types await human review. */
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

extern int FUN_002af920();

void FUN_0021e4cc(int param_1,undefined1 param_2,int param_3)
{
  int iVar1;
  int iVar2;
  
  *(undefined1 *)(param_1 + 0x1e4) = param_2;
  *(undefined1 *)(param_1 + 0x208) = 1;
  if ((param_3 != 0) &&
     (iVar2 = *(int *)(param_1 + 0x200), iVar1 = FUN_002af920(*(int *)(param_1 + 0x170)),
     iVar2 >= iVar1)) {
    *(undefined1 *)(param_1 + 0x208) = 0;
  }
  return;
}
