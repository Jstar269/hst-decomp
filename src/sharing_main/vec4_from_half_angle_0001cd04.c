/* HSTMATCH module=hstp_trans_main.prx start=0x0001cd04 end=0x0001cdb0 symbol=FUN_0001cd04 lang=c99 */
/* Hand-written reconstruction from the disassembly (matching idioms: float locals declared z, y, x; stores through an inline setter that takes the four floats); exact match verified; names and types await human review. */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned char bool;
typedef unsigned long long undefined8;
typedef int code();
#define true 1
#define false 0
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

typedef struct Vec4 { float x, y, z, w; } Vec4;

extern float FUN_0000bc4c(float param_1);
extern float FUN_0000bf4c(float param_1);
extern void FUN_000224c0(float, Vec4 *, Vec4 *);
extern void FUN_00022540(Vec4 *);
static inline void SetQ(Vec4 *q, float x, float y, float z, float w)
{
  q->x = x;
  q->y = y;
  q->z = z;
  q->w = w;
}

void FUN_0001cd04(Vec4 *out, float angle)
{
  Vec4 v;
  Vec4 axis;
  Vec4 res;
  float z, y, x;

  FUN_00022540(&axis);
  v.x = axis.x;
  v.y = axis.y;
  v.z = axis.z;
  axis.w = 0;
  v.w = 0;
  angle *= 0.5f;
  FUN_000224c0(FUN_0000bf4c(angle), &res, &v);
  x = res.x;
  y = res.y;
  z = res.z;
  SetQ(out, x, y, z, FUN_0000bc4c(angle));
}
