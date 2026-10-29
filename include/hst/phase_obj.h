/* Object with a phase (state) word and a timer, plus the flags and handle its per-frame update checks. */
#ifndef HST_PHASE_OBJ_H
#define HST_PHASE_OBJ_H

typedef struct PhaseObj {
  char pad00[0xc4];
  unsigned state;        /* 0xc4 phase id */
  int timer;             /* 0xc8 reset whenever the phase changes */
  char pad0cc[0xd4 - 0xcc];
  int unkd4;             /* 0xd4 */
  int unkd8;             /* 0xd8 */
  char pad0dc[0xf0 - 0xdc];
  unsigned char unkf0;   /* 0xf0 when set, the update treats the object as not ready */
  char pad0f1[0x164 - 0xf1];
  int handle;            /* 0x164 */
  int unk168;            /* 0x168 */
  int unk16c;            /* 0x16c */
} PhaseObj;

#endif
