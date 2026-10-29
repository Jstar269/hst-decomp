/* HSTMATCH module=EBOOT.BIN start=0x002584d0 end=0x00258608 symbol=FUN_002584d0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: structured Obj/Vec4 types, matrix transform branch order, scalar load order; readability pass; exact match verified; names and types await human review. */

struct Vec4 {
  float x;
  float y;
  float z;
  float w;
};

/* Rectangle with a depth value and an optional transform matrix. */
struct Obj {
  int pad0;
  short x1;
  short y1;
  short x2;
  short y2;
  short z;
  short pad1;
  int pad2;
  void *matrix;
};

extern void *FUN_00022548(struct Vec4 *out, void *matrix, const struct Vec4 *in);

/* Return the two corners of the rectangle; when a matrix is set both corners are transformed by it first. */
void FUN_002584d0(struct Obj *self, short *out_x1, short *out_y1, short *out_x2, short *out_y2)
{
  if (self->matrix != 0) {
    struct Vec4 p1;
    struct Vec4 p2;

    float fz = (float)self->z;
    float fy1 = (float)self->y1;
    float fx1 = (float)self->x1;
    p1.w = 1.0f;
    p1.z = fz;
    p1.y = fy1;
    p1.x = fx1;

    float fy2 = (float)self->y2;
    float fx2 = (float)self->x2;
    p2.z = fz;
    p2.w = 1.0f;
    p2.y = fy2;
    p2.x = fx2;

    FUN_00022548(&p1, self->matrix, &p1);
    FUN_00022548(&p2, self->matrix, &p2);

    *out_x1 = (short)(int)p1.x;
    *out_y1 = (short)(int)p1.y;
    *out_x2 = (short)(int)p2.x;
    *out_y2 = (short)(int)p2.y;
  } else {
    *out_x1 = self->x1;
    *out_y1 = self->y1;
    *out_x2 = self->x2;
    *out_y2 = self->y2;
  }
}
