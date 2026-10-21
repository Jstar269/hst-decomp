/* HSTMATCH module=hstp_trans_main.prx start=0x001a62d0 end=0x001a63f8 symbol=FUN_001a62d0 lang=c99 */
/* Clone of src/eboot/draw_grid_quads_001997dc.c (hstclone.py tag c21sn4s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: rewritten as a counted loop with the float arguments written out; the callee's declared parameter order is (int, nine floats, int), which sets the argument-setup schedule, and the function has a dropped float parameter (alpha, f12); exact match verified; names and types await human review. */
extern void FUN_00051e30(int, int, int, int, int, int, int);
extern void FUN_000522c0(int);
extern void FUN_00052354(int, float, float, float, float, float, float, float, float, float, int);

void FUN_001a62d0(int unused, int ctx, int flags, float alpha)
{
  int i;
  int x;
  int y;

  FUN_00051e30(ctx, 0, 0, 480, 272, 0, 0);
  x = 0;
  y = 0;
  FUN_00052354(ctx, 0.0f, 0.0f, 0.0f, 0.0f, 480.0f, 256.0f, 480.0f, 256.0f, alpha, flags);
  i = 0;
  do {
    FUN_00052354(ctx, 480.0f, (float)x, (float)y, 256.0f, 512.0f, (float)(x + 16), (float)(y + 32), 272.0f, alpha, flags);
    i++;
    x += 16;
    y += 32;
  } while (i < 15);
  FUN_000522c0(ctx);
}
