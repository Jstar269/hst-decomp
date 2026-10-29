/* HSTMATCH module=EBOOT.BIN start=0x002270a0 end=0x00227408 symbol=FUN_002270a0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified (matching idioms: the by-value Vec4 parameter is a plain aligned struct so the callee copies it, the scaled vector comes from an inline Scale() returning by value, the (float)func((double)x) round trips go through __extendsfdf2/__truncdfsf2, the identity matrix is copied from an extern const Mat4 with a memberwise copy constructor); names and types await human review. */
struct Vec4 {
  float x, y, z, w;
} __attribute__((aligned(16)));

struct Mat4 {
  Vec4 r0, r1, r2, r3;
  Mat4() {}
  Mat4(const Mat4 &o) : r0(o.r0), r1(o.r1), r2(o.r2), r3(o.r3) {}
};

struct Deep {
  char pad[0x58];
  int unk58;
};
struct Mid {
  char pad0[0x44];
  void *unk44;
};
/* Global object: pointers to the sub-objects used here. */
struct Ctx {
  char pad0[0x90];
  Mid *mid;   /* 0x90 */
  char pad1[0x9c - 0x94];
  Deep *deep; /* 0x9c */
};

struct Obj {
  char pad0[0x3c];
  int state;              /* 0x3c */
  Vec4 pos;               /* 0x40 */
  char pad1[0xa0 - 0x50];
  int unka0;              /* 0xa0 selects the branch */
  char pad2[0x428 - 0xa4];
  int kind;               /* 0x428 index into the two float tables */
  int unk42c;             /* 0x42c */
  unsigned char f430pad[4];
  unsigned char stateChanged; /* 0x434 set when state is changed */
  char pad3[0x440 - 0x435];
  Vec4 vec440;            /* 0x440 */
};

extern "C" {
extern Ctx *DAT_003386b0;
extern float DAT_002f2a44[];
extern float DAT_002f29dc[];
extern const Mat4 DAT_002bc410;
void FUN_00022498(float, Vec4 *, const Vec4 *);
double FUN_0000b16c(double);
void FUN_00228600(Obj *, int);
void FUN_000ce754(void *, Mat4 *, int, float, float, int, float);
}

static inline Vec4 Scale(const Vec4 &v, float s)
{
  Vec4 r;
  FUN_00022498(s, &r, &v);
  return r;
}

/* When unka0 is 0, sets the state (3 for some kinds, else 2) and a scaled vector; otherwise runs the helper and, for kinds 13 and 18, starts an effect at the position. */
extern "C" void FUN_002270a0(Obj *self, Vec4 p, int p3)
{
  if (self->unka0 == 0) {
    int m = self->kind;
    if (m == 1 || m == 23 || m == 24 || m == 25 || m == 11 || m == 15) {
      if (self->state != 3) {
        self->state = 3;
        self->stateChanged = 1;
      }
      self->unk42c = DAT_003386b0->deep->unk58;
    } else {
      if (self->state != 2) {
        self->state = 2;
        self->stateChanged = 1;
      }
      self->unk42c = DAT_003386b0->deep->unk58;
      self->vec440 = Scale(p, DAT_002f2a44[self->kind]);
      float a = (float)FUN_0000b16c((double)DAT_002f29dc[self->kind]);
      float b = (float)FUN_0000b16c((double)self->vec440.y);
      if (a > b)
        self->vec440.y = DAT_002f29dc[self->kind];
      else
        self->vec440.y = -self->vec440.y;
    }
  } else {
    Mat4 mat = DAT_002bc410;
    FUN_00228600(self, p3);
    if (self->kind == 13) {
      mat.r3.x = self->pos.x;
      mat.r3.y = self->pos.y;
      mat.r3.z = self->pos.z;
      mat.r3.w = self->pos.w;
      FUN_000ce754(DAT_003386b0->mid->unk44, &mat, 60, 3500.0f, 1.0f, 1, 0.0f);
    } else if (self->kind == 18) {
      mat.r3.x = self->pos.x;
      mat.r3.y = self->pos.y;
      mat.r3.z = self->pos.z;
      mat.r3.w = self->pos.w;
      FUN_000ce754(DAT_003386b0->mid->unk44, &mat, 61, 3500.0f, 1.0f, 1, 0.0f);
    }
  }
}
