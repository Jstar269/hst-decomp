/* HSTMATCH module=hstp_trans_main.prx start=0x000672b8 end=0x00067358 symbol=FUN_000672b8 lang=c++ */
/* Clone of src/eboot/vec_swap_build_00065e64.cpp (hstclone.py tag c064507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct {
  int f0;
  int f4;
  int f8;
} Vec;

struct Tag {};
struct Tag2 {};

extern "C" void FUN_00067cf4(Vec *, Vec *, Tag);
extern "C" void FUN_00067358(Vec *, int, int, Tag);
extern "C" void FUN_000673f4(Vec *, int);

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

extern "C" void FUN_000672b8(Vec *self, Vec *other)
{
  Vec tmp;
  tmp.f0 = 0;
  tmp.f4 = 0;
  tmp.f8 = 0;
  FUN_00067cf4(&tmp, other, Tag());
  FUN_00067358(&tmp, self->f0, self->f0 + self->f4 * 12, Tag());
  Swap3(self, &tmp, Tag2());
  FUN_000673f4(&tmp, -1);
}
