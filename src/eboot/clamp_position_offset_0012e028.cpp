/* HSTMATCH module=EBOOT.BIN start=0x0012e028 end=0x0012e1b0 symbol=FUN_0012e028 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idioms: the position is clamped with an inline by-value Clamp (v < lo ? lo : (v > hi ? hi : v)); Mat and Vec4 are both aligned(16) so the locals take the slots d (top), m, r in declaration order; the final Vec4 is produced by an inline Add returning by value (retail's scheduled four-float copy). */
struct Vec4 {
  float x, y, z, w;
  Vec4() {}
  Vec4(const Vec4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
} __attribute__((aligned(16)));
struct Mat {
  float m[16];
} __attribute__((aligned(16)));

/* Level bounds the camera focus is kept inside. */
struct Limits {
  char pad[0x1300];
  float xmin, xmax, zmin, zmax;
};
/* Camera: focus point, smoothed target and the eye orbiting it. */
struct CameraObj {
  char pad00[0x70];
  Vec4 focus;
  Vec4 prev_focus;
  Vec4 target;
  Vec4 eye;
  char padb0[0x38];
  float angle_deg;
};

extern "C" {
extern Limits *DAT_0033b574;
extern Mat DAT_002bc410;
extern float DAT_002dade4;
extern float DAT_002daddc;
extern float DAT_002dade0;
void FUN_0002246c(float, Vec4 *, const Vec4 *, const Vec4 *);
void FUN_0004d278(Mat *, Mat *, float);
void FUN_0004d2cc(Mat *, Mat *, float);
Vec4 *FUN_00022548(Vec4 *, const Mat *, const Vec4 *);
Vec4 *FUN_00022418(Vec4 *, const Vec4 *, const Vec4 *);
}

static inline float Clamp(float v, float lo, float hi)
{
  return v < lo ? lo : (v > hi ? hi : v);
}

static inline Vec4 Add(const Vec4 &a, const Vec4 &b)
{
  Vec4 r;
  FUN_00022418(&r, &a, &b);
  return r;
}

/* Clamps the focus to the level bounds, eases the target toward it and places the eye at a rotated offset from the target. */
extern "C" void FUN_0012e028(CameraObj *cam)
{
  cam->prev_focus.x = cam->focus.x;
  cam->prev_focus.y = cam->focus.y;
  cam->prev_focus.z = cam->focus.z;
  cam->prev_focus.w = cam->focus.w;
  Vec4 p = cam->focus;
  p.x = Clamp(p.x, DAT_0033b574->xmin, DAT_0033b574->xmax);
  p.z = Clamp(p.z, DAT_0033b574->zmin, DAT_0033b574->zmax);
  cam->focus = p;
  FUN_0002246c(DAT_002dade4, &cam->target, &cam->focus, &cam->target);
  Vec4 d;  /* offset from the target, rotated below */
  d.x = 0.0f;
  d.y = 0.0f;
  d.z = DAT_002daddc;
  d.w = 0.0f;
  Mat m;
  FUN_0004d278(&m, &DAT_002bc410, DAT_002dade0 * 0.017453292f);
  FUN_0004d2cc(&m, &m, cam->angle_deg * 0.017453292f);
  FUN_00022548(&d, &m, &d);
  cam->eye = Add(cam->target, d);
}
