/* HSTMATCH module=EBOOT.BIN start=0x0017e9c0 end=0x0017ea5c symbol=FUN_0017e9c0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed the helper with its object pointer between the second and final float parameters to preserve the retail EABI argument-register order; exact match verified; names and types await human review. */
typedef struct {
  char pad0[0x54];
  float f54, f58, f5c;
  char pad1[0x10];
  float rate;
} Game;
typedef struct { char pad[0x2d0]; float progress; unsigned char active; } Self;
extern Game *FUN_0016bc7c(void);
extern void FUN_0005c76c(float, float, void *, float, float);
void FUN_0017e9c0(Self *self) {
  if (self->active != 0) {
    float delta = FUN_0016bc7c()->rate;
    float progress = self->progress + delta;
    self->progress = progress;
    if (progress >= 1.0f) {
      self->active = 0;
      self->progress = 1.0f;
    }
  }
  Game *a = FUN_0016bc7c();
  Game *b = FUN_0016bc7c();
  Game *c = FUN_0016bc7c();
  float progress = self->progress;
  float third = c->f5c;
  FUN_0005c76c(a->f54, b->f58, (char *)self + 0x10, third, progress);
}

