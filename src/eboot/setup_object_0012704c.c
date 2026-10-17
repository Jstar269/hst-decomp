/* HSTMATCH module=EBOOT.BIN start=0x0012704c end=0x001270a8 symbol=FUN_0012704c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: parameter typed char * (not int) so the base copy goes to a0 before the jal and the +0x1d0 address in the delay slot; exact match verified; names and types await human review. */
extern void FUN_00093cc8(char *);
extern void FUN_0012a254(char *, int, int, int);
extern void FUN_0012aa6c(char *, int, char *);
extern void FUN_0012ac28(char *);

void FUN_0012704c(char *param_1, int param_2)
{
  FUN_0012a254(param_1,0,-1,0);
  FUN_0012aa6c(param_1,param_2,param_1 + 0x1d0);
  FUN_00093cc8(param_1);
  FUN_0012ac28(param_1);
}
