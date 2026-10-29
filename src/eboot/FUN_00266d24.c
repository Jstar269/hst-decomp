/* HSTMATCH module=EBOOT.BIN start=0x00266d24 end=0x00266d94 symbol=FUN_00266d24 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
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

extern u8 DAT_00309b58;
extern CourtMode * DAT_003402a0;
extern u32 * FUN_0001f06c();

FlagObj * FUN_00266d24(FlagObj *self)
{
  FUN_0001f06c();
  self->vtable = &DAT_00309b58;
  self->unk3c = 0;
  self->unk48 = 0;
  self->unk4c = 1;
  self->unk50 = 0;
  self->unk54 = 0;
  self->unk58 = 0;
  self->unk64 = 0;
  if (DAT_003402a0->mode == COURT_MODE_FLAG6) {
    self->unk65 = 1;
  }
  else {
    self->unk65 = 0;
  }
  return self;
}
