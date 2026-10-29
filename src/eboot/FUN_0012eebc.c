/* HSTMATCH module=EBOOT.BIN start=0x0012eebc end=0x0012eef8 symbol=FUN_0012eebc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct CameraObj {
  char pad00[0xe0];
  void *attached;             /* 0xe0 object attached to the camera */
} CameraObj;

extern u32 DAT_0033b578;
extern void FUN_0015f8f4();

/* Notifies the attached object when the mode flag is 1. */
void FUN_0012eebc(CameraObj *self)
{
  if ((self->attached != 0) && (DAT_0033b578 == 1)) {
    FUN_0015f8f4(self->attached);
  }
}
