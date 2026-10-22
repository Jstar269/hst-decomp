/* HSTMATCH module=EBOOT.BIN start=0x00237ff4 end=0x0023810c symbol=FUN_00237ff4 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Appends `count` copies of a 72-byte record to the ring buffer of the object: the write slot is
   base[f16] + f4, every record is copied field by field, the slot advances by one record and the
   write index f4 is bumped (the index is re-read after the copy because the copy may alias it).
   Matching idioms: MWCC copies a large plain struct assignment in bulk (a loop of eight-byte
   chunks), so the members have to be assigned one by one to get the memberwise copy; a three-byte
   sub-struct assigned as a whole gives lbu,lbu,lbu,sb,sb,sb; the null test on the slot is a
   branch-likely whose delay slot holds the early reload of the index, and the loop keeps the
   entry test in front of the body and the decrement at the bottom. */
typedef struct {
  unsigned char a;
  unsigned char b;
  unsigned char c;
} Tri;

typedef struct {
  int i;
  float f0;
  float f1;
  float f2;
  float f3;
  float f4;
  float f5;
  float f6;
  float f7;
  float f8;
  float f9;
  float f10;
  float f11;
  float f12;
  float f13;
  Tri t0;
  Tri t1;
  Tri t2;
} Rec;

typedef struct {
  Rec *base;
  int f4;
  int pad[2];
  int f16;
} Obj;

void FUN_00237ff4(Obj *self, int count, Rec *src)
{
  Rec *dst = &self->base[self->f16] + self->f4;

  while (count != 0) {
    if (dst != 0) {
      dst->i = src->i;
      dst->f0 = src->f0;
      dst->f1 = src->f1;
      dst->f2 = src->f2;
      dst->f3 = src->f3;
      dst->f4 = src->f4;
      dst->f5 = src->f5;
      dst->f6 = src->f6;
      dst->f7 = src->f7;
      dst->f8 = src->f8;
      dst->f9 = src->f9;
      dst->f10 = src->f10;
      dst->f11 = src->f11;
      dst->f12 = src->f12;
      dst->f13 = src->f13;
      dst->t0 = src->t0;
      dst->t1 = src->t1;
      dst->t2 = src->t2;
    }
    dst += 1;
    self->f4 = self->f4 + 1;
    count--;
  }
}
