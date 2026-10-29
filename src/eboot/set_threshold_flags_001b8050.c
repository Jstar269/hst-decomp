/* HSTMATCH module=EBOOT.BIN start=0x001b8050 end=0x001b8224 symbol=FUN_001b8050 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s512a) corrected by hand: typed structs, the mode test is the inverted if (m != 4 && m != 7 && m != 5) with the default call FUN_001b86f8(idx) (Ghidra drops the argument still in a0), two separate address-taken locals for the two FUN_001b1c44 results, float compares with the variable on the left, FUN_001b2240 prototyped (char *, int *, int, float, float, float, float, int, int, int) so the argument setup follows retail's order; readability pass; exact match verified; names and types await human review. */
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

extern Game *DAT_003386b0;
extern float DAT_00341314;
extern char DAT_0034179c;
extern Pl *FUN_0008882c(Game *);
extern int FUN_00093838(int);
extern int FUN_001b1c44(char *, int);
extern void FUN_001b2240(char *, int *, int, float, float, float, float, int, int, int);
extern void FUN_001b86f8(int);

/* Updates the low/high threshold flag of slot idx from the gauge ratio, playing a sound on each rising edge. */
void FUN_001b8050(int idx)
{
  Game *g = DAT_003386b0;
  int m = g->mode;
  if (m != GAME_MODE_A && m != GAME_MODE_C && m != GAME_MODE_B) {
    FUN_001b86f8(idx);
  } else {
    Pl *p = FUN_0008882c(g);
    if (p != 0) {
      ThresholdFlags *flags = p->flags;
      float ratio = (float)p->gauge / DAT_00341314;
      u8 low = ratio >= 0.2f;
      u8 high = ratio >= 1.0f;
      int sound_a;
      int sound_b;
      if (low && *(u8 *)((char *)flags + idx + 0x95) == 0) {
        sound_a = FUN_001b1c44(&DAT_0034179c, SOUND_LOW);
        FUN_001b2240(&DAT_0034179c, &sound_a, FUN_00093838(p->sound_pos), 1.0f, 1.0f, 30.0f, 75.0f, 0, 0, 0);
      }
      if (high && *(u8 *)((char *)flags + idx + 0x99) == 0) {
        sound_b = FUN_001b1c44(&DAT_0034179c, SOUND_HIGH);
        FUN_001b2240(&DAT_0034179c, &sound_b, FUN_00093838(p->sound_pos), 1.0f, 1.0f, 30.0f, 75.0f, 0, 0, 0);
      }
      *(u8 *)((char *)flags + idx + 0x95) = low;
      *(u8 *)((char *)flags + idx + 0x99) = high;
    }
  }
}
