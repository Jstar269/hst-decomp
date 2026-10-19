/* HSTMATCH module=hstp_trans_main.prx start=0x00268980 end=0x00268ab8 symbol=FUN_00268980 lang=c99 */
/* Clone of src/eboot/transform_rect_coords_002584d0.c (hstclone.py tag s10172123g4r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: structured Obj/Vec4 types, matrix transform branch order, scalar load order; exact match verified; names and types await human review. */

struct Vec4 {
  float x;
  float y;
  float z;
  float w;
};

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

extern void *FUN_00022570(struct Vec4 *out, void *matrix, const struct Vec4 *in);

void FUN_00268980(struct Obj *param_1, short *param_2, short *param_3, short *param_4, short *param_5)
{
  if (param_1->matrix != 0) {
    struct Vec4 v1;
    struct Vec4 v2;

    float fz = (float)param_1->z;
    float fy1 = (float)param_1->y1;
    float fx1 = (float)param_1->x1;
    v1.w = 1.0f;
    v1.z = fz;
    v1.y = fy1;
    v1.x = fx1;

    float fy2 = (float)param_1->y2;
    float fx2 = (float)param_1->x2;
    v2.z = fz;
    v2.w = 1.0f;
    v2.y = fy2;
    v2.x = fx2;

    FUN_00022570(&v1, param_1->matrix, &v1);
    FUN_00022570(&v2, param_1->matrix, &v2);

    *param_2 = (short)(int)v1.x;
    *param_3 = (short)(int)v1.y;
    *param_4 = (short)(int)v2.x;
    *param_5 = (short)(int)v2.y;
  } else {
    *param_2 = param_1->x1;
    *param_3 = param_1->y1;
    *param_4 = param_1->x2;
    *param_5 = param_1->y2;
  }
}
