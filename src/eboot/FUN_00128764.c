/* HSTMATCH module=EBOOT.BIN start=0x00128764 end=0x0012883c symbol=FUN_00128764 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Near-miss wip (lane cx5, unreviewed) corrected by hand: the w clamp is a ternary assignment followed by the z load (the if/else form duplicated the z load into both arms in the wrong order); exact match verified; names and types await human review. */
typedef struct { float x, y, z, w; } Vec4;
typedef struct { char pad[0x1a0]; Vec4 v; Vec4 out; } Object;
extern float DAT_002da3d4;
extern float DAT_002da3e4;
extern void FUN_00022418(Vec4 *, Vec4 *, Vec4 *);

void FUN_00128764(Object *self)
{
  Vec4 temp;
  float w, z, y, x, limit;
  temp.x = 0.0f;
  temp.y = DAT_002da3d4;
  temp.z = 0.0f;
  temp.w = 0.0f;
  FUN_00022418(&self->v, &self->v, &temp);
  limit = -DAT_002da3e4;
  w = self->v.w;
  w = (w > 0.0f) ? w : 0.0f;
  z = self->v.z;
  z = (z > 0.0f) ? z : 0.0f;
  y = self->v.y;
  y = (y > limit) ? y : limit;
  x = self->v.x;
  x = (x > 0.0f) ? x : 0.0f;
  self->v.x = x;
  self->v.y = y;
  self->v.z = z;
  self->v.w = w;
  FUN_00022418(&self->out, &self->out, &self->v);
}
