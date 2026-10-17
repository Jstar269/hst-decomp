/* HSTMATCH module=EBOOT.BIN start=0x00063dc8 end=0x00063e44 symbol=FUN_00063dc8 lang=c99 */
/* Clone of src/sharing_main/FUN_00064c8c_00064c8c.c (hstclone.py tag u5cr2e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned int uint;
typedef struct State {
  void *handle;
  float argument;
  uint scale_bits;
  uint limit_bits;
  uint field10;
  uint field14;
  uint factor_bits;
  uint factor_copy_bits;
} State;
extern void *FUN_00000bcc(uint size);
extern void *FUN_00050fc0(void *object);
extern void FUN_000513fc(void *object, int flag);
State *FUN_00063dc8(State *self, float argument)
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
  if (object) object = FUN_00050fc0(object);
  self->handle = object;
  FUN_000513fc(object, 1);
  return self;
}
