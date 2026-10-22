/* HSTMATCH module=EBOOT.BIN start=0x0016d110 end=0x0016d194 symbol=FUN_0016d110 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py candidate FUN_0016d110) corrected by hand: integer-first callee prototype and inverted ( != 0 ) conditions; exact match verified; names and types await human review. */
extern char *DAT_00341518;
extern int DAT_0034a77c;
extern int FUN_0024dd40(int, float);
extern int FUN_0024de88(int, int, int);

int FUN_0016d110(void)
{
  int iVar1;
  int u;

  iVar1 = (*(int (**)(void))(DAT_00341518 + 1000))();
  iVar1 = FUN_0024dd40(DAT_0034a77c, *(float *)(iVar1 + 4));
  if (FUN_0024de88(DAT_0034a77c, 0xf, iVar1) != 0) {
    u = 4;
  }
  else {
    if (FUN_0024de88(DAT_0034a77c, 4, iVar1) != 0) u = 3;
    else u = 2;
  }
  return u;
}
