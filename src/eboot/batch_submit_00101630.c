/* HSTMATCH module=EBOOT.BIN start=0x00101630 end=0x001016f4 symbol=FUN_00101630 lang=c99 */
/* Hand-written reconstruction from the disassembly (candidate hstgen.py a1/v0 restructured with structs; callee FUN_001018d0 prototyped with short parameters, which fixes the argument load order); exact match verified; names and types await human review. */
typedef struct Ent {
  int f0, f1, f2, f3;
  short s4, s5, s6, s7, s8;
  int f7, f8;
} Ent;
typedef struct Self { int p[5]; int e; unsigned cap; } Self;

extern void FUN_001018d0(Self *, int, int, short, short, short, short, short, int, int, int, int);
extern void FUN_00107174(void *, unsigned);

void FUN_00101630(Self *self, Ent *e, unsigned n)
{
  int i;

  if (self->e == 0 && self->cap < n) {
    FUN_00107174((char *)self + 0x10, n);
  }
  i = 0;
  if (0 < (int)n) {
    do {
      FUN_001018d0(self, e->f2, e->f3, e->s4, e->s5, e->s6, e->s7, e->s8, e->f7, e->f0, e->f1, e->f8);
      i = i + 1;
      e = e + 1;
    } while (i < (int)n);
  }
}
