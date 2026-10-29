/* HSTMATCH module=EBOOT.BIN start=0x002705fc end=0x00270738 symbol=FUN_002705fc lang=c++ */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* EXACT. Same two levers as its sibling 0x002704c0 (see that file): `void *dup = &DAT_002fe32c;`
   for the duplicated 3rd/4th argument (so `lui a2,0x30; addiu a2,a2,-7380` stays back to back),
   and ONE store after the `if` on the alloc result so MWCC duplicates it and encodes the null path
   as `beqzl v0` with the store in the delay slot. */
#include "hst/types.h"
#include "hst/replace_screen.h"

extern "C" {
extern u8 DAT_002fe2d0;
extern u8 DAT_002fe32c;
extern char DAT_002fe2b4[];
extern char DAT_0030ebf4[];
extern int FUN_00000bcc(...);
extern void FUN_0001ca58(...);
extern void FUN_0001cb88(...);
extern int FUN_00094fa4(...);
extern unsigned char FUN_00095104(...);
extern int FUN_002791a4(...);
extern u32 FUN_00279578(...);
}
/* Two views of the model for its virtual destructor (separate classes keep the two deletes apart). */
struct ModelA { virtual ~ModelA(); };
struct ModelB { virtual ~ModelB(); };

/* Replace the screen's model with the one from record table recs3: load it, and drop it again if loading fails. */
extern "C" void FUN_002705fc(ReplaceScreen *self)
{
  unsigned char loaded;
  int rec_off;
  int model;
  u32 model_arg;
  int *old;
  
  rec_off = FUN_002791a4(self,3);
  model = FUN_00279578(self,3);
  rec_off = rec_off + model * 4;
  if (self->unk180 < 0) {
    return;
  }
  {
    rec_off = rec_off * REPLACE_REC_SIZE;
    {
      void *dup;

      dup = &DAT_002fe32c;
      FUN_0001ca58(&DAT_0030ebf4,DAT_002fe2b4,dup,dup,
                   *(u32 *)((char *)self->recs3.data + rec_off + 8),&DAT_002fe2d0);
    }
    old = (int *)self->model;
    if (old != (int *)0x0) {
      delete ((ModelA *)(old));
      self->model = 0;
    }
    model = FUN_00000bcc(REPLACE_MODEL_SIZE);
    if (model != 0) {
      model = FUN_00094fa4(model);
    }
    self->model = (void *)model;
    model_arg = model;
    loaded = FUN_00095104(model_arg,3,*(u32 *)((char *)self->recs3.data + rec_off + 8),0,0);
    if ((loaded == '\0') && (old = (int *)self->model, old != (int *)0x0)) {
      delete ((ModelB *)(old));
      self->model = 0;
    }
    FUN_0001cb88(&DAT_0030ebf4);
  }
}
