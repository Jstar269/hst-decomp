/* HSTMATCH module=EBOOT.BIN start=0x00048f08 end=0x00048f64 symbol=FUN_00048f08 lang=c99 */
typedef struct {
  float x;
  float y;
} Vec2;
typedef struct {
  float x;
  float y;
  float z;
  float w;
} Vec4;

extern float sqrtf(float);

void FUN_00048f08(Vec4 *out, Vec4 *in)
{
  float len = sqrtf(in->x * in->x + in->z * in->z);
  float s = len;
  if (len == 0.0f) {
  } else {
    s = 1.0f / len;
  }
  out->x = in->x * s;
  out->y = 0.0f;
  out->z = in->z * s;
  out->w = 0.0f;
}
// near miss from lane km1 (unreviewed)
