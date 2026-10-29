/* HSTMATCH module=EBOOT.BIN start=0x001e4b4c end=0x001e4c48 symbol=FUN_001e4b4c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag u1ge) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

/* Widget whose float at 0x60 is set. */
typedef struct PosWidget {
  char pad00[0x60];
  float unk60;  /* 0x60 */
} PosWidget;

/* Object reached through the owner's pointer at 0x3c; only a pointer at 0x8c is used. */
typedef struct Owner3c {
  char pad00[0x8c];
  int *unk8c;  /* 0x8c */
} Owner3c;

#define ROW_COUNT 5
#define SHIFT_BIAS 480.0f

typedef struct RowPanel {
  char pad00[0x3c];
  Owner3c *unk3c;                  /* 0x3c */
  char pad40[0x9b8 - 0x40];
  PosWidget *widget[ROW_COUNT];    /* 0x9b8 */
  char pad9cc[0x1748 - 0x9cc];
  int base[ROW_COUNT];             /* 0x1748 */
} RowPanel;

extern void FUN_00102c54();
extern void FUN_001ea930();

/* Sets the float at 0x60 of each of the five widgets to its base value plus (offset + bias), calling FUN_00102c54 after each. */
void FUN_001e4b4c(float offset,RowPanel *self)
{
  int shift;
  
  shift = (int)(offset + SHIFT_BIAS);
  self->widget[0]->unk60 = (float)(self->base[0] + shift);
  FUN_00102c54(self->widget[0]);
  self->widget[1]->unk60 = (float)(self->base[1] + shift);
  FUN_00102c54(self->widget[1]);
  self->widget[2]->unk60 = (float)(self->base[2] + shift);
  FUN_00102c54(self->widget[2]);
  self->widget[3]->unk60 = (float)(self->base[3] + shift);
  FUN_00102c54(self->widget[3]);
  self->widget[4]->unk60 = (float)(self->base[4] + shift);
  FUN_00102c54(self->widget[4]);
  FUN_001ea930(self->unk3c->unk8c,(int)offset);
}
