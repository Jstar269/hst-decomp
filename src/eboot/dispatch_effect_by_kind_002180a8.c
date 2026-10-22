/* HSTMATCH module=EBOOT.BIN start=0x002180a8 end=0x002181a4 symbol=FUN_002180a8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char *DAT_00341508;
extern int FUN_00165004(char *, int);
extern float FUN_001646a0(int, int);
extern float FUN_00164740(int, int);
extern float FUN_001647ec(int, int);
extern float FUN_00164ac4(int, int);
extern float FUN_00164958(int, int);

float FUN_002180a8(int param_1, int param_2, int param_3, int param_4, int param_5)
{
  int n;
  int ptr;
  float f;

  n = FUN_00165004(DAT_00341508 + param_2 * 24, param_3);
  ptr = *(int *)(DAT_00341508 + param_2 * 24) + n * 556;
  f = 0.0f;
  switch (param_4) {
  case 0:
    f = FUN_001646a0(ptr, param_5);
    break;
  case 1:
    f = FUN_00164740(ptr, param_5);
    break;
  case 2:
    f = FUN_001647ec(ptr, param_5);
    break;
  case 3:
    f = FUN_00164ac4(ptr, param_5);
    break;
  case 4:
    f = FUN_00164958(ptr, param_5);
    break;
  }
  return f;
}
