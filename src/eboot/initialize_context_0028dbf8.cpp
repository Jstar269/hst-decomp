/* HSTMATCH module=EBOOT.BIN start=0x0028dbf8 end=0x0028dd1c symbol=FUN_0028dbf8 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: used address globals, returned the allocator result directly, and typed the final virtual call; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u8 DAT_00309d98;
extern u8 * DAT_003386c8;
extern char DAT_002feee4[];
extern char DAT_002feef8[];
extern u32 DAT_0030ab9c;
extern u32 DAT_0030ebf4;
extern int FUN_00000bcc(int);
extern int FUN_00010184(int,int);
extern void FUN_000104e0(int);
extern void FUN_0001bfb4(void *,unsigned int,unsigned int);
extern void FUN_0001cad0(void *,int,void *);
extern void FUN_0001cb88(void *);
extern int FUN_0001cbfc();
extern u32 FUN_0001cc54();
extern u32 * FUN_0001f06c();
extern void FUN_00253da0();
extern void FUN_00258294(int);
extern int * FUN_0028dd1c(int,char *);
}

struct Finalizer {
  virtual void slot0();
  virtual void slot1();
  virtual void slot2();
  virtual void slot3();
  virtual void slot4();
  virtual void slot5();
  virtual void finalize();
};

/* Scratch arena size, alignment, and size of the object built inside it. */
enum { SCRATCH_SIZE = 0x300000, SCRATCH_ALIGN = 0x40, CONTEXT_OBJ_SIZE = 0x1bc0 };

struct ContextHolder {
  void *vtable;             /* 0x00 */
  char pad04[0x38];
  Finalizer *context;       /* 0x3c: the object built below */
};

/* Constructor: builds the context object (FUN_0028dd1c) with a temporary scratch arena installed,
   restores the previous arena, then calls the object's finalize slot. */
extern "C" ContextHolder * FUN_0028dbf8(ContextHolder *self)
{
  int scratch;
  int obj;
  u32 prev_a;
  u32 prev_b;
  
  FUN_0001f06c();
  self->vtable = &DAT_00309d98;
  self->context = 0;
  scratch = FUN_00010184(SCRATCH_ALIGN,SCRATCH_SIZE);
  FUN_0001bfb4(&DAT_0030ab9c,scratch,SCRATCH_SIZE);
  FUN_0001cad0(&DAT_0030ebf4,1,DAT_002feee4);
  *(u32 *)(*(int *)(DAT_003386c8 + 0x40) + 0x5c) = 1;
  obj = FUN_00000bcc(CONTEXT_OBJ_SIZE);
  if (obj != 0) obj = (int)FUN_0028dd1c(obj,DAT_002feef8);
  self->context = (Finalizer *)obj;
  FUN_00253da0();
  FUN_0001cb88(&DAT_0030ebf4);
  prev_a = FUN_0001cbfc();
  prev_b = FUN_0001cc54();
  FUN_0001bfb4(&DAT_0030ab9c,prev_a,prev_b);
  if (scratch != 0) {
    FUN_000104e0(scratch);
  }
  FUN_00258294((int)self->context);
  self->context->finalize();
  return self;
}
