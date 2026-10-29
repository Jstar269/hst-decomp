/* NPC voice pack table: two vectors (kind "NPC_w" and "NPC_m") of 18-byte rows, 6 groups of 3 bytes each. */
#ifndef HST_NPC_VOICE_H
#define HST_NPC_VOICE_H

enum {
  NPC_VOICE_ROW_SIZE = 18,
  NPC_VOICE_GROUPS = 6,
  NPC_VOICE_COLS = 3,
  NPC_KIND_W = 0,         /* label starts with "NPC_w" */
  NPC_KIND_M = 1          /* label starts with "NPC_m" */
};

typedef struct NpcVoiceRow {
  char c[NPC_VOICE_ROW_SIZE];
} NpcVoiceRow;

typedef struct NpcVoiceVec {
  NpcVoiceRow *base;      /* 0x00 */
  unsigned int count;     /* 0x04 */
  unsigned int cap;       /* 0x08 */
} NpcVoiceVec;

#endif
