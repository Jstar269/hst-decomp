/* HSTMATCH module=EBOOT.BIN start=0x002af480 end=0x002af5b0 symbol=FUN_002af480 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* EXACT. Three findings, the first two general:
   * LOCAL DECLARATION ORDER SETS THE s/t REGISTERS IN REVERSE. Declaring `struct Elem *src;` before
     `dst` (assigning src on a separate line afterwards) is what flips dst=v1 into retail's dst=t2 and
     src=t3 - everything else was already word-identical with 58 differing words before this.
   * A 16-byte `struct Vec4` member copied as one assignment loads 4 floats then stores 4
     (`lwc1 x4; swc1 x4`). Retail interleaved 2+2 for this member: model it as TWO `struct Vec2`
     members and copy each (`dst->t0 = src->t0; dst->t1 = src->t1;`), which is what makes the tail
     match. Layout is unchanged (t0 at 0x110, t1 at 0x118).
   * the 26 `struct Pair` block unrolls from ONE `struct Arr26` member assignment; a 308-byte struct
     assignment or a `char[0x134]` ghost does not unroll.
   Plus the earlier ones: param_1 must be a POINTER for the loop test's `sltu`, and both the struct
   member store/load pairs and the `--dst; --src;` order come straight from the pseudocode. */
struct Pair { int a, b; };
struct Arr26 { struct Pair v[26]; };
struct Vec4 { float x, y, z, w; };
struct Vec2 { float x, y; };

struct Elem {
  int f00;
  int f04;
  struct Arr26 arr;
  unsigned char b;
  char pad[3];
  int fdc;
  int fe0;
  struct Vec4 q;
  struct Vec4 r;
  struct Vec2 s;
  int f10c;
  struct Vec2 t0;
  struct Vec2 t1;
  int u0;
  int u1;
  int u2;
  int u3;
  int u4;
};

void FUN_002af480(char *param_1,int param_2)
{
  struct Elem *src;
  struct Elem *dst = (struct Elem *)((char *)param_1 + 0x7850);

  src = dst - param_2;
  int i;

  while (param_1 < (char *)src) {
    src--;
    dst--;
    dst->f00 = src->f00;
    dst->f04 = src->f04;
    dst->arr = src->arr;
    dst->b = src->b;
    dst->fdc = src->fdc;
    dst->fe0 = src->fe0;
    dst->q = src->q;
    dst->r = src->r;
    dst->s = src->s;
    dst->f10c = src->f10c;
    dst->t0 = src->t0;
    dst->t1 = src->t1;
    dst->u0 = src->u0;
    dst->u1 = src->u1;
    dst->u2 = src->u2;
    dst->u3 = src->u3;
    dst->u4 = src->u4;
  }
}
