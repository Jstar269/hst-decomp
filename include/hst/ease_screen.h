/* Layout of the screen object that eases its three widget slots (constructor and per-frame update). */
#ifndef HST_EASE_SCREEN_H
#define HST_EASE_SCREEN_H

enum {
  EASE_SLOT_COUNT = 3,     /* widget slots owned by the screen */
  EASE_OBJECT_COUNT = 7,   /* child objects created after the slots */
  EASE_COUNTER_IDLE = -1   /* counter value while the animation is not running */
};

struct EaseTarget;

typedef struct EaseSlot {
  char pad00[0x60];
  float unk60;
  float unk64;
  char pad68[0x78 - 0x68];
  float unk78;
} EaseSlot;

typedef struct EaseScreen {
  void *vt;                          /* 0x00 */
  char pad04[0x50];                  /* 0x04 */
  unsigned char finished;            /* 0x54 */
  char pad55[0x5c - 0x55];           /* 0x55 */
  int unk5c;                         /* 0x5c */
  int unk60;                         /* 0x60 */
  int counter;                       /* 0x64 */
  EaseSlot *slots[EASE_SLOT_COUNT];  /* 0x68 */
  int objects[EASE_OBJECT_COUNT];    /* 0x74 */
  struct EaseTarget *target;         /* 0x90 */
  int unk94;                         /* 0x94 */
  char buf[0x100];                   /* 0x98 */
  unsigned char unk198;              /* 0x198 */
} EaseScreen;

#endif
