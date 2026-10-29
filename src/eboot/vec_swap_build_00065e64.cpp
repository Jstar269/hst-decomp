/* HSTMATCH module=EBOOT.BIN start=0x00065e64 end=0x00065f04 symbol=FUN_00065e64 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct {
  int f0;
  int f4;
  int f8;
} Vec;

struct Tag {};
struct Tag2 {};

extern "C" void FUN_000668a0(Vec *, Vec *, Tag);
extern "C" void FUN_00065f04(Vec *, int, int, Tag);
extern "C" void FUN_00065fa0(Vec *, int);

static inline void Swap3(Vec *a, Vec *b, Tag2)
{
  int t;
  t = a->f8;
  a->f8 = b->f8;
  b->f8 = t;
  t = a->f0;
  a->f0 = b->f0;
  b->f0 = t;
  t = a->f4;
  a->f4 = b->f4;
  b->f4 = t;
}

extern "C" void FUN_00065e64(Vec *self, Vec *other)
{
  Vec tmp;
  tmp.f0 = 0;
  tmp.f4 = 0;
  tmp.f8 = 0;
  FUN_000668a0(&tmp, other, Tag());
  FUN_00065f04(&tmp, self->f0, self->f0 + self->f4 * 12, Tag());
  Swap3(self, &tmp, Tag2());
  FUN_00065fa0(&tmp, -1);
}
