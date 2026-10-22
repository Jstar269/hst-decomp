/* HSTMATCH module=EBOOT.BIN start=0x00088258 end=0x00088388 symbol=FUN_00088258 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py candidate FUN_00088258) corrected by hand: float and symbol arguments, pointer-typed globals, loop declaration order; exact match verified; names and types await human review. */
typedef unsigned char undefined1;
typedef unsigned int undefined4;

extern undefined1 DAT_003071d8;
extern undefined4 DAT_00310fc4;
extern unsigned char DAT_003386b8;
extern int DAT_003386b0;
extern void FUN_0001f06c();
extern void FUN_0001f21c();
extern void FUN_00042698();
extern void FUN_0006df50(float);
extern char *FUN_0022a930();
extern char DAT_0030fe20;

int *FUN_00088258(int *param_1)
{
  unsigned int i;
  int *p;

  FUN_0001f06c();
  *param_1 = (int)(&DAT_003071d8);
  param_1[0xf] = 0xb;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  *(undefined1 *)(param_1 + 0x13) = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  *(undefined1 *)(param_1 + 0x16) = 0;
  *(undefined1 *)((int)param_1 + 0x59) = 0;
  *(undefined1 *)((int)param_1 + 0x5a) = 0;
  *(undefined1 *)((int)param_1 + 0x5b) = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 1;
  param_1[0x19] = 1;
  *(undefined1 *)(param_1 + 0x1a) = 0;
  param_1[0x1b] = 0;
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  param_1[0x28] = 0;
  param_1[0x29] = 0;
  DAT_003386b0 = (int)param_1;
  FUN_00042698(DAT_00310fc4, 0x100, 0x80);
  FUN_0006df50(2060.0f);
  FUN_0001f21c(&DAT_0030fe20, param_1);
  i = 0;
  p = param_1;
  do {
    i++;
    p[0x1c] = 0;
    p++;
  } while (i < 4);
  if (DAT_003386b8 != 0) {
    p = (int *)FUN_0022a930();
    ((char *)p)[0xab4f] = 0;
    p = (int *)FUN_0022a930();
    ((char *)p)[0xab50] = 0;
  }
  return param_1;
}
