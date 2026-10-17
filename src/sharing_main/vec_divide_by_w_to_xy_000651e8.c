/* HSTMATCH module=hstp_trans_main.prx start=0x000651e8 end=0x000652ac symbol=FUN_000651e8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
// Matching idiom: `if (v.w > 0.0f) { ...; return 1; } return 0;` (a flag variable `ok = v.w > 0.0f` moves the result into s2).
typedef struct { float x, y, z, w; } Vec4;
extern char DAT_003d4510;
extern void FUN_00022570(Vec4 *, void *, int);
extern void FUN_000224c0(float, Vec4 *, Vec4 *);

int FUN_000651e8(int a, float *ox, float *oy)
{
  Vec4 v;
  v.x = 240.0f;
  v.y = 272.0f;
  v.z = 0;
  v.w = 0.0f;
  FUN_00022570(&v, &DAT_003d4510, a);
  if (v.w > 0.0f) {
    FUN_000224c0(1.0f / v.w, &v, &v);
    *ox = (float)(int)(v.x - 1808.0f);
    *oy = (float)(int)(v.y - 1912.0f);
    return 1;
  }
  return 0;
}
