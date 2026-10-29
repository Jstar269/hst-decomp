/* Object of the 0x130000 sources: an elapsed/limit timer, an effect object, owned helpers and a mode word. */
#ifndef HST_TIMED_OBJ_H
#define HST_TIMED_OBJ_H

#define TIMED_NO_LIMIT (-1)   /* limit value meaning "never expires" */

/* Sub-object at +0x80 (owned, deleted with the object). */
typedef struct TimedSub {
  char pad00[0x58];
  int unk58;                  /* 0x58 row index into a table with a 0x58-byte stride */
  char pad5c[0x78 - 0x5c];
  unsigned char unk78;        /* 0x78 */
  char pad79;
  unsigned char unk7a;        /* 0x7a */
} TimedSub;

/* 0x20-byte effect object created at +0x48. */
typedef struct TimedEffect {
  int unk0;                   /* 0x0 */
  float unk4;                 /* 0x4 */
} TimedEffect;

typedef struct TimedObj {
  void *vtable;               /* 0x00 */
  char pad04[0x3c - 4];
  int elapsed;                /* 0x3c ticks since the last reset */
  int limit;                  /* 0x40 expiry in ticks, TIMED_NO_LIMIT = none */
  int unk44;                  /* 0x44 */
  TimedEffect *effect;        /* 0x48 */
  unsigned char unk4c;        /* 0x4c */
  char pad4d[0x7c - 0x4d];
  void *unk7c;                /* 0x7c owned */
  TimedSub *sub;              /* 0x80 owned */
  void *unk84;                /* 0x84 owned */
  int unk88;                  /* 0x88 */
  int mode;                   /* 0x8c */
  int unk90;                  /* 0x90 */
  char pad94[0xa0 - 0x94];
  int unka0, unka4, unka8, unkac;
  int unkb0, unkb4;
  char padb8[0xc0 - 0xb8];
  int unkc0, unkc4, unkc8, unkcc;
  int unkd0;
  char padd4[0xe0 - 0xd4];
  int unke0, unke4, unke8, unkec;
  unsigned char unkf0, unkf1, unkf2, unkf3;
  int unkf4, unkf8, unkfc, unk100;
  char pad104[0x110 - 0x104];
  int unk110, unk114, unk118, unk11c;
  int unk120;                 /* 0x120 counts up while >= 0 */
  char pad124[0x128 - 0x124];
  int unk128, unk12c, unk130;
  unsigned char unk134;       /* 0x134 */
} TimedObj;

#endif
