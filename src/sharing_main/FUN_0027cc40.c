/* HSTMATCH module=hstp_trans_main.prx start=0x0027cc40 end=0x0027cca4 symbol=FUN_0027cc40 lang=c99 */
/* Clone of src/eboot/FUN_0026bc68.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/sharing_screen.h"

/* Global record, only its word at 0x40 is read here. */
typedef struct RecordHead {
  char pad0[0x40];
  u32 unk40; /* 0x40 */
} RecordHead;

extern RecordHead * DAT_003e1a08;
extern int * FUN_0026c924();
extern int * FUN_0026ec7c();
extern int * FUN_00272c44();
extern int * FUN_0027a714();
extern int * FUN_0027c50c();

/* Constructor of the sharing screen: copies the record word and builds the sub-objects and the layout pane. */
SharingScreen * FUN_0027cc40(SharingScreen *self)
{
  self->unk0 = DAT_003e1a08->unk40;
  FUN_0027a714(self->sub4);
  FUN_0026ec7c(self->sub110);
  FUN_0026c924(self->sub6f0);
  FUN_00272c44(self->subabc);
  FUN_0027c50c(&self->pane);
  self->unkbb8 = 0;
  self->unkbc8 = 0;
  return self;
}
