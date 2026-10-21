/* HSTMATCH module=hstp_trans_main.prx start=0x0013a7a0 end=0x0013a948 symbol=FUN_0013a7a0 lang=c++ */
/* Clone of src/eboot/update_camera_state_0012f248.cpp (hstclone.py tag c21sn35s): addresses substituted; exact match verified; names and types await human review. */
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
extern Mgr *DAT_003f3450;
void FUN_00139740(Camera *, int);
void FUN_00139580(Camera *);
void FUN_00139d0c(Camera *, Basis *);
void FUN_00139e7c(Camera *, Basis *);
void FUN_00139bd4(Camera *);
void FUN_0013a450(float, Basis *, void *);
void FUN_00049624(Source *);
void FUN_00049820(Mat *, Source *);
void FUN_00022598(Mat *, void *, Mat *);
float FUN_00049cb4(Source *);
float FUN_00049da8(Source *);
float FUN_00049e34(Source *);

void FUN_0013a7a0(Camera *self)
{
  Basis b;
  Mat local_90;
  switch (self->state) {
  case 0:
    FUN_00139740(self, DAT_003f3450->v37());
    FUN_00139d0c(self, &b);
    FUN_00139e7c(self, &b);
    FUN_00139bd4(self);
    break;
  case 1:
  default:
    FUN_00139580(self);
    FUN_00139d0c(self, &b);
    FUN_00139e7c(self, &b);
    FUN_00139bd4(self);
    break;
  case 2: {
    FUN_00049624(self->src);
    Source *s = self->src;
    char *q = (char *)s->base + 0x30;
    FUN_00049820(&local_90, s);
    FUN_00022598(&b.m, q, &local_90);
    b.f40 = FUN_00049cb4(s) * 57.29578f;
    b.f44 = FUN_00049da8(s);
    b.f48 = FUN_00049e34(s);
    FUN_00139e7c(self, &b);
    break;
  }
  case 3:
    FUN_0013a450(self->t, &b, self->vec100);
    self->t = self->t + 0.02f;
    if (self->t >= 1.0f) {
      self->state = 2;
    }
    FUN_00139e7c(self, &b);
    break;
  }
}
}
