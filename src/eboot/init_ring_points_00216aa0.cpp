/* HSTMATCH module=EBOOT.BIN start=0x00216aa0 end=0x00216bc4 symbol=FUN_00216aa0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* matching idiom: the 0.3926991f angle step is a non-const float local (value-first mul.s and retail's f0/f1 numbering). */
#define RING_POINT_COUNT 16
#define SCREEN_HALF_W 240.0f /* half of the 480x272 screen */
#define SCREEN_HALF_H 136.0f

struct Pt {
  float x;
  float y;
};

struct Sub {
  char pad[0x48];
};

struct Obj {
  unsigned char flag;
  char pad0[3];
  Sub *sub;
  Pt outer[RING_POINT_COUNT];
  Pt inner[RING_POINT_COUNT];
};

extern "C" void *FUN_00000bcc(unsigned);
extern "C" Sub *FUN_00050fc0(Sub *);
extern "C" void FUN_00051398(float, Sub *);
extern "C" void FUN_000513fc(Sub *, int);
extern "C" float FUN_0000bc34(float);
extern "C" float FUN_0000bf34(float);

/* Constructor: create the sub object, then lay two rings of 16 points (an outer one 1.45 times the screen's half size, an inner one of radius 60 x 34) around the screen centre. */
extern "C" Obj *FUN_00216aa0(Obj *self)
{
  self->flag = 0;
  Sub *sub = (Sub *)FUN_00000bcc(sizeof(Sub));
  if (sub != 0) sub = FUN_00050fc0(sub);
  self->sub = sub;
  FUN_00051398(3000.0f, sub);
  FUN_000513fc(self->sub, 1);
  float step = 0.3926991f; /* a sixteenth of a turn */
  for (int i = 0; i < RING_POINT_COUNT; i++) {
    float angle = (float)i * step;
    float s = FUN_0000bc34(angle);
    float c = FUN_0000bf34(angle);
    self->outer[i].x = s * SCREEN_HALF_W * 1.45f + SCREEN_HALF_W;
    self->outer[i].y = c * SCREEN_HALF_H * 1.45f + SCREEN_HALF_H;
    self->inner[i].x = s * 60.0f + SCREEN_HALF_W;
    self->inner[i].y = c * 34.0f + SCREEN_HALF_H;
  }
  return self;
}
