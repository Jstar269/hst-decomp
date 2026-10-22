/* HSTMATCH module=EBOOT.BIN start=0x00153aac end=0x00153b98 symbol=FUN_00153aac lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py candidate FUN_00153aac) corrected by hand: pointer-typed parameters and byte globals, ternary for the message pick; exact match verified; names and types await human review. */
extern unsigned char DAT_003402f0;
extern unsigned char DAT_00341d80;
extern char DAT_002dc7c8[];
extern char DAT_002dc7e8[];
extern char DAT_002dc430[];
extern char DAT_002dc440[];
extern int DAT_0034a114;
extern void FUN_000143b0(char *, char *, int);
extern void FUN_0014d044(void *);
extern void FUN_0014fd94(char *, int, char *);
extern void FUN_001cc784(int, char *);
extern void FUN_001cc99c(int, int, int, int, int);

int FUN_00153aac(char *param_1, char *param_2)
{
  char buf[32];
  int b;

  FUN_000143b0(buf, DAT_002dc7c8, *(int *)(param_1 + 8));
  FUN_001cc784(DAT_0034a114, buf);
  DAT_00341d80 = *(int *)(param_1 + 0xc) == 1;
  b = *(int *)(param_1 + 0x10) == 1;
  if (DAT_003402f0 != 0) {
    FUN_0014d044(param_2);
    FUN_0014fd94(DAT_002dc7e8, *(int *)(param_1 + 0xc), b ? DAT_002dc430 : DAT_002dc440);
  }
  FUN_001cc99c(DAT_0034a114, *(int *)(param_1 + 0xc) == 2, 1, *(int *)(param_1 + 0x14), b);
  *(char *)(*(int *)(param_2 + 0xc) + 0x59) = 1;
  *(char *)(param_2 + 0x10) = 1;
  return 0;
}
