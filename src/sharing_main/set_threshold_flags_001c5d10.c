/* HSTMATCH module=hstp_trans_main.prx start=0x001c5d10 end=0x001c5ee4 symbol=FUN_001c5d10 lang=c99 */
/* Hand-written reconstruction (port of src/eboot/set_threshold_flags_001b8050.c, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
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
extern Game *DAT_003e19f0;
extern float DAT_003ea654;
extern char DAT_003eaad8;
extern Pl *FUN_00089f84(Game *);
extern int FUN_0009575c(int);
extern int FUN_001bfc3c(char *, int);
extern void FUN_001c02d4(char *, int *, int, float, float, float, float, int, int, int);
extern void FUN_001c63e4(int);

void FUN_001c5d10(int idx)
{
  Game *g = DAT_003e19f0;
  int m = g->mode;
  if (m != 4 && m != 7 && m != 5) {
    FUN_001c63e4(idx);
  } else {
    Pl *p = FUN_00089f84(g);
    if (p != 0) {
      char *f = p->f148;
      float r = (float)p->f41c / DAT_003ea654;
      u8 a = r >= 0.2f;
      u8 b = r >= 1.0f;
      int t1;
      int t2;
      if (a && *(u8 *)(f + idx + 0x95) == 0) {
        t1 = FUN_001bfc3c(&DAT_003eaad8, 0x4c);
        FUN_001c02d4(&DAT_003eaad8, &t1, FUN_0009575c(p->f5bc), 1.0f, 1.0f, 30.0f, 75.0f, 0, 0, 0);
      }
      if (b && *(u8 *)(f + idx + 0x99) == 0) {
        t2 = FUN_001bfc3c(&DAT_003eaad8, 0x4d);
        FUN_001c02d4(&DAT_003eaad8, &t2, FUN_0009575c(p->f5bc), 1.0f, 1.0f, 30.0f, 75.0f, 0, 0, 0);
      }
      *(u8 *)(f + idx + 0x95) = a;
      *(u8 *)(f + idx + 0x99) = b;
    }
  }
}
