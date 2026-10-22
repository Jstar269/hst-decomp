/* HSTMATCH module=EBOOT.BIN start=0x00152c60 end=0x00152cec symbol=FUN_00152c60 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py candidate FUN_00152c60) corrected by hand: pointer-typed self parameter, inverted ternary and the (x != 0) ^ 1 flag with an unsigned char parameter; exact match verified; names and types await human review. */
extern unsigned char DAT_003402f0;
extern char DAT_002dc57c;
extern char DAT_002dc580;
extern char DAT_002dc6d8[];
extern void FUN_0014c3ac(int, int, unsigned char);
extern void FUN_0014d044(void *);
extern void FUN_0014fd94(char *, int, char *);

int FUN_00152c60(char *param_1, int *param_2)
{
  if (DAT_003402f0 != 0) {
    FUN_0014d044(param_2);
    FUN_0014fd94(DAT_002dc6d8, *(int *)(param_1 + 8),
                 *(unsigned char *)(param_1 + 0xc) != 0 ? &DAT_002dc57c : &DAT_002dc580);
  }
  FUN_0014c3ac(*param_2, *(int *)(param_1 + 8), (*(unsigned char *)(param_1 + 0xc) != 0) ^ 1);
  return 0;
}
