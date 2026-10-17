/* HSTMATCH module=hstp_trans_main.prx start=0x000ac714 end=0x000ac7f4 symbol=FUN_000ac714 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review (matching idioms: the context getter is called inside the first comparison, which loads the compared member after the scaled limit; the flag is an `int` set by an if/else on a single `&&`, then tested as `b == 0 && p < 0.0f`). */
/* Returns 1 when the float at +4 of the second argument is negative and not inside the band above -(0.01 * limit) of the context (the first limit applies only when the flag argument is nonzero); otherwise 0. */
struct Ctx_000ac714 {
  char pad0[0x24];
  float f24;
  char pad1[0x14];
  float f3c;
};
struct Obj_000ac714 {
  char pad0[4];
  float f4;
};
extern "C" Ctx_000ac714 *FUN_000b6e80(void *g);

extern "C" int FUN_000ac714(void *g, Obj_000ac714 *o, int flag)
{
  if (flag == 0 || o->f4 > -(FUN_000b6e80(g)->f3c * 0.01f)) {
    Ctx_000ac714 *c = FUN_000b6e80(g);
    float p = o->f4;
    int b;
    if (p > -(c->f24 * 0.01f) && p < 0.0f) {
      b = 1;
    } else {
      b = 0;
    }
    if (b == 0 && p < 0.0f) {
      return 1;
    }
  }
  return 0;
}
