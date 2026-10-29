/* HSTMATCH module=hstp_trans_main.prx start=0x0029f3c0 end=0x0029f4e4 symbol=FUN_0029f3c0 lang=c++ */
/* Hand-written reconstruction (port of src/eboot/initialize_context_0028dbf8.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u8 DAT_003b3080;
extern u8 * DAT_003e1a08;
extern char DAT_003a7e58[];
extern char DAT_003a7e6c[];
extern u32 DAT_003b3e6c;
extern u32 DAT_003b7ebc;
extern int FUN_00000bcc(int);
extern int FUN_00010184(int,int);
extern void FUN_000104e0(int);
extern void FUN_0001bb2c(void *,unsigned int,unsigned int);
extern void FUN_0001c684(void *,int,void *);
extern void FUN_0001c73c(void *);
extern int FUN_0001c848();
extern u32 FUN_0001c8a0();
extern u32 * FUN_0001ec44();
extern void FUN_00264244();
extern void FUN_00268744(int);
extern int * FUN_0029f4e4(int,char *);
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

/* Constructor: builds the context object (FUN_0029f4e4) with a temporary scratch arena installed,
   restores the previous arena, then calls the object's finalize slot. */
extern "C" ContextHolder * FUN_0029f3c0(ContextHolder *self)
{
  int scratch;
  int obj;
  u32 prev_a;
  u32 prev_b;
  
  FUN_0001ec44();
  self->vtable = &DAT_003b3080;
  self->context = 0;
  scratch = FUN_00010184(SCRATCH_ALIGN,SCRATCH_SIZE);
  FUN_0001bb2c(&DAT_003b3e6c,scratch,SCRATCH_SIZE);
  FUN_0001c684(&DAT_003b7ebc,1,DAT_003a7e58);
  *(u32 *)(*(int *)(DAT_003e1a08 + 0x40) + 0x5c) = 1;
  obj = FUN_00000bcc(CONTEXT_OBJ_SIZE);
  if (obj != 0) obj = (int)FUN_0029f4e4(obj,DAT_003a7e6c);
  self->context = (Finalizer *)obj;
  FUN_00264244();
  FUN_0001c73c(&DAT_003b7ebc);
  prev_a = FUN_0001c848();
  prev_b = FUN_0001c8a0();
  FUN_0001bb2c(&DAT_003b3e6c,prev_a,prev_b);
  if (scratch != 0) {
    FUN_000104e0(scratch);
  }
  FUN_00268744((int)self->context);
  self->context->finalize();
  return self;
}
