/* HSTMATCH module=EBOOT.BIN start=0x00266a24 end=0x00266a9c symbol=FUN_00266a24 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p128a) corrected by hand: modeled the helper output as a four-word vector and typed object float fields; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/mover.h"

extern float FUN_0000c6dc(float param_1,float param_2);
struct Vector4 {
  float value[3];
  int tail;
};
extern void FUN_00022518(struct Vector4 *out, const float *in);

/* Turns a movement vector into a heading (atan2 of x and z); when flag is 0 also latches the vector and clears the update flag. */
void FUN_00266a24(Mover *self,const float *delta,int flag)
{
  struct Vector4 local;
  float result;
  
  self->prevHeading = self->heading;
  FUN_00022518(&local,delta);
  local.tail = 0;
  result = FUN_0000c6dc(local.value[0],local.value[2]);
  self->heading = result;
  if (flag == 0) {
    self->unk150[0] = self->unk130[0];
    self->unk150[1] = self->unk130[1];
    self->unk150[2] = self->unk130[2];
    self->unk150[3] = self->unk130[3];
    self->unk160 = 0;
  }
  return;
}
