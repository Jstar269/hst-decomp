/* HSTMATCH module=hstp_trans_main.prx start=0x00277ca0 end=0x00277d10 symbol=FUN_00277ca0 lang=c99 */
/* Clone of src/eboot/FUN_00266d24.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

/* Court mode value for which the object's flag at 0x65 is set. */
#define COURT_MODE_FLAG6 6

/* Court object; only the mode word is read. */
typedef struct CourtMode {
  char pad00[0x1364];
  int mode;                /* 0x1364 */
} CourtMode;

/* Object built on the base at 0x1f06c; the fields below are cleared or preset by its constructor. */
typedef struct FlagObj {
  const void *vtable;      /* 0x00 */
  char pad04[0x3c - 4];
  u32 unk3c;               /* 0x3c */
  char pad40[8];
  u32 unk48;               /* 0x48 */
  u8 unk4c;                /* 0x4c, initial 1 */
  char pad4d[3];
  u32 unk50;               /* 0x50 */
  u32 unk54;               /* 0x54 */
  u32 unk58;               /* 0x58 */
  char pad5c[8];
  u8 unk64;                /* 0x64 */
  u8 unk65;                /* 0x65, set when the court mode is COURT_MODE_FLAG6 */
} FlagObj;

extern u8 DAT_003b2e40;
extern CourtMode * DAT_003e95e0;
extern u32 * FUN_0001ec44();

FlagObj * FUN_00277ca0(FlagObj *self)
{
  FUN_0001ec44();
  self->vtable = &DAT_003b2e40;
  self->unk3c = 0;
  self->unk48 = 0;
  self->unk4c = 1;
  self->unk50 = 0;
  self->unk54 = 0;
  self->unk58 = 0;
  self->unk64 = 0;
  if (DAT_003e95e0->mode == COURT_MODE_FLAG6) {
    self->unk65 = 1;
  }
  else {
    self->unk65 = 0;
  }
  return self;
}
