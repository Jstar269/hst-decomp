/* HSTMATCH module=EBOOT.BIN start=0x002530b8 end=0x0025322c symbol=FUN_002530b8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review.
   Builds a view object: 4x4 frame from src, stores its last three rows into the object at 0x1d0..0x1fc in
   reverse row order, sets up the 480x272 projection from two floats at src+0x20, then feeds the two
   billboard axes at src+0x30/src+0x40 through the mesh slots at 0,1 and finishes with the pending payload. */
struct Vec4 { float x, y, z, w; };
extern "C" void FUN_0025322c(Vec4 *out, Vec4 *b);
extern "C" void FUN_00022518(Vec4 *dst, Vec4 *src);
extern "C" void FUN_0005bbd4(void *o, float, float, float, float, float, float);
extern "C" void FUN_0005c7a4(void *o, int i, Vec4 *v);
extern "C" void FUN_0005c810(void *o, int i, void *p);
extern "C" void FUN_0005c780(void *o, void *p);
extern "C" void FUN_0005bc58(void *o);

extern "C" void FUN_002530b8(char *src, char *dst)
{
  Vec4 frame[4];
  Vec4 a, b, c, d;

  FUN_0025322c(frame, (Vec4 *)src);
  *(Vec4 *)(dst + 0x1d0) = frame[3];
  *(Vec4 *)(dst + 0x1e0) = frame[2];
  *(Vec4 *)(dst + 0x1f0) = frame[1];
  FUN_0005bbd4(dst, 0.0f, 0.0f, 480.0f, 272.0f, *(float *)(src + 0x20), *(float *)(src + 0x24));
  a = *(Vec4 *)(src + 0x30);
  b = *(Vec4 *)(src + 0x40);
  FUN_00022518(&c, &a);
  c.w = 0.0f;
  FUN_0005c7a4(dst, 0, &a);
  FUN_0005c810(dst, 0, src + 80);
  FUN_00022518(&d, &b);
  d.w = 0.0f;
  FUN_0005c7a4(dst, 1, &b);
  FUN_0005c810(dst, 1, src + 96);
  FUN_0005c780(dst, src + 112);
  FUN_0005bc58(dst);
}
