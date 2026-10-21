/* HSTMATCH module=EBOOT.BIN start=0x001997dc end=0x00199904 symbol=FUN_001997dc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: rewritten as a counted loop with the float arguments written out; the callee's declared parameter order is (int, nine floats, int), which sets the argument-setup schedule, and the function has a dropped float parameter (alpha, f12); exact match verified; names and types await human review. */
extern void FUN_00051490(int, int, int, int, int, int, int);
extern void FUN_0005185c(int);
extern void FUN_00051894(int, float, float, float, float, float, float, float, float, float, int);

void FUN_001997dc(int unused, int ctx, int flags, float alpha)
{
  int i;
  int x;
  int y;

  FUN_00051490(ctx, 0, 0, 480, 272, 0, 0);
  x = 0;
  y = 0;
  FUN_00051894(ctx, 0.0f, 0.0f, 0.0f, 0.0f, 480.0f, 256.0f, 480.0f, 256.0f, alpha, flags);
  i = 0;
  do {
    FUN_00051894(ctx, 480.0f, (float)x, (float)y, 256.0f, 512.0f, (float)(x + 16), (float)(y + 32), 272.0f, alpha, flags);
    i++;
    x += 16;
    y += 32;
  } while (i < 15);
  FUN_0005185c(ctx);
}
