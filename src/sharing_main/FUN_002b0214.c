/* HSTMATCH module=hstp_trans_main.prx start=0x002b0214 end=0x002b0240 symbol=FUN_002b0214 lang=c99 */
/* Clone of src/eboot/FUN_002a0e08.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct FlagHolder {
  char pad[0x14c];
  u8 flag;      /* 0x14c */
} FlagHolder;

extern void FUN_00113a50();

/* Sets the flag; clearing it calls FUN_00113a50. */
void FUN_002b0214(FlagHolder *self,u8 value)
{
  self->flag = value;
  if (self->flag == '\0') {
    FUN_00113a50();
  }
}
