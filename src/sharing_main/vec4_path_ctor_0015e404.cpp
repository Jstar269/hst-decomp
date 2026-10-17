/* HSTMATCH module=hstp_trans_main.prx start=0x0015e404 end=0x0015e54c symbol=FUN_0015e404 lang=c++ */
/* Clone of src/eboot/vec4_path_ctor_001522b4.cpp (hstclone.py tag c47): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed Obj/V4 structs, float reads (swc1) from the stream helper, (h >> 12) & 0xf field extract (ext), unsigned h for the sltiu range test with -1 as the then value, indexed loop over the point array; exact match verified; names and types await human review. */
struct V4 { float x, y, z, w; };
struct Obj {
  void *vptr;
  unsigned char b;
  int mask;
  int count;
  V4 *pts;
};
extern char DAT_003b16d8;
extern char DAT_003b1eec;
extern "C" void *FUN_000008d8(void *, void *, int, int, int);
extern "C" void *FUN_00000a90(int);
extern "C" V4 *FUN_00022440(V4 *, V4 *, V4 *);
extern "C" float FUN_0015b014(void *);
extern "C" unsigned short FUN_0015b050(void *);
extern "C" void FUN_00057f98();

extern "C" Obj *FUN_0015e404(Obj *self, void *stream)
{
  self->vptr = &DAT_003b16d8;
  self->b = 0;
  self->vptr = &DAT_003b1eec;
  unsigned h = FUN_0015b050(stream);
  self->count = (h >> 12) & 0xf;
  self->mask = (h & 0xfff) >= 0x800 ? -1 : (h & 0x7ff);
  int n = self->count;
  self->pts = (V4 *)FUN_000008d8(FUN_00000a90(n * 0x10 + 0x10), (void *)FUN_00057f98, 0, 0x10, n);
  for (int i = 0; i < self->count; i++) {
    self->pts[i].x = FUN_0015b014(stream);
    self->pts[i].y = FUN_0015b014(stream);
    self->pts[i].z = FUN_0015b014(stream);
    self->pts[i].w = 1.0f;
    if (i > 0) FUN_00022440(&self->pts[i], &self->pts[i], &self->pts[i - 1]);
  }
  return self;
}
