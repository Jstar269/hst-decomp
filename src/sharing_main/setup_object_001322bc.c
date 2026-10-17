/* HSTMATCH module=hstp_trans_main.prx start=0x001322bc end=0x00132318 symbol=FUN_001322bc lang=c99 */
/* Clone of src/eboot/setup_object_0012704c.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: parameter typed char * (not int) so the base copy goes to a0 before the jal and the +0x1d0 address in the delay slot; exact match verified; names and types await human review. */
extern void FUN_00095bec(char *);
extern void FUN_001354c4(char *, int, int, int);
extern void FUN_00135ed8(char *, int, char *);
extern void FUN_00136094(char *);

void FUN_001322bc(char *param_1, int param_2)
{
  FUN_001354c4(param_1,0,-1,0);
  FUN_00135ed8(param_1,param_2,param_1 + 0x1d0);
  FUN_00095bec(param_1);
  FUN_00136094(param_1);
}
