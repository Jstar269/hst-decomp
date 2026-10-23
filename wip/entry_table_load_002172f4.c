/* HSTMATCH module=EBOOT.BIN start=0x002172f4 end=0x00217440 symbol=FUN_002172f4 lang=c99 */
extern int DAT_003070bc;
extern int DAT_002efb1c;
extern void FUN_000649c0(int *);
extern void FUN_0008c230(int *);
extern int FUN_000651b8(int *, int, int, int, int *);
extern int FUN_000650e0(int *);
extern void *FUN_00000a90(int);
extern unsigned char FUN_00065104(int *, int, int);
extern void *FUN_0006517c(int *, int, int);
extern void *FUN_000149a8(void *, void *);
extern void FUN_00066338(int *, int);
extern void FUN_00064a08(int *, int);

int FUN_002172f4(int *param_1, int param_2)
{
  int b[4];
  int a[4];
  int obj[4];
  int ret = 0;
  int off;
  int i;

  FUN_000649c0(obj);
  obj[0] = (int)&DAT_003070bc;
  FUN_0008c230(a);
  FUN_0008c230(b);
  if (FUN_000651b8(obj, param_2, 0, 0, &DAT_002efb1c) != 0) {
    *param_1 = (int)FUN_00000a90(FUN_000650e0(obj) * 0x21);
    if (FUN_000650e0(obj) >= 1) {
      off = 0;
      i = 1;
      do {
        *(char *)(*param_1 + off) = (char)FUN_00065104(obj, i, 0);
        FUN_000149a8((char *)(*param_1 + off + 1), FUN_0006517c(obj, i, 1));
        off += 0x21;
        i++;
      } while (i < FUN_000650e0(obj));
    }
    ret = 1;
  }
  obj[0] = (int)&DAT_003070bc;
  FUN_00066338(b, 0);
  FUN_00066338(a, 0);
  FUN_00064a08(obj, 0);
  return ret;
}

// NEAR MISS: 59 differing words.  Structure and body agree; what differs is register
// colouring around the prologue: retail keeps &obj in s0 (`addiu s0,sp,32`, `move a0,s0`,
// later `addiu a0,s0,32` for the second 8c230 and `move a0,s0` for the open call) and reuses
// s0 for `off` once the loop starts, while ours re-materialises `addiu a0,sp,32` and spends
// s0 on the &DAT_003070bc constant (our two `obj[0] = (int)&DAT_003070bc;` stores are CSE'd
// into one saved register; retail materialises `lui v0,0x30; addiu v0,v0,28860` twice).
// Consequence: retail has param_1->s2, param_2->s3, ret/i->s1, off->s0; ours has
// param_1->s3, param_2->s2, ret/i->s1, off->s2 and the constant in s0.
// Ruled out: typing the two vptr stores differently (`*(int **)obj = &DAT`, v4) removes the
// constant from a saved register but drops to three saved registers and a 64-byte frame
// (objects at sp+16); a 16-byte `Obj16` struct with `int *vt` (v3) shrinks the frame to 64
// the same way; every declaration order of (ret, off, i) and of (b, a, obj) leaves the four
// param/local colours unchanged; the do/while count guard, the `>= 1` test and the
// duplicated `ret = 1` already match.
// near miss from lane fm5 (unreviewed)
