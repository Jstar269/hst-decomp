/* HSTMATCH module=hstp_trans_main.prx start=0x001d1444 end=0x001d160c symbol=FUN_001d1444 lang=c++ */
/* Hand-written reconstruction (port of src/eboot/update_result_phase_001c30b8.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
/* Matching idioms: the phase < 16 arm ends in an early return (the nested if/else form leaves retail's duplicated lw a0,84(s0) out); the flag is int b = (f60 < 0); if (b == 0) { b = 1; if (!(x <= 0.0f)) b = 0; } (c.le.s + bc1t with the preset in the slot); the 0x2879e0 call declares its float after the pointer (F(void *, float, int, int, int, int)), which puts addiu a0 before li a2. */
struct Inner {
  char pad[0x78];
  float f78;
};
struct Target {
  char pad[0x60];
  int f60;
  int pad64;
  Inner *f68;
};
struct Self {
  char pad0[8];
  int phase;
  char pad0c[0xc];
  void *f18;
  char pad1c[0x38];
  Target *f54;
  char pad58[0x88];
  int fe0;
  unsigned char fe4;
  char pade5[3];
  int fe8;
  char padec[4];
  unsigned char ff0;
};
struct Game {
  char pad[0x1320];
};

extern "C" {
extern Game *DAT_003e48b4;
extern char DAT_003eaad8[];
extern int DAT_003f48d0;
extern int DAT_003f4830[];
extern void *DAT_003ea914;
void FUN_00299114(void *, float, int, int, int, int);
void FUN_001c28a4(float, void *);
void FUN_001c04c4(void *);
void FUN_00232650(float, float);
void FUN_0023212c(void *, int, int);
void FUN_002bd1a4();
void FUN_001d8ebc(void *);
void FUN_001d8ec4(void *);
void FUN_0019cdc8(void *, int);
void FUN_001dbf68(Self *, int, int);
void FUN_001dbab4(void *);

void FUN_001d1444(Self *self)
{
  if (self->phase == 0) {
    FUN_00299114((char *)DAT_003e48b4 + 0x1320, 0.0f, 0, 15, 0, 0);
    FUN_001c28a4(0.5f, DAT_003eaad8);
  }
  if (self->phase < 16) {
    if (self->phase == 15) {
      FUN_001c04c4(DAT_003eaad8);
    }
    return;
  }
  int b = self->f54->f60 < 0;
  if (b == 0) {
    b = 1;
    if (!(self->f54->f68->f78 <= 0.0f)) {
      b = 0;
    }
  }
  if (b) {
    if (self->fe0 < DAT_003f48d0) {
      FUN_00232650(110.0f, 50.0f);
      FUN_0023212c(self->f54, DAT_003f4830[self->fe0], 1);
      self->fe0 = self->fe0 + 1;
    } else {
      FUN_002bd1a4();
      if (self->fe4 != 0) {
        FUN_001d8ec4(self->f18);
        self->fe8 = 1;
        self->ff0 = 1;
        FUN_0019cdc8(DAT_003ea914, 3);
        FUN_001dbf68(self, 8, 1);
        FUN_001dbab4(self->f18);
        self->fe0 = 0;
      } else {
        FUN_001d8ebc(self->f18);
        self->fe8 = 0;
        self->ff0 = 1;
        FUN_0019cdc8(DAT_003ea914, 3);
        FUN_001dbf68(self, 8, 1);
        FUN_001dbab4(self->f18);
        self->fe0 = 0;
      }
    }
  }
}
}
