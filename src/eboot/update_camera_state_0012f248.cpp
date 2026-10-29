/* HSTMATCH module=EBOOT.BIN start=0x0012f248 end=0x0012f3f0 symbol=FUN_0012f248 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* State switch of the camera object (0 = query manager, 1/default = follow, 2 = from source object, 3 = blend). Matching idioms: case 1 and default share one body (case 1: default:), the manager call is the 38th declared virtual (vtable offset 156), Basis basis is declared before Mat srcMat (slots 80 and 16), and the translation pointer base+0x30 is computed before the first call (s1 in the delay slot). */
#include "hst/camera_obj.h"

/* Radians to degrees, and the blend factor added per update in blend mode. */
#define RAD_TO_DEG 57.29578f
#define BLEND_STEP 0.02f

struct Vec4 {
  float x, y, z, w;
} __attribute__((aligned(16)));
struct Mat {
  float m[16];
} __attribute__((aligned(16)));
struct Basis {
  Mat m;
  float angleDeg; /* 0x40 */
  float unk44;
  float unk48;
};

struct CameraSource {
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

extern "C" {
extern Mgr *DAT_0034a118;
void FUN_0012e1e8(CameraObj *, int);
void FUN_0012e028(CameraObj *);
void FUN_0012e7b4(CameraObj *, Basis *);
void FUN_0012e924(CameraObj *, Basis *);
void FUN_0012e67c(CameraObj *);
void FUN_0012eef8(float, Basis *, void *);
void FUN_00049774(CameraSource *);
void FUN_00049970(Mat *, CameraSource *);
void FUN_00022570(Mat *, void *, Mat *);
float FUN_00049da4(CameraSource *);
float FUN_00049e68(CameraSource *);
float FUN_00049ec4(CameraSource *);

void FUN_0012f248(CameraObj *self)
{
  Basis basis;
  Mat srcMat;
  switch (self->state) {
  case CAM_STATE_QUERY_MANAGER:
    FUN_0012e1e8(self, DAT_0034a118->v37());
    FUN_0012e7b4(self, &basis);
    FUN_0012e924(self, &basis);
    FUN_0012e67c(self);
    break;
  case CAM_STATE_FOLLOW:
  default:
    FUN_0012e028(self);
    FUN_0012e7b4(self, &basis);
    FUN_0012e924(self, &basis);
    FUN_0012e67c(self);
    break;
  case CAM_STATE_FROM_SOURCE: {
    FUN_00049774(self->src);
    CameraSource *src = self->src;
    char *translation = (char *)src->base + 0x30;
    FUN_00049970(&srcMat, src);
    FUN_00022570(&basis.m, translation, &srcMat);
    basis.angleDeg = FUN_00049da4(src) * RAD_TO_DEG;
    basis.unk44 = FUN_00049e68(src);
    basis.unk48 = FUN_00049ec4(src);
    FUN_0012e924(self, &basis);
    break;
  }
  case CAM_STATE_BLEND:
    FUN_0012eef8(self->t, &basis, &self->unk100);
    self->t = self->t + BLEND_STEP;
    if (self->t >= 1.0f) {
      self->state = CAM_STATE_FROM_SOURCE;
    }
    FUN_0012e924(self, &basis);
    break;
  }
}
}
