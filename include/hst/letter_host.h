/* C view of the object that owns a letter panel at +0x1d0 (the panel's first word is its state). */
#ifndef HST_LETTER_HOST_H
#define HST_LETTER_HOST_H

typedef struct LetterPanelRef {
  int state;          /* 0x00 */
} LetterPanelRef;

typedef struct LetterHost {
  char pad00[0x1b0];
  int unk1b0;         /* 0x1b0 gate: the panel is only driven while this is 5 */
  char pad1b4[0x1d0 - 0x1b4];
  LetterPanelRef *panel; /* 0x1d0 */
} LetterHost;

#endif
