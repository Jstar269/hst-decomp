/* Player object seen through its state word, slot index, character pointer, sound record and model chain. */
#ifndef HST_CHARA_PLAYER_H
#define HST_CHARA_PLAYER_H

enum {
  MOTION_UNSET = -1,      /* motion id read when the model has no effect object */
  SOUND_NONE = 0xd0       /* sound id meaning "no sound" */
};

/* Effect object of a model; its first track holds the current motion id. */
typedef struct MotionEffect {
  char pad00[0xf0];
  int motion;           /* 0xf0 */
} MotionEffect;

typedef struct MotionModel {
  char pad00[0x58];
  MotionEffect *effect; /* 0x58 */
} MotionModel;

typedef struct CharaPlayer {
  char pad000[0x3c];
  int state;            /* 0x3c */
  char pad40[0x144 - 0x40];
  int unk144;           /* 0x144 */
  int slot;             /* 0x148 index of the player's slot */
  char pad14c[0x154 - 0x14c];
  short *chara;         /* 0x154 points at the character id */
  int chara_group;      /* 0x158 character container index */
  int chara_index;      /* 0x15c row inside the container */
  char pad160[0x1b4 - 0x160];
  unsigned char flag1b4; /* 0x1b4 */
  char pad1b5[0x43c - 0x1b5];
  float unk43c;         /* 0x43c compared against a scaled global limit */
  char pad440[4];
  int unk444;           /* 0x444 */
  int unk448;           /* 0x448 */
  int unk44c;           /* 0x44c */
  int unk450;           /* 0x450 */
  int unk454;           /* 0x454 */
  int unk458;           /* 0x458 */
  char pad45c[0x5b4 - 0x45c];
  int last_sound;       /* 0x5b4 sound id last played */
  char last_sound_flag; /* 0x5b8 */
  char pad5b9[0x5bc - 0x5b9];
  MotionModel *model;   /* 0x5bc */
  char pad5c0[0x84c - 0x5c0];
  int drop_count;       /* 0x84c printed as "not drop" */
  int lob_count;        /* 0x850 printed as "not lob" */
  int unk854;           /* 0x854 */
  int unk858;           /* 0x858 */
} CharaPlayer;

#endif
