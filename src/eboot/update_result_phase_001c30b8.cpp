/* HSTMATCH module=EBOOT.BIN start=0x001c30b8 end=0x001c3280 symbol=FUN_001c30b8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
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
extern Game *DAT_0033b574;
extern char DAT_0034179c[];
extern int DAT_0034b590;
extern int DAT_0034b4f0[];
extern void *DAT_003415d4;
void FUN_002879e0(void *, float, int, int, int, int);
void FUN_001b4848(float, void *);
void FUN_001b2430(void *);
void FUN_002230dc(float, float);
void FUN_00222bb8(void *, int, int);
void FUN_002ad9e8();
void FUN_001ca8e8(void *);
void FUN_001ca8f0(void *);
void FUN_001905b8(void *, int);
void FUN_001cd88c(Self *, int, int);
void FUN_001cd3d8(void *);

void FUN_001c30b8(Self *self)
{
  if (self->phase == 0) {
    FUN_002879e0((char *)DAT_0033b574 + 0x1320, 0.0f, 0, 15, 0, 0);
    FUN_001b4848(0.5f, DAT_0034179c);
  }
  if (self->phase < 16) {
    if (self->phase == 15) {
      FUN_001b2430(DAT_0034179c);
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
    if (self->fe0 < DAT_0034b590) {
      FUN_002230dc(110.0f, 50.0f);
      FUN_00222bb8(self->f54, DAT_0034b4f0[self->fe0], 1);
      self->fe0 = self->fe0 + 1;
    } else {
      FUN_002ad9e8();
      if (self->fe4 != 0) {
        FUN_001ca8f0(self->f18);
        self->fe8 = 1;
        self->ff0 = 1;
        FUN_001905b8(DAT_003415d4, 3);
        FUN_001cd88c(self, 8, 1);
        FUN_001cd3d8(self->f18);
        self->fe0 = 0;
      } else {
        FUN_001ca8e8(self->f18);
        self->fe8 = 0;
        self->ff0 = 1;
        FUN_001905b8(DAT_003415d4, 3);
        FUN_001cd88c(self, 8, 1);
        FUN_001cd3d8(self->f18);
        self->fe0 = 0;
      }
    }
  }
}
}
