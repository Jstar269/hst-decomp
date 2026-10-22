/* HSTMATCH module=EBOOT.BIN start=0x00215a58 end=0x00215ab8 symbol=FUN_00215a58 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode (inputs/pseudocode/ram-0x00215a58.c, no hstgen tag) corrected by hand: the sign-extending byte field held in an int so no seb is emitted; exact match verified; names and types await human review. */
extern char *DAT_0034a6a8;
extern int FUN_000b3c68();
extern int FUN_0020b62c(int);

int FUN_00215a58(int param_1)
{
  int c = *(signed char *)(FUN_000b3c68() + 0x14);
  int n = FUN_0020b62c(param_1);

  return *(int *)(DAT_0034a6a8 + (c + -1) * 0x20 + 0x14) + n * 0x230;
}
