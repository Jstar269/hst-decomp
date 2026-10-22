/* HSTMATCH module=EBOOT.BIN start=0x001eed9c end=0x001ef0fc symbol=FUN_001eed9c lang=c++ rodata=0x002c8f24 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Link {
  char pad[0x10];
  float f10, f14, f18, f1c;
};
struct Obj {
  char pad00[0x3c];
  int f3c;
  int state;
  char pad44[0x4cc];
  int f510;
  unsigned char f514;
  char pad515[0x4f];
  Link *f564;
  float f568;
  char pad_56c[4];
  float f570, f574, f578, f57c, f580;
  char pad584[0x34];
  int f5b8;
  unsigned char f5bc;
};

extern "C" {
extern char DAT_0034179c[];
void FUN_001fb9dc(void *);
void FUN_001ef2ec(Obj *);
void FUN_001ef424(Obj *);
void FUN_001ef824(Obj *);
void FUN_001f02fc(Obj *);
void FUN_001efcd8(Obj *);
void FUN_001f00c8(Obj *);
void FUN_001f0560(Obj *);
void FUN_001f0850(Obj *);
void FUN_001f10ec(Obj *);
void FUN_001f14a4(Obj *);
void FUN_001f15d0(Obj *);
void FUN_001f1968(Obj *);
void FUN_001f20d8(Obj *);
void FUN_001f2264(Obj *);
void FUN_001f25a4(Obj *);
void FUN_001f1e24(Obj *);
void FUN_001f1e8c(Obj *);
void FUN_001f1ea8(Obj *);
void FUN_001f4900(Obj *);
int FUN_001f92ec(Obj *);
int FUN_001f9354(Obj *);
void FUN_00219210(Link *);
int FUN_001b1f7c(char *, int);
int FUN_001e5a84(int);
int FUN_001e7198(int);
void FUN_001b413c(float, float, char *);

void FUN_001eed9c(Obj *self)
{
  bool on;
  int idx;
  if (self->f514 == 0) {
    return;
  }
  FUN_001fb9dc((char *)self + 0x3c);
  switch (self->state) {
  case 0: FUN_001ef2ec(self); break;
  case 1: FUN_001ef424(self); break;
  case 2:
  case 3: break;
  case 4: FUN_001ef824(self); break;
  case 5: FUN_001f02fc(self); break;
  case 6: FUN_001efcd8(self); break;
  case 7: FUN_001f00c8(self); break;
  case 8: FUN_001f0560(self); break;
  case 9: FUN_001f0850(self); break;
  case 10: FUN_001f10ec(self); break;
  case 11: FUN_001f14a4(self); break;
  case 12: FUN_001f15d0(self); break;
  case 13: FUN_001f1968(self); break;
  case 14: FUN_001f20d8(self); break;
  case 15: FUN_001f2264(self); break;
  case 16: FUN_001f25a4(self); break;
  case 17: FUN_001f1e24(self); break;
  case 18: FUN_001f1e8c(self); break;
  case 19: FUN_001f1ea8(self); break;
  default: break;
  }
  FUN_001f4900(self);
  if (FUN_001f92ec(self) != 0) {
    if (self->f564 != 0) {
      FUN_00219210(self->f564);
      if (FUN_001f9354(self) != 0) {
        self->f580 += 0.1f;
        float fVar5 = self->f580;
        if (fVar5 > 0.0f) {
          self->f580 = 0.0f;
        }
        float c = self->f57c;
        float d = self->f578;
        float fVar6 = self->f574;
        float fVar8 = self->f580;
        float sum = fVar6 + fVar8;
        Link *l = self->f564;
        l->f10 = self->f570;
        l->f14 = sum;
        l->f18 = d;
        l->f1c = c;

      }
    }
  }
  idx = self->f5b8;
  on = false;
  if (idx != -1) {
    unsigned char c1 = FUN_001b1f7c(DAT_0034179c, self->f5b8);
    on = c1 != 0;
    if (FUN_001b1f7c(DAT_0034179c, self->f5b8) == 0) {
      self->f5b8 = -1;
    }
  }
  if (self->f510 != 0) {
    if (FUN_001e5a84(self->f510) != -1) {
      unsigned char c2 = FUN_001b1f7c(DAT_0034179c, FUN_001e5a84(self->f510));
      on = (on | c2) != 0;
    }
  }
  if (self->f510 != 0 && FUN_001e7198(self->f510) != -1) {
    unsigned char c3 = FUN_001b1f7c(DAT_0034179c, FUN_001e7198(self->f510));
    on = (on | c3) != 0;
  }
  if (on && self->f5bc == 0) {
    FUN_001b413c(0.2734375f, 0.1f, DAT_0034179c);
    self->f5bc = 1;
  } else if (!on && self->f5bc != 0) {
    FUN_001b413c(1.0f, 0.3f, DAT_0034179c);
    self->f5bc = 0;
  }
}
}
// Matching idioms (lane om2 2026-10-22): (a) the tested field loaded into an argument register
// (`lw a0,1380(s1); beqz a0`) is the dropped FIRST ARGUMENT of the call right after the test -
// `FUN_00219210()` is `FUN_00219210(self->f564)`; (b) the float that is COALESCED with the
// destination of an in-place `add.s` follows the position of the SUM in the source, not the
// declaration order of the other floats: `float sum = f574 + f580;` written BEFORE the other
// float read gives retail's `add.s $f0,$f2,$f0` (the sum shares $f0 with its second operand)
// and the other value gets $f1; the identical sum written inline in the later store gives
// `add.s $f1,$f2,$f1` and swaps $f0/$f1 with that other value (5 words off).
