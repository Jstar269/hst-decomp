/* HSTMATCH module=EBOOT.BIN start=0x002223fc end=0x002224f8 symbol=FUN_002223fc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Rec {
  unsigned char active;
  char pad1[7];
  int age;
  float alpha;
  char pad2[8];
  int x;
  int y;
  float vx;
  float vy;
  float vz;
  float vw;
};

struct Obj {
  char pad[0x20];
  Rec recs[16];
};

extern "C" void *FUN_00022498(float, float *, float *);

extern "C" void FUN_002223fc(Obj *o)
{
  for (int i = 0; i < 16; i++) {
    if (o->recs[i].active) {
      int age = o->recs[i].age + 1;
      o->recs[i].age = age;
      if (age > 20) {
        o->recs[i].active = 0;
      } else if (age > 10) {
        o->recs[i].alpha = 1.0f - ((float)age - 10.0f) / 10.0f;
      } else if (age > 0) {
        o->recs[i].alpha = 1.0f;
      }
      FUN_00022498(0.9f, &o->recs[i].vx, &o->recs[i].vx);
      o->recs[i].x = (int)((float)o->recs[i].x + o->recs[i].vx);
      o->recs[i].y = (int)((float)o->recs[i].y + o->recs[i].vy);
    }
  }
}
