/* HSTMATCH module=EBOOT.BIN start=0x0015df28 end=0x0015e268 symbol=FUN_0015df28 lang=c++ data=0x002de73c */
/* Hand-written reconstruction (port of src/sharing_main/update_digit_counter_0016a4b4.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
/* Per-frame update of a three-digit counter display: while active, each digit i of (count + 1) / 10^i (double math through __divdf3, FUN_0000c07c = the pow wrapper, __floatsidf and __fixdfsi) shows its sprite with the row base added, or hides it for a leading zero; the digit sprites are then shifted left by the digit-count offset {13, 6, 0}[digits - 1] (each x move keeps the sprite width), two wave sprites swing by |sin(0.2 * frame)| * 6, the frame counter advances, the wave sprites are hidden when +5 is set, then 0x1668dc runs and the owned object's virtual slot 3 is called. Matching idioms: the offset table is a block-scope `int tab[3] = {13, 6, 0}` inside a 3-iteration loop that MWCC unrolls (three re-initialisations of ONE stack array; a table in an inline helper gets a slot per call and another .data copy), MoveX computes the delta before the store (`short d = nx - ox; s->x = nx;`), the digit sprite is re-read after the visibility call, and the hide argument is `(hide != 0) ^ 1`. Names provisional. */
struct Sprite {
  int f0;
  short x, y, x2, y2;
  char padc[0x24 - 0xc];
  int f24, f28;
};
struct Row {
  int a;
  const char *name;
  int base;
};
struct Obj {
  virtual void v0();
  virtual void v1();
  virtual void v2();
  virtual void v3();
};
struct Self {
  int count;
  unsigned char active;
  unsigned char hide;
  char pad6[2];
  int x[3];
  int frame;
  int wl;
  int wr;
  int arg;
  int pad24;
  Sprite *digits[3];
  Sprite *waveR;
  Sprite *waveL;
  int pad3c;
  Obj *obj;
};
extern Row DAT_002de6d4[];
extern "C" {
void FUN_000ffb3c(Sprite *, int);
void FUN_0015a304(int);
double FUN_0000c07c(double, double);
float FUN_0000bf34(float);
float fabsf(float);
}

static inline void MoveX(Sprite *s, short nx)
{
  short ox = s->x;
  short d = nx - ox;
  s->x = nx;
  s->x2 = s->x2 + d;
}

extern "C" void FUN_0015df28(Self *self)
{
  if (self->active != 0) {
    int last = 0;
    for (int i = 0; i < 3; i++) {
      int v = (int)((double)(self->count + 1) / FUN_0000c07c(10.0, (double)i));
      if (v / 10 == 0 && v % 10 == 0) {
        FUN_000ffb3c(self->digits[i], 1);
      } else {
        FUN_000ffb3c(self->digits[i], 0);
        last = i + 1;
        int d = v % 10 + DAT_002de6d4[i].base;
        Sprite *s = self->digits[i];
        s->f24 = d;
        s->f28 = d;
      }
    }
    for (int k = 0; k < 3; k++) {
      int tab[3] = {13, 6, 0};
      MoveX(self->digits[k], self->x[k] - tab[last - 1]);
    }
    float amp = fabsf(FUN_0000bf34((float)self->frame * 0.2f)) * 6.0f;
    MoveX(self->waveL, (int)((float)self->wl - amp));
    MoveX(self->waveR, (int)((float)self->wr + amp));
    self->frame++;
    FUN_000ffb3c(self->waveL, (self->hide != 0) ^ 1);
    FUN_000ffb3c(self->waveR, (self->hide != 0) ^ 1);
    FUN_0015a304(self->arg);
    self->obj->v3();
  }
}
