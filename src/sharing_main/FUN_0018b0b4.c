/* HSTMATCH module=hstp_trans_main.prx start=0x0018b0b4 end=0x0018b150 symbol=FUN_0018b0b4 lang=c99 */
/* Clone of src/eboot/FUN_0017e9c0.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed the helper with its object pointer between the second and final float parameters to preserve the retail EABI argument-register order; exact match verified; names and types await human review. */
typedef struct {
  char pad0[0x54];
  float f54, f58, f5c;
  char pad1[0x10];
  float rate;
} Game;
typedef struct { char pad[0x2d0]; float progress; unsigned char active; } Self;
extern Game *FUN_00177ea4(void);
extern void FUN_0005d3f4(float, float, void *, float, float);
void FUN_0018b0b4(Self *self) {
  if (self->active != 0) {
    float delta = FUN_00177ea4()->rate;
    float progress = self->progress + delta;
    self->progress = progress;
    if (progress >= 1.0f) {
      self->active = 0;
      self->progress = 1.0f;
    }
  }
  Game *a = FUN_00177ea4();
  Game *b = FUN_00177ea4();
  Game *c = FUN_00177ea4();
  float progress = self->progress;
  float third = c->f5c;
  FUN_0005d3f4(a->f54, b->f58, (char *)self + 0x10, third, progress);
}

