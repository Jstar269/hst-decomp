/* HSTMATCH module=EBOOT.BIN start=0x001b8050 end=0x001b8224 symbol=FUN_001b8050 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s512a) corrected by hand: typed structs, the mode test is the inverted if (m != 4 && m != 7 && m != 5) with the default call FUN_001b86f8(idx) (Ghidra drops the argument still in a0), two separate address-taken locals for the two FUN_001b1c44 results, float compares with the variable on the left, FUN_001b2240 prototyped (char *, int *, int, float, float, float, float, int, int, int) so the argument setup follows retail's order; exact match verified; names and types await human review. */
#include "hst/types.h"
typedef struct Game { char pad[0x3c]; int mode; } Game;
typedef struct Pl {
  char pad0[0x148];
  char *f148;
  char pad1[0x41c - 0x14c];
  int f41c;
  char pad2[0x5bc - 0x420];
  int f5bc;
} Pl;
extern Game *DAT_003386b0;
extern float DAT_00341314;
extern char DAT_0034179c;
extern Pl *FUN_0008882c(Game *);
extern int FUN_00093838(int);
extern int FUN_001b1c44(char *, int);
extern void FUN_001b2240(char *, int *, int, float, float, float, float, int, int, int);
extern void FUN_001b86f8(int);

void FUN_001b8050(int idx)
{
  Game *g = DAT_003386b0;
  int m = g->mode;
  if (m != 4 && m != 7 && m != 5) {
    FUN_001b86f8(idx);
  } else {
    Pl *p = FUN_0008882c(g);
    if (p != 0) {
      char *f = p->f148;
      float r = (float)p->f41c / DAT_00341314;
      u8 a = r >= 0.2f;
      u8 b = r >= 1.0f;
      int t1;
      int t2;
      if (a && *(u8 *)(f + idx + 0x95) == 0) {
        t1 = FUN_001b1c44(&DAT_0034179c, 0x4c);
        FUN_001b2240(&DAT_0034179c, &t1, FUN_00093838(p->f5bc), 1.0f, 1.0f, 30.0f, 75.0f, 0, 0, 0);
      }
      if (b && *(u8 *)(f + idx + 0x99) == 0) {
        t2 = FUN_001b1c44(&DAT_0034179c, 0x4d);
        FUN_001b2240(&DAT_0034179c, &t2, FUN_00093838(p->f5bc), 1.0f, 1.0f, 30.0f, 75.0f, 0, 0, 0);
      }
      *(u8 *)(f + idx + 0x95) = a;
      *(u8 *)(f + idx + 0x99) = b;
    }
  }
}
