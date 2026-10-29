/* HSTMATCH module=EBOOT.BIN start=0x00112cc0 end=0x00112e10 symbol=FUN_00112cc0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: member offsets written off a base pointer at the embedded object, the address expressions rewritten, #pragma opt_strength_reduction off (retail recomputes the object address per store); readability pass (names, structs, constants); exact match verified; names and types await human review. */
#pragma opt_strength_reduction off
#include "hst/types.h"
#include "hst/progress_digits.h"
extern u8 DAT_002bc410;
extern u8 DAT_002d9210;
extern u8 DAT_0030779c;
extern u8 DAT_00307cf0;
extern u8 DAT_00307cfc;
extern u32 FUN_00056098();
extern u32 * FUN_000fbf84();
extern u32 * FUN_000fc00c();
extern u32 * FUN_000fc0a0();

/* Constructor: when in_charge is set build the embedded base object, then clear the cell values and flags. */
ProgressDigits * FUN_00112cc0(ProgressDigits *self,short in_charge)
{
  SpriteHost *host;
  int offset;
  int *word;   /* walks the object as ints; the cell values start at word 4 */

  if (in_charge != 0) {
    host = &self->base;
    self->host = host;
    FUN_000fc0a0(host);
    FUN_00056098(host->sub30);
    host->vtable = &DAT_0030779c;
    host->unk70 = 0;
    host->unk74 = -1;
    host->unk78 = 0x3f800000;
    host->unk7c = 0x3f800000;
    FUN_00056098(host->sub80);
    host->vtablec0 = &DAT_002d9210;
    FUN_000fc00c(host,&DAT_002bc410);
    FUN_000fbf84(host->sub80,&DAT_002bc410);
  }
  self->vtable7c = &DAT_00307cf0;
  *(u8 **)self->host = &DAT_00307cfc;
  offset = 0;
  self->host->unkd0 = (int)&self->base - (int)self->host;
  self->first = 0;
  self->stride = 0;
  self->count = 0;
  word = (int *)self;
  do {
    word[4] = PROGRESS_DIGIT_UNSET;
    self->unk4c[offset + 0] = 1;
    self->unk5b[offset + 0] = 0;
    self->unk6a[offset + 0] = 0;
    word[5] = PROGRESS_DIGIT_UNSET;
    self->unk4c[offset + 1] = 1;
    self->unk5b[offset + 1] = 0;
    self->unk6a[offset + 1] = 0;
    word[6] = PROGRESS_DIGIT_UNSET;
    self->unk4c[offset + 2] = 1;
    self->unk5b[offset + 2] = 0;
    self->unk6a[offset + 2] = 0;
    word[7] = PROGRESS_DIGIT_UNSET;
    self->unk4c[offset + 3] = 1;
    self->unk5b[offset + 3] = 0;
    self->unk6a[offset + 3] = 0;
    word[8] = PROGRESS_DIGIT_UNSET;
    self->unk4c[offset + 4] = 1;
    self->unk5b[offset + 4] = 0;
    self->unk6a[offset + 4] = 0;
    offset = offset + 5;
    word = word + 5;
  } while (offset < PROGRESS_DIGITS_MAX);
  return self;
}
