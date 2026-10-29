/* HSTMATCH module=EBOOT.BIN start=0x002704c0 end=0x002705fc symbol=FUN_002704c0 lang=c++ */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* EXACT. Two levers were needed on top of the earlier %hi/%lo symbol-address fix:
   * the duplicated 3rd/4th argument must be materialised through a local (`void *dup = &DAT_002fe324;`)
     so MWCC completes `lui a2,0x30; addiu a2,a2,-7388` back to back instead of deferring the addiu
     past `lui a0/lui a1`;
   * the post-alloc null test has ONE store after the `if`, not a store before and another inside:
     `iVar3 = new(...); if (iVar3) iVar3 = ctor(iVar3); *(u4*)(this+0xf0) = iVar3;` MWCC duplicates the
     store into both paths and encodes the null path as `beqzl v0` with `sw v0,240(s0)` in the delay
     slot. Writing the store twice by hand gives a plain `beqz` and stays one word off. */
#include "hst/types.h"
#include "hst/replace_screen.h"

extern "C" {
extern u8 DAT_002fe2d0;
extern u8 DAT_002fe324;
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

/* Replace the screen's model with the one from record table recs1: load it, and drop it again if loading fails. */
extern "C" void FUN_002704c0(ReplaceScreen *self)
{
  int loaded;
  int rec_off;
  int model;
  u32 model_arg;
  int *old;
  
  rec_off = FUN_002791a4(self,1);
  model = FUN_00279578(self,1);
  rec_off = rec_off + model * 4;
  if (self->unk180 < 0) {
    return;
  }
  {
    rec_off = rec_off * REPLACE_REC_SIZE;
    {
      void *dup;

      dup = &DAT_002fe324;
      FUN_0001ca58(&DAT_0030ebf4,DAT_002fe2b4,dup,dup,
                   *(u32 *)((char *)self->recs1.data + rec_off + 8),&DAT_002fe2d0);
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
    loaded = FUN_00095104(model_arg,1,*(u32 *)((char *)self->recs1.data + rec_off + 8),0,0);
    FUN_0001cb88(&DAT_0030ebf4);
    if ((loaded == '\0') && (old = (int *)self->model, old != (int *)0x0)) {
      delete ((ModelB *)(old));
      self->model = 0;
    }
  }
}
