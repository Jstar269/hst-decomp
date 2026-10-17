/* HSTMATCH module=EBOOT.BIN start=0x001cb7d0 end=0x001cb860 symbol=FUN_001cb7d0 lang=c99 */
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

extern undefined4 DAT_003415ac;
extern void FUN_0010b8cc();
extern void FUN_00114168();
extern void FUN_001c2498();
extern void FUN_001cd88c();
extern undefined * FUN_002294f4();

void FUN_001cb7d0(int param_1,undefined4 param_2)
{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x15c);
  *(undefined1 *)(iVar2 + 0xb0) = 0;
  iVar1 = (int)(FUN_002294f4(iVar2 + 0x34,*(undefined4 *)(iVar2 + 0x24),param_2,0));
  if (iVar1 != 0) {
    FUN_00114168(DAT_003415ac,1,iVar1,0,0);
    FUN_0010b8cc(**(undefined4 **)(DAT_003415ac + 0x58),0,0);
    FUN_001cd88c(iVar2,4,1);
    FUN_001c2498(iVar2);
  }
  return;
}
