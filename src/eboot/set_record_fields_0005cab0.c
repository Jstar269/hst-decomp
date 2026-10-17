/* HSTMATCH module=EBOOT.BIN start=0x0005cab0 end=0x0005cbac symbol=FUN_0005cab0 lang=c99 */
/* Clone of src/sharing_main/set_record_fields_0005d83c.c (hstclone.py tag s10170158a1r3e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct {
  float x, y, z, w;
} Vec4;
typedef struct {
  Vec4 a;
  Vec4 b;
  Vec4 c;
  float d;
  float e;
  float pad[2];
} Rec;
typedef struct {
  char pad0[0x20];
  int count;
  Rec *recs;
} Obj;

static inline void SetA(Obj *o, int idx, const Vec4 *v)
{
  if (idx < o->count) {
    Rec *r = &o->recs[idx];
    r->a.x = v->x;
    r->a.y = v->y;
    r->a.z = v->z;
    r->a.w = v->w;
  }
}

static inline void SetB(Obj *o, int idx, const Vec4 *v)
{
  if (idx < o->count) {
    Rec *r = &o->recs[idx];
    r->b.x = v->x;
    r->b.y = v->y;
    r->b.z = v->z;
    r->b.w = v->w;
  }
}

static inline void SetC(Obj *o, int idx, const Vec4 *v)
{
  if (idx < o->count) {
    Rec *r = &o->recs[idx];
    r->c.x = v->x;
    r->c.y = v->y;
    r->c.z = v->z;
    r->c.w = v->w;
  }
}

static inline void SetD(Obj *o, int idx, float v)
{
  if (idx < o->count) {
    Rec *r = &o->recs[idx];
    r->d = v;
  }
}

static inline void SetE(Obj *o, int idx, float v)
{
  if (idx < o->count) {
    Rec *r = &o->recs[idx];
    r->e = v;
  }
}

void FUN_0005cab0(Obj *self, int idx, const Vec4 *a, const Vec4 *b, const Vec4 *c, float d, float e)
{
  SetA(self, idx, a);
  SetB(self, idx, b);
  SetC(self, idx, c);
  SetD(self, idx, d);
  SetE(self, idx, e);
}
