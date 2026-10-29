/* HSTMATCH module=hstp_trans_main.prx start=0x00201c30 end=0x00201ca4 symbol=FUN_00201c30 lang=c99 */
/* Clone of src/eboot/FUN_001f3770.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001f08bc();
extern u32 FUN_002015d8();
extern void FUN_00207b70();
extern void FUN_0020a040();

typedef struct ActionObj {
  char pad00[0x3c];
  char sub3c[4];     /* 0x3c sub-object handed to the last helper */
  u32 unk40;         /* 0x40 */
  char pad44[0x510 - 0x44];
  u32 unk510;        /* 0x510 */
} ActionObj;

enum { ACTION_RESET = 0x14, ACTION_SPECIAL = 0xb };

void FUN_00201c30(ActionObj *self)
{
  int action;
  
  action = FUN_002015d8(self,self->unk40,0);
  if (action == ACTION_RESET) {
    FUN_00207b70(self);
  }
  else {
    if (action == ACTION_SPECIAL) {
      FUN_001f08bc(self->unk510);
    }
    FUN_0020a040(self->sub3c,action,1);
  }
}
