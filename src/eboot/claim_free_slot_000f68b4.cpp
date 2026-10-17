/* HSTMATCH module=EBOOT.BIN start=0x000f68b4 end=0x000f6998 symbol=FUN_000f68b4 lang=c++ */
/* Clone of src/sharing_main/claim_free_slot_000fbfa8.cpp (hstclone.py tag s10170158a2r1e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag sh2/v0) corrected by hand: rebuilt with a 32-entry slot table struct (64-byte stride starting at +0x30), first-free-slot search with break-free loop, and the quotient/remainder computed before the free-slot test; exact match verified; names and types await human review. */
extern "C" unsigned FUN_0001342c();

struct Slot {
  unsigned char used;   // +0x30
  int rem;              // +0x34
  int quot;             // +0x38
  int key1;             // +0x3c
  int key2;             // +0x40
  char pad14[0x1c];
  int v30;              // +0x60
  int v34;              // +0x64
  int v38;              // +0x68
  char pad3c[4];
};

struct Self {
  char pad00[0x30];
  Slot slots[32];
  char pad830[0xc];
  float f83c;
  char pad840[0x1c];
  int divisor;          // 0x85c
};

extern "C" void FUN_000f68b4(Self *self, int param_2, int key1, int key2)
{
  int found = -1;
  for (unsigned i = 0; i < 32; i++) {
    if (self->slots[i].used == 1) {
      if (key1 == self->slots[i].key1 && key2 == self->slots[i].key2) {
        return;
      }
    } else if (found < 0 && self->slots[i].used == 0) {
      found = i;
    }
  }
  int d = self->divisor;
  int quot = param_2 / d;
  int rem = param_2 % d;
  if (found >= 0) {
    self->slots[found].used = 1;
    self->slots[found].rem = rem;
    self->slots[found].quot = quot;
    self->slots[found].key1 = key1;
    self->slots[found].key2 = key2;
    float f = self->f83c;
    self->slots[found].v30 = (int)f;
    self->slots[found].v34 = (int)f;
    self->slots[found].v38 = FUN_0001342c();
  }
}
