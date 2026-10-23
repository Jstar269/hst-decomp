/* HSTMATCH module=EBOOT.BIN start=0x00202a68 end=0x00202aec symbol=FUN_00202a68 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct Rec { float a; int b; float c; int d; };
struct Self { char pad[0x14]; int f14; int f18; struct Rec recs[12]; };

int FUN_00202a68(struct Self *self, int kind, int num, int *out, float f)
{
  int i;

  i = self->f14;
  if (0xc <= i) return i;
  self->recs[self->f14].b = kind;
  self->recs[self->f14].a = f;
  self->recs[self->f14].c = (float)num;
  *(int *)((char *)self + self->f14 * 0x10 + 0x28) = *out;
  if (kind == 6) {
    self->f18 = self->f14;
  }
  self->f14++;
  return self->f14 - 1;
}
