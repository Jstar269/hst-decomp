/* HSTMATCH module=hstp_trans_main.prx start=0x0026340c end=0x00263580 symbol=FUN_0026340c lang=c++ */
/* Clone of src/eboot/build_view_002530b8.cpp (hstclone.py tag c015707): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review.
   Builds a view object: 4x4 frame from src, stores its last three rows into the object at 0x1d0..0x1fc in
   reverse row order, sets up the 480x272 projection from two floats at src+0x20, then feeds the two
   billboard axes at src+0x30/src+0x40 through the mesh slots at 0,1 and finishes with the pending payload. */
struct Vec4 { float x, y, z, w; };
extern "C" void FUN_00263580(Vec4 *out, Vec4 *b);
extern "C" void FUN_00022540(Vec4 *dst, Vec4 *src);
extern "C" void FUN_0005c85c(void *o, float, float, float, float, float, float);
extern "C" void FUN_0005d42c(void *o, int i, Vec4 *v);
extern "C" void FUN_0005d4fc(void *o, int i, void *p);
extern "C" void FUN_0005d408(void *o, void *p);
extern "C" void FUN_0005c8e0(void *o);

extern "C" void FUN_0026340c(char *src, char *dst)
{
  Vec4 frame[4];
  Vec4 a, b, c, d;

  FUN_00263580(frame, (Vec4 *)src);
  *(Vec4 *)(dst + 0x1d0) = frame[3];
  *(Vec4 *)(dst + 0x1e0) = frame[2];
  *(Vec4 *)(dst + 0x1f0) = frame[1];
  FUN_0005c85c(dst, 0.0f, 0.0f, 480.0f, 272.0f, *(float *)(src + 0x20), *(float *)(src + 0x24));
  a = *(Vec4 *)(src + 0x30);
  b = *(Vec4 *)(src + 0x40);
  FUN_00022540(&c, &a);
  c.w = 0.0f;
  FUN_0005d42c(dst, 0, &a);
  FUN_0005d4fc(dst, 0, src + 80);
  FUN_00022540(&d, &b);
  d.w = 0.0f;
  FUN_0005d42c(dst, 1, &b);
  FUN_0005d4fc(dst, 1, src + 96);
  FUN_0005d408(dst, src + 112);
  FUN_0005c8e0(dst);
}
