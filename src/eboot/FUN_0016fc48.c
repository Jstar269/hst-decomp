/* HSTMATCH module=EBOOT.BIN start=0x0016fc48 end=0x0016fca4 symbol=FUN_0016fc48 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p1), refined by hstperm.py random mutation (perm-p1/r00/f0404_0016fc48_m02.c); exact match verified; names and types await human review. */
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


void FUN_0016fc48(int param_1)
{
  int iVar1;
  int iVar3;
  int iVar2;
  
  iVar3 = 0;
  iVar2 = param_1;
  do {
    iVar1 = (**(code **)(param_1 + 1000))(iVar3);
    iVar3 = iVar3 + 1;
    *(char *)(iVar1 + 1) = (char)*(undefined4 *)(iVar2 + 0xc0);
    iVar2 = iVar2 + 4;
  } while (iVar3 < 0xf);
  return;
}
