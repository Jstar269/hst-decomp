/* HSTMATCH module=EBOOT.BIN start=0x0015d960 end=0x0015dbbc symbol=FUN_0015d960 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_002dcc1c;

/* Global manager: only its phase word is used here. */
typedef struct Manager {
  char pad0[0x14];
  int phase;  /* 0x14 */
} Manager;

/* First of the two objects the state machine starts and polls for a level of 0.0f. */
typedef struct ObjA {
  char pad0[0xc];
  float level;  /* 0xc */
  char pad10[0x52 - 0x10];
  u8 unk52;     /* 0x52 */
} ObjA;

/* Second object; its level is polled the same way. */
typedef struct ObjB {
  char pad0[8];
  float level;  /* 0x8 */
} ObjB;

extern ObjA * DAT_00331b84;
extern Manager * DAT_003403f8;
extern u32 DAT_003415d4;
extern u8 DAT_0034a678;
extern ObjB * DAT_0034a820;
extern u8 DAT_0034179c;
extern void FUN_00047864();
extern void FUN_0006391c(float, void *, int);
extern void FUN_0015a118();
extern void FUN_001905b8();
extern int FUN_00190724();
extern void FUN_001b3ea4(float, void *);
extern void FUN_00234158();
extern void FUN_002930c8(float, void *, int);

typedef struct Object {
  char pad0[0x3c];
  int state;    /* 0x3c */
  int timer;    /* 0x40 frames left before the fade-out state ends */
  char pad1[4];
  unsigned char flag;  /* 0x48 selects which of the two objects is used */
  char pad2[9];
  unsigned char unk52;
} Object;

void FUN_0015d960(Object *self)
{
  int value;
  
  FUN_0015a118(DAT_003403f8);
  if (DAT_003403f8->phase == 8) {
    value = self->state;
    switch (value) {
    case 0:
    case 1:
    case 2:
      FUN_00047864();
      break;
    case 3:
      FUN_00234158(&DAT_0034a678,0x20);
      break;
    case 4:
      self->flag = 0;
      if (self->flag != 0) {
        FUN_002930c8(65534.0f,DAT_0034a820,0);
      }
      else {
        FUN_0006391c(65534.0f,DAT_00331b84,0xf);
      }
      FUN_001b3ea4(0.5f,&DAT_0034179c);
      DAT_003403f8->phase = 4;
      break;
    }
  }
  value = self->timer;
  if (value > 0) {
    self->timer = value + -1;
    if (value + -1 <= 0) {
      switch (self->state) {
      case 4:
        DAT_003403f8->phase = 8;
        FUN_00234158(&DAT_0034a678,DAT_002dcc1c);
        value = (int)(DAT_00331b84);
        *(u32 *)&DAT_00331b84->level = 0;
        *(u8 *)(value + 0x52) = 0;
        break;
      }
    }
  }
  else if ((DAT_003403f8->phase == 3) && (value = FUN_00190724(DAT_003415d4), value != 0)) {
    self->timer = 5;
  }
  if (DAT_003403f8->phase == 5) {
    FUN_001905b8(DAT_003415d4,3);
    DAT_003403f8->phase = 3;
  }
  if (DAT_003403f8->phase == 4) {
    if (self->flag != 0) {
      if (DAT_0034a820->level == 0.0f) {
        DAT_003403f8->phase = 5;
      }
    } else if (DAT_00331b84->level == 0.0f) {
      DAT_003403f8->phase = 5;
    }
  }
}
