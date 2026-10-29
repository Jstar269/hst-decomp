/* HSTMATCH module=EBOOT.BIN start=0x00223c04 end=0x00223db0 symbol=FUN_00223c04 lang=c++ rodata=0x002c99e4 */
/* Hand-written reconstruction from the disassembly; exact match verified (matching idiom: the switch is on 'kind - 1' with a 'case -1:' sharing the default body, which gives retail's addiu -1 / addiu +1 table index); names and types await human review. */
#include "hst/dual_entry_pane.h"

extern "C" {
extern float DAT_0034a290;
extern float DAT_0034a294;
extern float DAT_0034a2a0;
extern float DAT_002f10e8;
extern float DAT_002f10ec;
void FUN_00223de0(DualEntryPane *);
}

static inline float Clamp(const float &value, const float &lo, const float &hi)
{
  return value < lo ? lo : (!(value > hi) ? value : hi);
}

/* Selects entry (key, kind): the kind is mapped to an id, and a new entry is started unless it is already current. */
extern "C" void FUN_00223c04(DualEntryPane *self, int key, int kind)
{
  int id;
  switch (kind - 1) {
  case 6:
    id = 6;
    break;
  case 5:
    id = 0;
    break;
  case 4:
    id = 1;
    break;
  case 3:
    id = 2;
    break;
  case 2:
    id = 3;
    break;
  case 1:
    id = 4;
    break;
  case 0:
    id = 5;
    break;
  case -1:
  default:
    id = -1;
    break;
  }
  FUN_00223de0(self);
  if (self->cur < 0) {
    self->cur = 0;
    self->key[0] = 0;
  }
  if (self->key[self->cur] == key && self->id[self->cur] == id)
    return;
  self->cur ^= 1; /* switch to the other entry */
  self->key[self->cur] = key;
  self->id[self->cur] = id;
  self->unk8c[self->cur] = DAT_0034a290;
  self->unk94[self->cur] = DAT_0034a294;
  self->unk9c[self->cur] = Clamp(DAT_0034a2a0, DAT_002f10e8, DAT_002f10ec);
  self->unka4[self->cur] = 0;
}
