/* HSTMATCH module=hstp_trans_main.prx start=0x00236614 end=0x0023697c symbol=FUN_00236614 lang=c++ */
/* Clone of src/eboot/motion_state_setup_002270a0.cpp (hstclone.py tag c21sn4s): addresses substituted; exact match verified; names and types await human review. */
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
  int f58;
};
struct Mid {
  char pad0[0x44];
  void *f44;
};
struct Ctx {
  char pad0[0x90];
  Mid *f90;
  char pad1[0x9c - 0x94];
  Deep *f9c;
};

struct Obj {
  char pad0[0x3c];
  int f3c;
  Vec4 v40;
  char pad1[0xa0 - 0x50];
  int fa0;
  char pad2[0x428 - 0xa4];
  int f428;
  int f42c;
  unsigned char f430pad[4];
  unsigned char f434;
  char pad3[0x440 - 0x435];
  Vec4 f440;
};

extern "C" {
extern Ctx *DAT_003e19f0;
extern float DAT_0039ae10[];
extern float DAT_0039ada8[];
extern const Mat4 DAT_002cc260;
void FUN_000224c0(float, Vec4 *, const Vec4 *);
double FUN_0000b184(double);
void FUN_00237b74(Obj *, int);
void FUN_000d2350(void *, Mat4 *, int, float, float, int, float);
}

static inline Vec4 Scale(const Vec4 &v, float s)
{
  Vec4 r;
  FUN_000224c0(s, &r, &v);
  return r;
}

extern "C" void FUN_00236614(Obj *self, Vec4 p, int p3)
{
  if (self->fa0 == 0) {
    int m = self->f428;
    if (m == 1 || m == 23 || m == 24 || m == 25 || m == 11 || m == 15) {
      if (self->f3c != 3) {
        self->f3c = 3;
        self->f434 = 1;
      }
      self->f42c = DAT_003e19f0->f9c->f58;
    } else {
      if (self->f3c != 2) {
        self->f3c = 2;
        self->f434 = 1;
      }
      self->f42c = DAT_003e19f0->f9c->f58;
      self->f440 = Scale(p, DAT_0039ae10[self->f428]);
      float a = (float)FUN_0000b184((double)DAT_0039ada8[self->f428]);
      float b = (float)FUN_0000b184((double)self->f440.y);
      if (a > b)
        self->f440.y = DAT_0039ada8[self->f428];
      else
        self->f440.y = -self->f440.y;
    }
  } else {
    Mat4 mat = DAT_002cc260;
    FUN_00237b74(self, p3);
    if (self->f428 == 13) {
      mat.r3.x = self->v40.x;
      mat.r3.y = self->v40.y;
      mat.r3.z = self->v40.z;
      mat.r3.w = self->v40.w;
      FUN_000d2350(DAT_003e19f0->f90->f44, &mat, 60, 3500.0f, 1.0f, 1, 0.0f);
    } else if (self->f428 == 18) {
      mat.r3.x = self->v40.x;
      mat.r3.y = self->v40.y;
      mat.r3.z = self->v40.z;
      mat.r3.w = self->v40.w;
      FUN_000d2350(DAT_003e19f0->f90->f44, &mat, 61, 3500.0f, 1.0f, 1, 0.0f);
    }
  }
}
