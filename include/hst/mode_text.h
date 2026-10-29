/* Table that maps a mode id to the text bank and group holding its labels (used with text_bank_lookup.h). */
#ifndef HST_MODE_TEXT_H
#define HST_MODE_TEXT_H

typedef struct ModeText {
  int bank;                     /* 0x00 text bank id */
  int group;                    /* 0x04 group inside the bank (also the bank row used for counts) */
} ModeText;                     /* size 8 */

extern ModeText DAT_002ca6c0[];

#endif
