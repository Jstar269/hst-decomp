/* HSTMATCH module=hstp_trans_main.prx start=0x00064c8c end=0x00064d08 symbol=FUN_00064c8c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"
typedef struct State {
  void *handle;
  float argument;
  u32 scale_bits;
  u32 limit_bits;
  u32 field10;
  u32 field14;
  u32 factor_bits;
  u32 factor_copy_bits;
} State;
extern void *FUN_00000bcc(u32 size);
extern void *FUN_000518d4(void *object);
extern void FUN_00051d9c(void *object, int flag);
State *FUN_00064c8c(State *self, float argument)
{
  void *object;
  self->handle = 0;
  self->argument = argument;
  self->scale_bits = 0x43700000;
  self->limit_bits = 0x43080000;
  self->field10 = 0;
  self->field14 = 0;
  self->factor_bits = 0x3f8147ae;
  self->factor_copy_bits = 0x3f8147ae;
  object = FUN_00000bcc(0x48);
  if (object) object = FUN_000518d4(object);
  self->handle = object;
  FUN_00051d9c(object, 1);
  return self;
}
