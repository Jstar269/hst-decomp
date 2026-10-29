/* HSTMATCH module=hstp_trans_main.prx start=0x0013a414 end=0x0013a450 symbol=FUN_0013a414 lang=c99 */
/* Clone of src/eboot/FUN_0012eebc.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct CameraObj {
  char pad00[0xe0];
  void *attached;             /* 0xe0 object attached to the camera */
} CameraObj;

extern u32 DAT_003e48b8;
extern void FUN_0016be80();

/* Notifies the attached object when the mode flag is 1. */
void FUN_0013a414(CameraObj *self)
{
  if ((self->attached != 0) && (DAT_003e48b8 == 1)) {
    FUN_0016be80(self->attached);
  }
}
