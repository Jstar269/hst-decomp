/* HSTMATCH module=hstp_trans_main.prx start=0x000544f8 end=0x000545c4 symbol=FUN_000544f8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Releases what a model (the object of model.cpp: loader 0x0005427c, destructor 0x000541d8 call this) holds: the object at +0x10 through its
   deleting destructor FUN_0004afe4(p, 1), the buffer at +0x0c (FUN_000104e0), the i3d handle at +0x08 (FUN_0005043c with the
   texture-name vector at +0x24, FUN_00054954 = release_items_00054954.cpp, lock/unlock pair around FUN_0004f404), the array
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
extern char DAT_003ba4b0[];
void *FUN_0004afe4(void *p, short flag);
void FUN_000104e0(void *p);
void FUN_0005043c(void *g, int handle, Vec *v);
void FUN_00054954(Self *self);
void FUN_000516a0(void *g, int flag);
void FUN_00048fb8(void);
void FUN_0004f404(int handle);
void FUN_00049020(void);

void FUN_000544f8(Self *self)
{
  if (self->obj != 0) {
    FUN_0004afe4(self->obj, 1);
    self->obj = 0;
  }
  if (self->buf != 0) {
    FUN_000104e0(self->buf);
    self->buf = 0;
  }
  if (self->handle != 0) {
    FUN_0005043c(DAT_003ba4b0, self->handle, &self->other);
    FUN_00054954(self);
    FUN_000516a0(DAT_003ba4b0, 1);
    FUN_00048fb8();
    FUN_0004f404(self->handle);
    self->handle = 0;
    FUN_00049020();
  }
  if (self->arr != 0) {
    delete[] self->arr;
    self->arr = 0;
  }
  self->Reset();
}
}
