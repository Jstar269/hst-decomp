/* HSTMATCH module=hstp_trans_main.prx start=0x00177f64 end=0x0017803c symbol=FUN_00177f64 lang=c99 */
/* Hand-written reconstruction from the disassembly (same source as the EBOOT sibling src/eboot/mode_char_swap_0016bcec.c, addresses substituted); exact match verified; names and types await human review. */
extern int DAT_003f39a8;
extern void FUN_002446f8(int *);
extern void FUN_0024476c(int *);
extern void FUN_00244258(int *, int);

/* Applies a mode request to the current state id (DAT_003f39a8): modes 1 and 2 use their own helpers, 3 and 4 go to a fixed target state. */
void FUN_00177f64(int mode)
{
  switch (mode) {
  case 1:
    FUN_002446f8(&DAT_003f39a8);
    break;
  case 2:
    FUN_0024476c(&DAT_003f39a8);
    break;
  case 3:
    switch (DAT_003f39a8) {
    case 0x27:
      FUN_00244258(&DAT_003f39a8, 0x20);
      break;
    case 0x2e:
      FUN_00244258(&DAT_003f39a8, 0x2b);
      break;
    default:
      FUN_00244258(&DAT_003f39a8, 0x1e);
      break;
    }
    break;
  case 4:
    FUN_00244258(&DAT_003f39a8, 0x1e);
    break;
  }
}
