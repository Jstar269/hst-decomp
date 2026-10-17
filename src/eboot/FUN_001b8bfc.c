/* HSTMATCH module=EBOOT.BIN start=0x001b8bfc end=0x001b8c54 symbol=FUN_001b8bfc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p1), refined by hstperm.py random mutation (perm-p1/r00/f0200_001b8bfc_m12.c); exact match verified; names and types await human review. */
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

extern void FUN_001b94f8();
extern undefined4 * FUN_001b9708();

int FUN_001b8bfc(int param_1)
{
  undefined4 uStack_4;
  int local_8;
  int local_c;
  
  FUN_001b9708((undefined4 *)param_1);
  *(undefined1 *)(param_1 + 0xc) = 0;
  local_c = param_1 + 4;
  local_8 = *(int *)(param_1 + 8);
  FUN_001b94f8(&uStack_4,(int *)param_1,&local_8,&local_c);
  *(undefined4 *)(param_1 + 0x10) = 9;
  return param_1;
}
