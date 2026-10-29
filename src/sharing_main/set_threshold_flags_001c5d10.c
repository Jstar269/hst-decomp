/* HSTMATCH module=hstp_trans_main.prx start=0x001c5d10 end=0x001c5ee4 symbol=FUN_001c5d10 lang=c99 */
/* Hand-written reconstruction (port of src/eboot/set_threshold_flags_001b8050.c, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/threshold_flags.h"

typedef struct Game { char pad[0x3c]; int mode; } Game;
typedef struct Pl {
  char pad0[0x148];
  ThresholdFlags *flags;     /* 0x148 */
  char pad1[0x41c - 0x14c];
  int gauge;                 /* 0x41c current gauge value */
  char pad2[0x5bc - 0x420];
  int sound_pos;             /* 0x5bc argument for the positional sound lookup */
} Pl;

enum {
  GAME_MODE_A = 4,           /* modes in which the gauge flags are tracked */
  GAME_MODE_B = 5,
  GAME_MODE_C = 7,
  SOUND_LOW = 0x4c,          /* sound played when the low limit is first reached */
  SOUND_HIGH = 0x4d          /* sound played when the high limit is first reached */
};

extern Game *DAT_003e19f0;
extern float DAT_003ea654;
extern char DAT_003eaad8;
extern Pl *FUN_00089f84(Game *);
extern int FUN_0009575c(int);
extern int FUN_001bfc3c(char *, int);
extern void FUN_001c02d4(char *, int *, int, float, float, float, float, int, int, int);
extern void FUN_001c63e4(int);

/* Updates the low/high threshold flag of slot idx from the gauge ratio, playing a sound on each rising edge. */
void FUN_001c5d10(int idx)
{
  Game *g = DAT_003e19f0;
  int m = g->mode;
  if (m != GAME_MODE_A && m != GAME_MODE_C && m != GAME_MODE_B) {
    FUN_001c63e4(idx);
  } else {
    Pl *p = FUN_00089f84(g);
    if (p != 0) {
      ThresholdFlags *flags = p->flags;
      float ratio = (float)p->gauge / DAT_003ea654;
      u8 low = ratio >= 0.2f;
      u8 high = ratio >= 1.0f;
      int sound_a;
      int sound_b;
      if (low && *(u8 *)((char *)flags + idx + 0x95) == 0) {
        sound_a = FUN_001bfc3c(&DAT_003eaad8, SOUND_LOW);
        FUN_001c02d4(&DAT_003eaad8, &sound_a, FUN_0009575c(p->sound_pos), 1.0f, 1.0f, 30.0f, 75.0f, 0, 0, 0);
      }
      if (high && *(u8 *)((char *)flags + idx + 0x99) == 0) {
        sound_b = FUN_001bfc3c(&DAT_003eaad8, SOUND_HIGH);
        FUN_001c02d4(&DAT_003eaad8, &sound_b, FUN_0009575c(p->sound_pos), 1.0f, 1.0f, 30.0f, 75.0f, 0, 0, 0);
      }
      *(u8 *)((char *)flags + idx + 0x95) = low;
      *(u8 *)((char *)flags + idx + 0x99) = high;
    }
  }
}
