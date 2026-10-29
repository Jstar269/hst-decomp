/* HSTMATCH module=EBOOT.BIN start=0x001f0560 end=0x001f0850 symbol=FUN_001f0560 lang=c99 rodata=0x002c8f8c */
/* Ghidra pseudocode (hstgen.py tag a7, via wip/attempt_001f0560.c) corrected by hand: fields of the stage object are real struct members (the raw offset form makes MWCC share &state in a1/v1), `iVar2 > 5` for the count test (slti at), the busy test written busy != 0 -> false else bit test, and the post-case `cur` reload folded into the compare; exact match verified; names and types await human review. */
typedef struct Stage {
  char pad00[0x44];
  int init;
  char pad48[0x510 - 0x48];
  unsigned int unit;
  char pad514[0x58c - 0x514];
  unsigned char busy;
  char pad58d[0x1084 - 0x58d];
  int state;
  int count;
  char pad108c[0x10a0 - 0x108c];
  int target;
  int cur;
} Stage;

extern char *DAT_002cfc8c;
extern char DAT_0034179c;
extern void FUN_001b1c44(void *, int);
extern void FUN_001e09dc();
extern void FUN_001e28e0();
extern void FUN_001e2990();
extern void FUN_001e5ac4();
extern void FUN_001e5b64();
extern void FUN_001e5da0();
extern void FUN_001e5df0();
extern void FUN_001e5e3c();
extern void FUN_001f3770();
extern void FUN_001f474c();
extern void FUN_001f47a4();
extern void FUN_001f4bfc();

void FUN_001f0560(Stage *self)
{
  unsigned char ready;
  int next;
  int prev;

  if (self->init == 0) {
    self->state = 0;
    self->count = 0;
    FUN_001f474c(self, 0);
    FUN_001e09dc(self->unit, 2);
    FUN_001e2990(self->unit);
    FUN_001e5ac4(self->unit);
    FUN_001e5da0(self->unit);
  }
  switch (self->state) {
  case 0:
    next = self->count + 1;
    self->count = next;
    if (10 < next) {
      self->state = 1;
      self->count = 0;
      FUN_001e5b64(self->unit, self->state);
      FUN_001e5e3c(self->unit, self->state);
      FUN_001b1c44(&DAT_0034179c, 8);
    }
    break;
  case 1:
  case 2:
  case 3:
  case 4:
    next = self->count + 1;
    self->count = next;
    if (next > 5) {
      if (self->state != 4) {
        FUN_001b1c44(&DAT_0034179c, 8);
      }
      next = self->state;
      self->state = next + 1;
      self->count = 0;
      FUN_001e5b64(self->unit, self->state);
      FUN_001e5e3c(self->unit, self->state);
    } else {
      if (self->busy != 0) {
        ready = 0;
      } else {
        ready = ((int)*(char *)(DAT_002cfc8c + 0x8b) << 0x1c) >> 0x1e == 0;
      }
      if (ready) {
        FUN_001b1c44(&DAT_0034179c, 3);
        self->cur = self->target;
        self->state = 6;
        self->count = 0;
        FUN_001e5df0(self->unit);
        FUN_001e5b64(self->unit, self->state);
        FUN_001e28e0(self->unit);
      }
    }
    break;
  case 5:
    prev = self->cur;
    next = prev + 0x14;
    self->cur = next;
    if (next >= self->target) {
      self->cur = self->target;
      self->state = 6;
      self->count = 0;
      FUN_001e28e0(self->unit);
    } else {
      if (self->busy != 0) {
        ready = 0;
      } else {
        ready = ((int)*(char *)(DAT_002cfc8c + 0x8b) << 0x1c) >> 0x1e == 0;
      }
      if (ready) {
        FUN_001b1c44(&DAT_0034179c, 3);
        self->cur = self->target;
        self->state = 6;
        self->count = 0;
        FUN_001e28e0(self->unit);
        FUN_001e5df0(self->unit);
      }
    }
    if (prev != self->cur) {
      FUN_001b1c44(&DAT_0034179c, 0x1a);
    }
    FUN_001e5b64(self->unit, self->state);
    break;
  case 6:
    if (self->busy != 0) {
      ready = 0;
    } else {
      ready = ((int)*(char *)(DAT_002cfc8c + 0x8b) << 0x1c) >> 0x1e == 0;
    }
    if (ready) {
      FUN_001b1c44(&DAT_0034179c, 3);
      FUN_001f3770(self);
    }
  }
  FUN_001f4bfc(self);
  FUN_001f47a4(self);
}
