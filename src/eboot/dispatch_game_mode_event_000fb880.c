/* HSTMATCH module=EBOOT.BIN start=0x000fb880 end=0x000fba28 symbol=FUN_000fb880 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode corrected by hand: symbolized global references and expressed mode dispatch with switches; exact match verified; names and types await human review. */
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

extern undefined * DAT_003386b0;
extern undefined4 DAT_0034a820;
extern char DAT_002d823c[];
extern undefined DAT_0030ebf4;
extern void FUN_0001cad0(void *, int, char *);
extern void FUN_0001cb88(void *);
extern void FUN_000f79b8();
extern void FUN_000f7e30();
extern undefined4 FUN_000f9508();
extern void FUN_000fbaf4();
extern void FUN_000fbbf8();
extern void FUN_001fc3dc();
extern void FUN_001fc4e8();
extern void FUN_00291b8c();
extern void FUN_00291cdc();

undefined4 FUN_000fb880(int param_1,int param_2,undefined4 param_3,undefined4 param_4)
{
  undefined4 uVar1;
  
  if (((*(int *)(DAT_003386b0 + 0x3c) == 9) && (param_2 != 0x12)) && (param_2 != 0x18)) {
    return 0;
  }
  switch (param_2) {
    case 0:
      FUN_0001cad0(&DAT_0030ebf4,1,DAT_002d823c);
      FUN_000f79b8(*(undefined4 *)(param_1 + 0x3c));
      FUN_000fbaf4(*(undefined4 *)(param_1 + 0x44));
      if (DAT_0034a820 != 0) FUN_00291b8c(DAT_0034a820,2);
      FUN_0001cb88(&DAT_0030ebf4);
      FUN_001fc3dc(*(undefined4 *)(param_1 + 0x40),0);
      break;
    case 0x18:
      FUN_0001cad0(&DAT_0030ebf4,1,DAT_002d823c);
      FUN_000f79b8(*(undefined4 *)(param_1 + 0x3c));
      FUN_000fbaf4(*(undefined4 *)(param_1 + 0x44));
      if (DAT_0034a820 != 0) FUN_00291b8c(DAT_0034a820,2);
      FUN_0001cb88(&DAT_0030ebf4);
      FUN_001fc3dc(*(undefined4 *)(param_1 + 0x40),1);
      break;
  }
  uVar1 = *(undefined4 *)(param_1 + 0x3c);
LAB_000fb9ac:
  uVar1 = FUN_000f9508(uVar1,param_2,param_3,param_4);
  switch (param_2) {
    case 0x12:
      FUN_001fc4e8(*(undefined4 *)(param_1 + 0x40),1);
      FUN_000fbbf8(*(undefined4 *)(param_1 + 0x44));
      FUN_000f7e30(*(undefined4 *)(param_1 + 0x3c),0);
      if (DAT_0034a820 != 0) FUN_00291cdc(DAT_0034a820);
  }
  return uVar1;
}
