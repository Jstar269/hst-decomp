/* HSTMATCH module=EBOOT.BIN start=0x0012f248 end=0x0012f3f0 symbol=FUN_0012f248 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* State switch of the camera object (0 = query manager, 1/default = follow, 2 = from source object, 3 = blend). Matching idioms: case 1 and default share one body (case 1: default:), the manager call is the 38th declared virtual (vtable offset 156), Basis b is declared before Mat local_90 (slots 80 and 16), and the pointer base+0x30 is computed before the first call (s1 in the delay slot). */
struct Vec4 {
  float x, y, z, w;
} __attribute__((aligned(16)));
struct Mat {
  float m[16];
} __attribute__((aligned(16)));
struct Basis {
  Mat m;
  float f40, f44, f48;
};

struct Source {
  int *base;
};

struct Mgr {
  virtual void v0();
  virtual void v1();
  virtual void v2();
  virtual void v3();
  virtual void v4();
  virtual void v5();
  virtual void v6();
  virtual void v7();
  virtual void v8();
  virtual void v9();
  virtual void v10();
  virtual void v11();
  virtual void v12();
  virtual void v13();
  virtual void v14();
  virtual void v15();
  virtual void v16();
  virtual void v17();
  virtual void v18();
  virtual void v19();
  virtual void v20();
  virtual void v21();
  virtual void v22();
  virtual void v23();
  virtual void v24();
  virtual void v25();
  virtual void v26();
  virtual void v27();
  virtual void v28();
  virtual void v29();
  virtual void v30();
  virtual void v31();
  virtual void v32();
  virtual void v33();
  virtual void v34();
  virtual void v35();
  virtual void v36();
  virtual int v37();
};

struct Camera {
  char pad00[0xf0];
  int state;
  int padf4;
  Source *src;
  char padfc[4];
  char vec100[0x140];
  float t;
};

extern "C" {
extern Mgr *DAT_0034a118;
void FUN_0012e1e8(Camera *, int);
void FUN_0012e028(Camera *);
void FUN_0012e7b4(Camera *, Basis *);
void FUN_0012e924(Camera *, Basis *);
void FUN_0012e67c(Camera *);
void FUN_0012eef8(float, Basis *, void *);
void FUN_00049774(Source *);
void FUN_00049970(Mat *, Source *);
void FUN_00022570(Mat *, void *, Mat *);
float FUN_00049da4(Source *);
float FUN_00049e68(Source *);
float FUN_00049ec4(Source *);

void FUN_0012f248(Camera *self)
{
  Basis b;
  Mat local_90;
  switch (self->state) {
  case 0:
    FUN_0012e1e8(self, DAT_0034a118->v37());
    FUN_0012e7b4(self, &b);
    FUN_0012e924(self, &b);
    FUN_0012e67c(self);
    break;
  case 1:
  default:
    FUN_0012e028(self);
    FUN_0012e7b4(self, &b);
    FUN_0012e924(self, &b);
    FUN_0012e67c(self);
    break;
  case 2: {
    FUN_00049774(self->src);
    Source *s = self->src;
    char *q = (char *)s->base + 0x30;
    FUN_00049970(&local_90, s);
    FUN_00022570(&b.m, q, &local_90);
    b.f40 = FUN_00049da4(s) * 57.29578f;
    b.f44 = FUN_00049e68(s);
    b.f48 = FUN_00049ec4(s);
    FUN_0012e924(self, &b);
    break;
  }
  case 3:
    FUN_0012eef8(self->t, &b, self->vec100);
    self->t = self->t + 0.02f;
    if (self->t >= 1.0f) {
      self->state = 2;
    }
    FUN_0012e924(self, &b);
    break;
  }
}
}
