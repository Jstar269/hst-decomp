/* HSTMATCH module=EBOOT.BIN start=0x000fc00c end=0x000fc0a0 symbol=FUN_000fc00c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: retyped param_1 as the enclosing object so the copy base is a typed conversion held in its own register, expressed the 16 float copies as four whole-row struct assignments, and returned the sub-object pointer; readability pass; exact match verified; names and types await human review. */
struct V4 {
  float x;
  float y;
  float z;
  float w;
};

struct M4 {
  struct V4 r0;
  struct V4 r1;
  struct V4 r2;
  struct V4 r3;
};

struct Outer {
  char pad_0[0x30];
  struct M4 m;
};

/* Copies a 4x4 matrix into the matrix member of `outer` (null-safe base) and returns the member. */
struct M4 *FUN_000fc00c(struct Outer *outer, struct M4 *src)
{
  struct M4 *dst;

  dst = (struct M4 *)outer;
  if (outer != 0) {
    dst = (struct M4 *)((char *)dst + 0x30);
  }
  dst->r0 = src->r0;
  dst->r1 = src->r1;
  dst->r2 = src->r2;
  dst->r3 = src->r3;
  return (struct M4 *)((char *)outer + 0x30);
}
