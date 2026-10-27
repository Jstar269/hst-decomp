/* HSTMATCH module=hstp_trans_main.prx start=0x00060dc8 end=0x00060f58 symbol=FUN_00060dc8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* vbtexanim.cpp constructor body: vtable DAT_003b033c, cleared texture vector m_Texture (+0x28, pushed through the
   inline push_back whose slow path FUN_0005505c takes an empty tag), the textures of a NUL-terminated name list
   loaded through FUN_0004fdb4 with the DAT_003ba6ac flag cleared around each load, ASSERT(m_Texture.size()) (line
   32, stub FUN_00060f58), the size of the first texture (FUN_000507f0 / FUN_00050848) and a frames*w*h buffer.
   The name walk is an INDEX loop: MWCC strength-reduces it to the pointer s0 initialised in the loop preheader,
   which is where retail copies the parameter (a `while (*names) names++;` walk copies it before the entry test).
   Names provisional. */
struct Tag {};
struct PtrVec;
extern "C" void FUN_0005505c(PtrVec *, void *const *, Tag);
struct PtrVec {
  void **data;
  unsigned size;
  unsigned cap;
  void push_back(void *const &x)
  {
    if (size < cap) {
      size++;
      data[size - 1] = x;
    } else {
      FUN_0005505c(this, &x, Tag());
    }
  }
};

struct TexAnim {
  void *vptr;
  unsigned char f4;
  int f8;
  int fc;
  int f10;
  int f14;
  int f18;
  int width;
  int height;
  int frames;
  PtrVec m_Texture;
  void *buf;
  int f38;
};

extern char DAT_003b033c[];
extern unsigned char DAT_003ba6ac;
extern char DAT_003ba4b0[];
extern char DAT_00376ea8[];
extern char DAT_00376ed4[];
extern char DAT_00376ee8[];
extern "C" void *FUN_0004fdb4(void *, const char *, int, int);
extern "C" int FUN_000507f0(void *, void *, int);
extern "C" int FUN_00050848(void *, void *, int);
extern "C" void *FUN_00000a90(unsigned);
extern "C" void FUN_00060f58(...);

#define ASSERT(c) if (!(c)) { FUN_00060f58(DAT_00376ea8, DAT_00376ed4, DAT_00376ee8, 32); for (;;) {} }

extern "C" TexAnim *FUN_00060dc8(TexAnim *self, const char **names, int p3, int p4, int p5, int p6, int p7)
{
  self->vptr = DAT_003b033c;
  self->m_Texture.data = 0;
  self->m_Texture.size = 0;
  self->m_Texture.cap = 0;
  self->f4 = 0;
  self->f8 = p5;
  self->fc = 0;
  self->f10 = 0;
  self->f14 = p3;
  self->f18 = p4;
  self->width = 480;
  self->height = 272;
  self->frames = p6;
  self->f38 = p7;
  for (int i = 0; names[i]; i++) {
    DAT_003ba6ac = 0;
    void *t = FUN_0004fdb4(DAT_003ba4b0, names[i], 0, 0);
    DAT_003ba6ac = 1;
    self->m_Texture.push_back(t);
  }
  ASSERT(self->m_Texture.size);
  void *t0 = self->m_Texture.data[0];
  self->width = FUN_000507f0(DAT_003ba4b0, t0, 0);
  self->height = FUN_00050848(DAT_003ba4b0, t0, 0);
  self->buf = FUN_00000a90(self->frames * (self->width * self->height));
  return self;
}
