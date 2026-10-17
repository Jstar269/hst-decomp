/* HSTMATCH module=EBOOT.BIN start=0x002199c8 end=0x00219a50 symbol=FUN_002199c8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p1), refined by hstperm.py random mutation (perm-p1/r00/f0391_002199c8_m15.c); exact match verified; names and types await human review. */
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

extern void FUN_00051490();
extern void FUN_0005185c();
extern void FUN_0005a770();

void FUN_002199c8(undefined4 *param_1)
{
  int iVar2;
  int iVar1;
  
  FUN_00051490(*param_1,0,0,0x1e0,0x110,0,0);
  iVar2 = 0;
  iVar1 = 0;
  do {
    FUN_0005a770(param_1[1] + iVar1,*param_1,0,0);
    iVar2 = iVar2 + 1;
    iVar1 = iVar1 + 0xa0;
  } while (iVar2 < 200);
  FUN_0005185c(*param_1);
  return;
}
