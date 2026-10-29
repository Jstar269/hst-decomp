/* HSTMATCH module=EBOOT.BIN start=0x00266424 end=0x002664c0 symbol=FUN_00266424 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: typed the final copied state field as float; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/mover.h"

extern void FUN_00055044();
extern void FUN_00059174();
extern void FUN_0005f0d8();
extern float FUN_00128e40(float param_1,float param_2);
extern void FUN_00266818();
extern void FUN_0026694c();
extern void FUN_00266b1c();

/* Per-frame update: steps the vector, refreshes the heading and updates the body (and the optional second body). */
void FUN_00266424(Mover *self)
{
  MoverBody *body;
  float heading;
  
  FUN_0026694c(self);
  heading = FUN_00128e40(self->heading,self->prevHeading);
  self->heading = heading;
  FUN_00266b1c(self);
  body = self->body;
  FUN_00059174(body);
  FUN_0005f0d8(body);
  if (self->body2 != 0) {
    FUN_00055044(self->body2,self->body->unk30);
    body = self->body2;
    FUN_00059174(body);
    FUN_0005f0d8(body);
  }
  FUN_00266818(self);
  self->body->unk80 = self->body->tracks[0].value;
}
