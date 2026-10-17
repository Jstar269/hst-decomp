/* HSTMATCH module=EBOOT.BIN start=0x0006cdb4 end=0x0006ce30 symbol=FUN_0006cdb4 lang=c99 */
/* Clone of src/sharing_main/copy_construct_0006e39c.c (hstclone.py tag s10170158a1r3e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned char uchar;

typedef struct { int pad[3]; } Blob12;
typedef struct { int pad[4]; } Blob16;
typedef struct {
  int b;
  int c;
  Blob12 m0;
  Blob16 m1;
  float f;
  uchar g;
} Body;
typedef struct {
  int a;
  Body body;
} Obj;

extern Blob16 *FUN_0006ce30(Blob16 *, const Blob16 *);
extern Blob12 *FUN_0006ce70(Blob12 *, const Blob12 *);

Obj *FUN_0006cdb4(Obj *self, const Obj *src)
{
  Body *d;

  self->a = src->a;
  d = &self->body;
  d->b = src->body.b;
  d->c = src->body.c;
  FUN_0006ce70(&d->m0, &src->body.m0);
  FUN_0006ce30(&d->m1, &src->body.m1);
  d->f = src->body.f;
  d->g = src->body.g;
  return self;
}
