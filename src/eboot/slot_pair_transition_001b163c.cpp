/* HSTMATCH module=EBOOT.BIN start=0x001b163c end=0x001b1744 symbol=FUN_001b163c lang=c++ */
/* Clone of src/sharing_main/slot_pair_transition_001bf660.cpp (hstclone.py tag s10170158a3r1e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Written as one sequence of independent `if (slot >= 0)` blocks per mode: every test re-reads the member (the reloads sit in the bltzl slots), so retail's repeated `if (b >= 0)` pairs are two separate ifs. */
struct Self { char pad[0x7ac]; int a; char pad1[4]; int b; char pad2[0x18]; int cur; float t; };
extern "C" {
extern void FUN_000628e4(int, int);
extern void FUN_00062b1c(float, int, int);
}
extern "C" void FUN_001b163c(Self *s, int mode)
{
  if (mode != 0) {
    if (s->a >= 0) {
      FUN_00062b1c(0.5f, s->a, 0);
      s->cur = s->a;
      s->t = 0.0f;
    }
    if (s->b >= 0) {
      FUN_00062b1c(0.0f, s->b, 0);
    }
    if (s->b >= 0) {
      FUN_00062b1c(0.5f, s->b, 128);
    }
  } else {
    if (s->b >= 0) {
      FUN_00062b1c(0.5f, s->b, 0);
    }
    if (s->a >= 0) {
      FUN_00062b1c(0.0f, s->a, 0);
      s->cur = s->a;
      s->t = 0.0f;
    }
    if (s->a >= 0) {
      FUN_00062b1c(0.5f, s->a, 128);
      if (s->cur >= 0) {
        FUN_000628e4(s->cur, 0);
        s->cur = -1;
      }
      s->t = 1.0f;
    }
  }
}
