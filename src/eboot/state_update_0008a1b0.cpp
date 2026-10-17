/* HSTMATCH module=EBOOT.BIN start=0x0008a1b0 end=0x0008a3a8 symbol=FUN_0008a1b0 lang=c++ */
/* Clone of src/sharing_main/state_update_0008b870.cpp (hstclone.py tag s10170158a1r1e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Per-frame state update of an object (+0x3c state, +0x40 next state): on the first frame (+0x44 == 0, a one-case switch) it sets +0x68 in debug mode and counts. The global input byte (DAT_002cfc8c + 0x8b) holds four signed 2-bit fields: when fields 3 and 0 are both non-zero it only calls 0x122d88 (field 2 == 0) or 0x122d14 (field 1 == 0); otherwise (and, in debug mode, only while +0x6c > 0) it tries to start state 7 when Ready() allows it (in debug mode not blocked by 0x100ef4; +0x4c clear; state 5 or 7: 0x123394 result >= 0; state 6: also 0xe3144 == 0), storing field 3 == 0 into the byte at +0x7a of the sub-object and calling 0x8a19c; finally the debug-mode countdown at +0x6c. Matching idioms: `switch (f44) { case 0: ... break; }` for the first-frame test (an if gives `bnez` instead of retail's `beqz; b; nop`); Ready() is an inline bool with an early `return false` and `return ok` (a flag local in the caller drops the shared `move v1,zero` / `andi` join); `!F()` not `F() == 0` (sltu/xori); the 2-bit fields are declared LSB first (s0 = bits 1:0 ... s3 = bits 7:6). Names provisional. */
struct Flags {
  signed char s0 : 2;
  signed char s1 : 2;
  signed char s2 : 2;
  signed char s3 : 2;
};
struct Global {
  char pad[0x8b];
  Flags flags;
};
struct Inner {
  char pad[0x7a];
  bool flag7a;
};
struct Holder {
  char pad[0x80];
  Inner *inner;
};
struct Self {
  char pad0[0x3c];
  int state;
  int f40;
  int f44;
  char pad48[4];
  unsigned char b4c;
  char pad4d[0x58 - 0x4d];
  unsigned char b58;
  char pad59[0x68 - 0x59];
  unsigned char b68;
  char pad69[3];
  int f6c;
  char pad70[0x8c - 0x70];
  Holder *f8c;
  char pad90[0x9c - 0x90];
  int f9c;
};
extern Global *DAT_002cfc8c;
extern unsigned char DAT_003386b8;
extern int DAT_00338c20;
extern int DAT_00338b44;
extern "C" {
void FUN_00117d38(int);
void FUN_00117cc4(int);
int FUN_000fb7b8(int);
int FUN_001181c0(int);
int FUN_000def58(int);
void FUN_00088a44(Self *, int);
}
static inline bool Ready(Self *self)
{
  bool ok = false;
  if (DAT_003386b8 != 0 && FUN_000fb7b8(DAT_00338c20) != 0) return false;
  if (self->b4c == 0) {
    switch (self->state) {
    case 5:
    case 7:
      ok = FUN_001181c0(self->f9c) >= 0;
      break;
    case 6:
      ok = FUN_001181c0(self->f9c) >= 0 && !FUN_000def58(DAT_00338b44);
      break;
    }
  }
  return ok;
}
extern "C" void FUN_0008a1b0(Self *self)
{
  switch (self->f44) {
  case 0:
    if (DAT_003386b8 != 0) self->b68 = 1;
    self->f44++;
    break;
  }
  if (DAT_002cfc8c->flags.s3 == 0 || DAT_002cfc8c->flags.s0 == 0) {
    if (DAT_003386b8 == 0 || self->f6c > 0) {
      if (Ready(self)) {
        self->f40 = 7;
        self->b58 = 0;
        self->f8c->inner->flag7a = DAT_002cfc8c->flags.s3 == 0;
        FUN_00088a44(self, 1);
      }
    }
  } else {
    if (DAT_002cfc8c->flags.s2 == 0) FUN_00117d38(self->f9c);
    else if (DAT_002cfc8c->flags.s1 == 0) FUN_00117cc4(self->f9c);
  }
  if (DAT_003386b8 != 0 && self->f6c > 0) self->f6c--;
}
