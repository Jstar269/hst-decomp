/* HSTMATCH module=EBOOT.BIN start=0x0016bcec end=0x0016bdc4 symbol=FUN_0016bcec lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int DAT_0034a678;
extern void FUN_002345f8(int *);
extern void FUN_0023466c(int *);
extern void FUN_00234158(int *, int);

void FUN_0016bcec(int mode)
{
  switch (mode) {
  case 1:
    FUN_002345f8(&DAT_0034a678);
    break;
  case 2:
    FUN_0023466c(&DAT_0034a678);
    break;
  case 3:
    switch (DAT_0034a678) {
    case 0x27:
      FUN_00234158(&DAT_0034a678, 0x20);
      break;
    case 0x2e:
      FUN_00234158(&DAT_0034a678, 0x2b);
      break;
    default:
      FUN_00234158(&DAT_0034a678, 0x1e);
      break;
    }
    break;
  case 4:
    FUN_00234158(&DAT_0034a678, 0x1e);
    break;
  }
}
