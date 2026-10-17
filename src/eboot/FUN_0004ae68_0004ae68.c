/* HSTMATCH module=EBOOT.BIN start=0x0004ae68 end=0x0004af60 symbol=FUN_0004ae68 lang=c99 */
/* Clone of src/sharing_main/FUN_0004b044_0004b044.c (hstclone.py tag u3r2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v16) corrected by hand: reversed the status arms to preserve the retail logger branch; exact match verified; names and types await human review. */
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

extern undefined DAT_002d0828;
extern undefined DAT_00311170;
extern char DAT_002d08bc[];
extern bool FUN_0002b7fc();
extern undefined4 FUN_0002b8cc();
extern void FUN_00049194();
extern void FUN_000491cc();
extern void FUN_0004af60();
extern void FUN_0004afe0();
extern void FUN_0004b0f8();
extern uint FUN_0004cad0();
extern void FUN_0004f010();

undefined4 FUN_0004ae68(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, undefined4 param_5)
{
  int iVar1;
  
  FUN_0004af60(param_1);
  iVar1 = FUN_0004cad0(param_2,0,0x10,1);
  *param_1 = iVar1;
  if (iVar1 != 0) {
    FUN_00049194();
    iVar1 = FUN_0002b8cc(*param_1);
    FUN_000491cc();
    if (iVar1 != 0) {
      FUN_0004f010((int)&DAT_00311170,iVar1,DAT_002d08bc,0x158,&DAT_002d0828);
    } else {
      FUN_0002b7fc(*param_1,1);
      FUN_0004afe0(param_1,param_3);
      FUN_0004b0f8(param_1,param_4,param_5);
      return 1;
    }
  }
  FUN_0004af60(param_1);
  return 0;
}
