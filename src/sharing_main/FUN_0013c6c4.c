/* HSTMATCH module=hstp_trans_main.prx start=0x0013c6c4 end=0x0013c714 symbol=FUN_0013c6c4 lang=c99 */
/* Clone of src/eboot/FUN_0013110c.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0001ef14();
extern void FUN_0012f2d0();
extern u32 FUN_001303ec();

/* Object whose member at 0x80 is configured, with the result stored at 0x88 and the constant 3 at 0x8c. */
typedef struct HolderObj {
  char pad00[0x80];
  u32 unk80;        /* 0x80 */
  char pad84[4];
  u32 unk88;        /* 0x88 */
  u32 unk8c;        /* 0x8c */
} HolderObj;

void FUN_0013c6c4(HolderObj *self)
{
  u32 value;
  
  FUN_0001ef14(self->unk80,1);
  FUN_0012f2d0(self->unk80,0,0);
  value = FUN_001303ec(self->unk80);
  self->unk88 = value;
  self->unk8c = 3;
}
