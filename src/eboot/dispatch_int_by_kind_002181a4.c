/* HSTMATCH module=EBOOT.BIN start=0x002181a4 end=0x002182a0 symbol=FUN_002181a4 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode (inputs/pseudocode/ram-0x002181a4.c, no hstgen tag) corrected by hand: the if-chain rewritten as a switch with cases in source order and the result initialised after the pointer computation; exact match verified; names and types await human review. */
extern char *DAT_00341508;
extern int FUN_00165004(char *, int);
extern int FUN_00164c60(int, int);
extern int FUN_00164d00(int, int);
extern int FUN_00164e24(int, int);
extern int FUN_00164f64(int, int);
extern int FUN_00164ec4(int, int);

int FUN_002181a4(int param_1, int param_2, int param_3, int param_4, int param_5)
{
  int n;
  int ptr;
  int r;

  n = FUN_00165004(DAT_00341508 + param_2 * 24, param_3);
  ptr = *(int *)(DAT_00341508 + param_2 * 24) + n * 556;
  r = 0;
  switch (param_4) {
  case 0:
    r = FUN_00164c60(ptr, param_5);
    break;
  case 1:
    r = FUN_00164d00(ptr, param_5);
    break;
  case 2:
    r = FUN_00164e24(ptr, param_5);
    break;
  case 3:
    r = FUN_00164f64(ptr, param_5);
    break;
  case 4:
    r = FUN_00164ec4(ptr, param_5);
    break;
  }
  return r;
}
