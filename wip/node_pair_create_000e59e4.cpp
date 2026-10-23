/* HSTMATCH module=EBOOT.BIN start=0x000e59e4 end=0x000e5b9c symbol=FUN_000e59e4 lang=c++ */
/* NEAR MISS 108/110 words, 98 differ. The colour block is SOLVED by the inlined by-value setter: retail's
   lui 0x4300 + four `sw` into a 16-byte temp, then temp -> argument slot (0x30), then argument slot -> p+0xb0
   is exactly what `p->SetColor(Vec4(128,128,128,128))` produces when Vec4's four-float ctor and a
   `void SetColor(Vec4 v) { col = v; }` member are inlined. Plain `Vec4 v = {..}` gives a static .data copy
   (unplaceable), a float[4] local gives only one copy (90 words), member-by-member stores give 74 words.
   Remaining 2 words: retail's release block tests the pointer THREE times (outer bnez, `beqzl a0` whose delay
   reloads f44, then a `beqzl a0` whose delay holds `sw zero,f40`) and ends with the store duplicated in both
   arms; this literal nested-if form gets 108, the natural `if (p) delete p;` form 106, and `if (p) delete p;`
   with the store outside the if 105. */

struct Vec4 {
  float x, y, z, w;
  Vec4() {}
  Vec4(float a, float b, float c, float d) {
    x = a;
    y = b;
    z = c;
    w = d;
  }
};

struct Node {
  virtual void release(int);
  char pad04[0xac];
  Vec4 col;
  void SetColor(Vec4 v) { col = v; }
};

struct Holder {
  char pad00[0x40];
  Node *f40;
  Node *f44;
  char pad48[0x80 - 0x48];
  int f80;
};

extern "C" void *FUN_00000bcc(int size);
extern "C" Node *FUN_000e3944(Node *, Holder *, int, int);
extern "C" void FUN_0001f21c(Holder *, Node *);

extern "C" void FUN_000e59e4(Holder *self, int t0, int t1, int t2)
{
  Node *p;

  p = self->f40;
  if (p != 0) {
    if (p == 0) {
      self->f40 = 0;
    } else {
      p->release(1);
      self->f40 = 0;
    }
  }
  p = self->f44;
  if (p != 0) {
    if (p == 0) {
      self->f44 = 0;
    } else {
      p->release(1);
      self->f44 = 0;
    }
  }
  p = (Node *)FUN_00000bcc(0xc0);
  if (p != 0)
    p = FUN_000e3944(p, self, t0, t2);
  self->f40 = p;
  p->SetColor(Vec4(128.0f, 128.0f, 128.0f, 128.0f));
  p = (Node *)FUN_00000bcc(0xc0);
  if (p != 0)
    p = FUN_000e3944(p, self, t1, t2);
  self->f44 = p;
  p->SetColor(Vec4(128.0f, 128.0f, 128.0f, 128.0f));
  FUN_0001f21c(self, self->f40);
  FUN_0001f21c(self, self->f44);
  self->f80 = 0;
}
// near miss from lane fm7 (unreviewed)
