/* HSTMATCH module=EBOOT.BIN start=0x00199104 end=0x001991cc symbol=FUN_00199104 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned char undefined1;

extern undefined1 DAT_00341770;
extern undefined1 DAT_002e189c;
extern void FUN_001991cc(undefined1 *, int);
extern void FUN_001991f8(int, int);
extern void FUN_002b7c30(void);
extern int FUN_002b7cd0(void);

void FUN_00199104(int param_1)
{
  int iVar1;

  DAT_00341770 = 0;
  switch (*(int *)(param_1 + 0x7c)) {
  case 0:
    break;
  case 1:
    iVar1 = FUN_002b7cd0();
    if (iVar1 != 0) {
      switch (iVar1) {
      case 1:
        break;
      case 2:
        DAT_00341770 = 1;
        break;
      case 3:
        FUN_002b7c30();
        break;
      case 4:
        break;
      default:
        FUN_001991cc(&DAT_002e189c,iVar1);
        break;
      }
    }
    else {
      FUN_001991f8(param_1,0);
    }
    break;
  }
}
