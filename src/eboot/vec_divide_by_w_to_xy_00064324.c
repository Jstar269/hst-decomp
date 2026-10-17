/* HSTMATCH module=EBOOT.BIN start=0x00064324 end=0x000643e8 symbol=FUN_00064324 lang=c99 */
/* Clone of src/sharing_main/vec_divide_by_w_to_xy_000651e8.c (hstclone.py tag s10170158a4r1e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct { float x, y, z, w; } Vec4;
extern char DAT_0032b1d0;
extern void FUN_00022548(Vec4 *, void *, int);
extern void FUN_00022498(float, Vec4 *, Vec4 *);

int FUN_00064324(int a, float *ox, float *oy)
{
  Vec4 v;
  v.x = 240.0f;
  v.y = 272.0f;
  v.z = 0;
  v.w = 0.0f;
  FUN_00022548(&v, &DAT_0032b1d0, a);
  if (v.w > 0.0f) {
    FUN_00022498(1.0f / v.w, &v, &v);
    *ox = (float)(int)(v.x - 1808.0f);
    *oy = (float)(int)(v.y - 1912.0f);
    return 1;
  }
  return 0;
}
