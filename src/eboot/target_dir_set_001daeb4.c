/* HSTMATCH module=EBOOT.BIN start=0x001daeb4 end=0x001dafe8 symbol=FUN_001daeb4 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Vec3 { float x; float y; float z; };
struct Vec4 { float x; float y; float z; float w; };

struct Row {
  unsigned char pad00[0x20];
  struct Vec4 v;              /* 0x20 */
  unsigned char pad30[0x10];
};

struct Container {
  unsigned char pad00[0x8c];
  int flags;                  /* 0x8c */
  unsigned char pad90[0xd0];
  struct Row *rows;           /* 0x160 */
};

struct Target {
  unsigned char pad00[0x3c];
  struct Container *owner;    /* 0x3c */
  unsigned char pad40[8];
  int row;                    /* 0x48 */
  unsigned char pad4c[0x84];
  struct Vec4 a;              /* 0xd0 */
  struct Vec3 b;              /* 0xe0 */
  float blend;                /* 0xec */
};

extern void FUN_001dafe8(struct Target *target, struct Vec3 *out, struct Vec4 *in);

void FUN_001daeb4(float blend, struct Target *target, struct Vec4 *param_3)
{
  struct Vec4 vec;
  struct Vec4 frame;
  struct Container *owner;
  struct Row *row;

  vec = *param_3;
  if (vec.w == 0.0f) {
    target->b.x = 0.0f;
    target->b.y = 0.0f;
    target->b.z = 0.0f;
  }
  else if (vec.w == -1.0f) {
    if (target->b.z == 0.0f) {
      target->b.x = 0.0f;
      target->b.y = 0.0f;
      vec.w = 0.0f;
      target->b.z = 0.0f;
    }
  }
  else {
    target->blend = blend;
    vec.w = 1.0f;
    if (target->a.w == 0.0f) {
      owner = target->owner;
      if (owner == 0 || owner->flags == 0) {
        target->b.x = 0.0f;
        target->b.y = 0.0f;
        target->b.z = 0.0f;
      }
      else {
        row = owner->rows + target->row;
        frame.x = row->v.x;
        frame.y = row->v.y;
        frame.z = row->v.z;
        frame.w = row->v.w;
        FUN_001dafe8(target, &target->b, &frame);
      }
    }
  }
  target->a.x = vec.x;
  target->a.y = vec.y;
  target->a.z = vec.z;
  target->a.w = vec.w;
}
