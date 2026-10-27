/* HSTMATCH module=EBOOT.BIN start=0x00053a38 end=0x00053b04 symbol=FUN_00053a38 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Releases what a model (the object of model.cpp: loader and destructor call this) holds: the object at +0x10 through its
   deleting destructor FUN_0004ae08(p, 1), the buffer at +0x0c (FUN_000104e0), the i3d handle at +0x08 (FUN_0004fb88 with the
   texture-name vector at +0x24, FUN_00053e08 = release_items_00053e08.cpp, lock/unlock pair around FUN_0004ecbc), the array
   at +0x00 (delete[] = __dla__FPv), then the inline Reset() of all six fields (retail stores arr = 0 twice). */
struct Vec {
  int *data;
  unsigned size;
};

struct Self {
  char *arr;            /* 0x00 */
  int f04;              /* 0x04 */
  int handle;           /* 0x08 */
  void *buf;            /* 0x0c */
  void *obj;            /* 0x10 */
  unsigned char active; /* 0x14 */
  char pad15[3];
  Vec items;            /* 0x18 */
  int f20;
  Vec other;            /* 0x24 */
  void Reset()
  {
    arr = 0;
    f04 = 0;
    handle = 0;
    buf = 0;
    obj = 0;
    active = 0;
  }
};

extern "C" {
extern char DAT_00311170[];
void *FUN_0004ae08(void *p, short flag);
void FUN_000104e0(void *p);
void FUN_0004fb88(void *g, int handle, Vec *v);
void FUN_00053e08(Self *self);
void FUN_00050d8c(void *g, int flag);
void FUN_00049194(void);
void FUN_0004ecbc(int handle);
void FUN_000491cc(void);

void FUN_00053a38(Self *self)
{
  if (self->obj != 0) {
    FUN_0004ae08(self->obj, 1);
    self->obj = 0;
  }
  if (self->buf != 0) {
    FUN_000104e0(self->buf);
    self->buf = 0;
  }
  if (self->handle != 0) {
    FUN_0004fb88(DAT_00311170, self->handle, &self->other);
    FUN_00053e08(self);
    FUN_00050d8c(DAT_00311170, 1);
    FUN_00049194();
    FUN_0004ecbc(self->handle);
    self->handle = 0;
    FUN_000491cc();
  }
  if (self->arr != 0) {
    delete[] self->arr;
    self->arr = 0;
  }
  self->Reset();
}
}
