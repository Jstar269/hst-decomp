/* HSTMATCH module=hstp_trans_main.prx start=0x0028a92c end=0x0028a998 symbol=FUN_0028a92c lang=c99 helpers=FUN_00280834@0x00280834-0x00280860 */
/* Hand-written reconstruction from the disassembly (adapted from the exact EBOOT twin src/eboot/mode_setter_f138_00279648.c: addresses retargeted, the same-file static log stub FUN_00280834 defined in front of the target and placed at its own retail address by helpers=); exact match verified; names and types await human review. */
/* Stores a scroll value for the current mode 1..4 and logs it with the format "SetScroll(%d)=%d\n" (DAT_003a7388);
   other modes are ignored. Retail keeps the store in the stub call's delay slot, which needs the stub's known
   clobber set (static in the same file). Field names other than the scroll array are placeholders. */
extern char DAT_003a7388[];
static void FUN_00280834(...)
{
}

typedef struct Obj {
  char pad0[0x104];
  int mode;
  char pad1[0x10];
  int f118[4];
  int f128[4];
  int scroll[4];
  int f148[4];
} Obj;

void FUN_0028a92c(Obj *o, int value)
{
  int mode = o->mode;
  switch (mode) {
  case 1:
  case 2:
  case 3:
  case 4:
    o->scroll[mode - 1] = value;
    FUN_00280834(DAT_003a7388, mode, value);
    break;
  }
}
