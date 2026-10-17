/* HSTMATCH module=EBOOT.BIN start=0x001c352c end=0x001c35ec symbol=FUN_001c352c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed the byte-check return and float/pointer helper arguments; exact match verified; names and types await human review. */
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
extern undefined4 DAT_003415d4;
extern void *DAT_0034a114;
extern void FUN_00103628();
extern int FUN_001155c0();
extern undefined4 FUN_001156d4();
extern void FUN_001905b8();
extern void FUN_001c6cfc(float,void *,int);
extern void FUN_001ca8f0();
extern void FUN_001cd3d8();
extern void FUN_001cd88c();

void FUN_001c352c(int param_1)
{
  int iVar1;
  
  iVar1 = FUN_001155c0(DAT_003415ac);
  if (iVar1 != 0) {
    FUN_00103628(DAT_003415ac,1);
    iVar1 = FUN_001156d4(DAT_003415ac);
    if (iVar1 == 0) {
      FUN_001ca8f0(*(undefined4 *)(param_1 + 0x18));
      *(undefined4 *)(param_1 + 0xe8) = 1;
      *(undefined1 *)(param_1 + 0xf0) = 0;
      FUN_001905b8(DAT_003415d4,3);
      FUN_001cd88c(param_1,8,1);
      FUN_001cd3d8(*(undefined4 *)(param_1 + 0x18));
    }
    else {
      FUN_001cd88c(param_1,0,1);
      FUN_001c6cfc(1.0f,DAT_0034a114,1);
    }
  }
  return;
}
