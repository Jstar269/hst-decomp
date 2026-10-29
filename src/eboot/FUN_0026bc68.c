/* HSTMATCH module=EBOOT.BIN start=0x0026bc68 end=0x0026bccc symbol=FUN_0026bc68 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/sharing_screen.h"

/* Global record, only its word at 0x40 is read here. */
typedef struct RecordHead {
  char pad0[0x40];
  u32 unk40; /* 0x40 */
} RecordHead;

extern RecordHead * DAT_003386c8;
extern int * FUN_0025c474();
extern int * FUN_0025de54();
extern int * FUN_00261e1c();
extern int * FUN_00269798();
extern int * FUN_0026b590();

/* Constructor of the sharing screen: copies the record word and builds the sub-objects and the layout pane. */
SharingScreen * FUN_0026bc68(SharingScreen *self)
{
  self->unk0 = DAT_003386c8->unk40;
  FUN_00269798(self->sub4);
  FUN_0025de54(self->sub110);
  FUN_0025c474(self->sub6f0);
  FUN_00261e1c(self->subabc);
  FUN_0026b590(&self->pane);
  self->unkbb8 = 0;
  self->unkbc8 = 0;
  return self;
}
