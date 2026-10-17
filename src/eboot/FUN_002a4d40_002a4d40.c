/* HSTMATCH module=EBOOT.BIN start=0x002a4d40 end=0x002a4eb8 symbol=FUN_002a4d40 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed the byte globals and module address, retained the signed result in a ternary, and reversed the final state arms; exact match verified; names and types await human review. */
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

extern unsigned char DAT_0030fbfe;
extern unsigned char DAT_00311029;
extern unsigned char DAT_0030ebf4;
extern char DAT_003007b4[];
extern char DAT_003007bc[];
extern char DAT_003007d0[];
extern void FUN_0001cad0();
extern void FUN_0001cb88();
extern void FUN_002a4eb8();
extern void FUN_002a4f18();
extern int FUN_002b7710();
extern void FUN_002b7888();

void FUN_002a4d40(int param_1)
{
  uint uVar1;
  int local_4;
  int local_8;
  
  if (*(int *)(param_1 + 0x5d0) == 0) {
    uVar1 = FUN_002b7710(DAT_003007b4,0x2425823,0,0,&local_4,4);
    uVar1 = ((int)uVar1 < 0) ? uVar1 : (uint)(local_4 == 1);
    if ((int)uVar1 < 1) {
      FUN_002a4f18(param_1,2);
    }
    else {
      DAT_00311029 = '\0';
      FUN_0001cad0(&DAT_0030ebf4,1,DAT_003007bc);
      FUN_0001cb88(&DAT_0030ebf4);
      if ((DAT_0030fbfe != '\0') && (DAT_00311029 != '\0')) {
        uVar1 = FUN_002b7710(DAT_003007b4,0x2425823,0,0,&local_8,4);
        uVar1 = ((int)uVar1 < 0) ? uVar1 : (uint)(local_8 == 1);
        if ((int)uVar1 < 1) {
          FUN_002b7888(0x200000);
        }
        FUN_0001cad0(&DAT_0030ebf4,1,DAT_003007bc);
        FUN_0001cb88(&DAT_0030ebf4);
      }
      if (DAT_0030fbfe != 0) {
        FUN_002a4f18(param_1,1);
      }
      else {
        FUN_002a4f18(param_1,2);
      }
    }
  }
  else {
    FUN_002a4eb8(DAT_003007d0);
  }
  return;
}
