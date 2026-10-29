/* View of the slot table object at its two handle fields and level (the 0x1b4000 sources); the slot table layout itself is in slot_table.h. */
#ifndef HST_SLOT_FADE_H
#define HST_SLOT_FADE_H

typedef struct SlotFadeTable {
  char pad000[0x7ac];
  int handle_a;      /* 0x7ac handle, negative when unset */
  char pad7b0[4];
  int handle_b;      /* 0x7b4 handle, negative when unset */
  char pad7b8[0x7d0 - 0x7b8];
  int handle_cur;    /* 0x7d0 set to handle_a when the level is 0, cleared when it is raised, -1 when none */
  float level;       /* 0x7d4 level last set (0.0f to 1.0f) */
} SlotFadeTable;

#endif
