/* HSTMATCH module=EBOOT.BIN start=0x0001d0b8 end=0x0001d164 symbol=FUN_0001d0b8 lang=c99 */
/* Clone of src/sharing_main/vec4_from_half_angle_0001cd04.c (hstclone.py tag s10170158a3r1e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (matching idioms: float locals declared z, y, x; stores through an inline setter that takes the four floats); exact match verified; names and types await human review. */

typedef struct Vec4 { float x, y, z, w; } Vec4;

extern float FUN_0000bc34(float param_1);
extern float FUN_0000bf34(float param_1);
extern void FUN_00022498(float, Vec4 *, Vec4 *);
extern void FUN_00022518(Vec4 *);
static inline void SetQ(Vec4 *q, float x, float y, float z, float w)
{
  q->x = x;
  q->y = y;
  q->z = z;
  q->w = w;
}

void FUN_0001d0b8(Vec4 *out, float angle)
{
  Vec4 v;
  Vec4 axis;
  Vec4 res;
  float z, y, x;

  FUN_00022518(&axis);
  v.x = axis.x;
  v.y = axis.y;
  v.z = axis.z;
  axis.w = 0;
  v.w = 0;
  angle *= 0.5f;
  FUN_00022498(FUN_0000bf34(angle), &res, &v);
  x = res.x;
  y = res.y;
  z = res.z;
  SetQ(out, x, y, z, FUN_0000bc34(angle));
}
