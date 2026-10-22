/* HSTMATCH module=hstp_trans_main.prx start=0x001fd198 end=0x001fd4f8 symbol=FUN_001fd198 lang=c++ rodata=0x002d93bc */
/* Clone of src/eboot/process_state_001eed9c.cpp (hstclone.py tag om2): addresses substituted; exact match verified; names and types await human review. */
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
extern char DAT_003eaad8[];
void FUN_0020a0f4(void *);
void FUN_001fd6e8(Obj *);
void FUN_001fd828(Obj *);
void FUN_001fdc28(Obj *);
void FUN_001fe700(Obj *);
void FUN_001fe0dc(Obj *);
void FUN_001fe4cc(Obj *);
void FUN_001fe964(Obj *);
void FUN_001fec54(Obj *);
void FUN_001ff4f0(Obj *);
void FUN_001ff8a8(Obj *);
void FUN_001ff9d4(Obj *);
void FUN_001ffd6c(Obj *);
void FUN_002004dc(Obj *);
void FUN_00200668(Obj *);
void FUN_002009a8(Obj *);
void FUN_00200228(Obj *);
void FUN_00200290(Obj *);
void FUN_002002ac(Obj *);
void FUN_00202e90(Obj *);
int FUN_002079a4(Obj *);
int FUN_00207a0c(Obj *);
void FUN_00228728(Link *);
int FUN_001c0010(char *, int);
int FUN_001f3c9c(int);
int FUN_001f53b0(int);
void FUN_001c2280(float, float, char *);

void FUN_001fd198(Obj *self)
{
  bool on;
  int idx;
  if (self->f514 == 0) {
    return;
  }
  FUN_0020a0f4((char *)self + 0x3c);
  switch (self->state) {
  case 0: FUN_001fd6e8(self); break;
  case 1: FUN_001fd828(self); break;
  case 2:
  case 3: break;
  case 4: FUN_001fdc28(self); break;
  case 5: FUN_001fe700(self); break;
  case 6: FUN_001fe0dc(self); break;
  case 7: FUN_001fe4cc(self); break;
  case 8: FUN_001fe964(self); break;
  case 9: FUN_001fec54(self); break;
  case 10: FUN_001ff4f0(self); break;
  case 11: FUN_001ff8a8(self); break;
  case 12: FUN_001ff9d4(self); break;
  case 13: FUN_001ffd6c(self); break;
  case 14: FUN_002004dc(self); break;
  case 15: FUN_00200668(self); break;
  case 16: FUN_002009a8(self); break;
  case 17: FUN_00200228(self); break;
  case 18: FUN_00200290(self); break;
  case 19: FUN_002002ac(self); break;
  default: break;
  }
  FUN_00202e90(self);
  if (FUN_002079a4(self) != 0) {
    if (self->f564 != 0) {
      FUN_00228728(self->f564);
      if (FUN_00207a0c(self) != 0) {
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
    unsigned char c1 = FUN_001c0010(DAT_003eaad8, self->f5b8);
    on = c1 != 0;
    if (FUN_001c0010(DAT_003eaad8, self->f5b8) == 0) {
      self->f5b8 = -1;
    }
  }
  if (self->f510 != 0) {
    if (FUN_001f3c9c(self->f510) != -1) {
      unsigned char c2 = FUN_001c0010(DAT_003eaad8, FUN_001f3c9c(self->f510));
      on = (on | c2) != 0;
    }
  }
  if (self->f510 != 0 && FUN_001f53b0(self->f510) != -1) {
    unsigned char c3 = FUN_001c0010(DAT_003eaad8, FUN_001f53b0(self->f510));
    on = (on | c3) != 0;
  }
  if (on && self->f5bc == 0) {
    FUN_001c2280(0.2734375f, 0.1f, DAT_003eaad8);
    self->f5bc = 1;
  } else if (!on && self->f5bc != 0) {
    FUN_001c2280(1.0f, 0.3f, DAT_003eaad8);
    self->f5bc = 0;
  }
}
}
// Matching idioms (lane om2 2026-10-22): (a) the tested field loaded into an argument register
// (`lw a0,1380(s1); beqz a0`) is the dropped FIRST ARGUMENT of the call right after the test -
// `FUN_00228728()` is `FUN_00228728(self->f564)`; (b) the float that is COALESCED with the
// destination of an in-place `add.s` follows the position of the SUM in the source, not the
// declaration order of the other floats: `float sum = f574 + f580;` written BEFORE the other
// float read gives retail's `add.s $f0,$f2,$f0` (the sum shares $f0 with its second operand)
// and the other value gets $f1; the identical sum written inline in the later store gives
// `add.s $f1,$f2,$f1` and swaps $f0/$f1 with that other value (5 words off).
