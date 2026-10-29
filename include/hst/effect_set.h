/* Object holding four effect slots (0x1b0 bytes each) plus two owned members; shared by its constructor, destructor and per-slot updates. */
#ifndef HST_EFFECT_SET_H
#define HST_EFFECT_SET_H

enum { EFFECT_SLOTS = 4, EFFECT_SLOT_SIZE = 0x1b0 };

typedef struct EffectSet {
  const void *vtable;               /* 0x0 */
  char pad04[0x38];
  void *unk3c;                      /* 0x3c owned member, freed by the destructor */
  void *unk40;                      /* 0x40 owned member, freed by the destructor */
  char pad44[0xc];
  char slots[EFFECT_SLOTS][EFFECT_SLOT_SIZE]; /* 0x50 */
  unsigned char unk710;             /* 0x710 */
  char pad711[0x7a0 - 0x711];
  unsigned char unk7a0[EFFECT_SLOTS]; /* 0x7a0 per-slot flag */
} EffectSet;

#endif
