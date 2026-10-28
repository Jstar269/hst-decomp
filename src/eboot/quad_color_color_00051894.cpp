/* HSTMATCH module=EBOOT.BIN start=0x00051894 end=0x00051a10 symbol=FUN_00051894 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct V { float x, y, z, w; };
struct Self { char pad00[40]; void *f40; };
extern "C" void *FUN_0003807c(void *obj, const V *a, const V *b, const V *c, const V *d, const V *col);
extern "C" void FUN_00051894(Self *self, unsigned color,
                             float A, float B, float C, float D,
                             float E, float F, float G, float H, float Z)
{
  V q4, q3, q2, q1;
  q4.x = C; q4.y = D; q4.z = Z; q4.w = 0.0f;
  q3.x = G; q3.y = H; q3.z = Z; q3.w = 0.0f;
  q2.x = A; q2.y = B; q2.z = 1.0f; q2.w = 0.0f;
  q1.x = E; q1.y = F; q1.z = 1.0f; q1.w = 0.0f;
  unsigned char *p = (unsigned char *)&color;
  float cr, cg, cb, ca;
  ca = (float)p[3] / 128.0f;
  cb = (float)p[2] / 255.0f;
  cg = (float)p[1] / 255.0f;
  cr = (float)p[0] / 255.0f;
  V col; col.x = cr; col.y = cg; col.z = cb; col.w = ca;
  self->f40 = FUN_0003807c(self->f40, &q4, &q3, &q2, &q1, &col);
}
