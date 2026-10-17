/* HSTMATCH module=hstp_trans_main.prx start=0x00101748 end=0x001017dc symbol=FUN_00101748 lang=c99 */
/* Clone of src/eboot/copy_mat4_000fc00c.c (hstclone.py tag c1707b): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: retyped param_1 as the enclosing object so the copy base is a typed conversion held in its own register, expressed the 16 float copies as four whole-row struct assignments, and returned the sub-object pointer; exact match verified; names and types await human review. */
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

struct M4 *FUN_00101748(struct Outer *param_1, struct M4 *param_2)
{
  struct M4 *p;

  p = (struct M4 *)param_1;
  if (param_1 != 0) {
    p = (struct M4 *)((char *)p + 0x30);
  }
  p->r0 = param_2->r0;
  p->r1 = param_2->r1;
  p->r2 = param_2->r2;
  p->r3 = param_2->r3;
  return (struct M4 *)((char *)param_1 + 0x30);
}
