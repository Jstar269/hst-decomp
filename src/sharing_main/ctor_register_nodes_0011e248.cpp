/* HSTMATCH module=hstp_trans_main.prx start=0x0011e248 end=0x0011e7fc symbol=FUN_0011e248 lang=c++ */
/* Hand-written reconstruction from the disassembly (started from hstgen.py tag v0c); exact match verified; names and types await human review. */
/* Idioms: Wrap1/Wrap2 use real virtual inheritance (derived-to-base `Node *n = self->f58;` is the null-checked load of the virtual-base pointer at +0, two hops for Wrap2); Node1/Node4 are `new T` with an INLINE ctor (beqz v0; move s1,v0); PushBack(vec, ptr, Tag) has an unused by-value Tag parameter plus Tag() for the out-of-line grow, which gives retail's 128-byte frame (two hidden slots per inlined call); the matrix constant is copied as a whole Mat4 into the first node. */
struct Tag {};
struct Vec4 {
  float x, y, z, w;
};
struct Mat4 {
  Vec4 r0, r1, r2, r3;
};
struct Base0 {
  void *vt;
  char pad[0x2c];
};
struct Node : Base0, Mat4 {
  Node *parent;
  int index;
};
extern "C" void FUN_0011e8a8(void *, void *);
extern "C" void FUN_0011e7fc(void *, void *);
extern "C" char DAT_0037ffe4[];
extern "C" char DAT_003b0ec4[];
extern "C" char DAT_003b0f08[];
struct Node1 : Node {
  char padn1[0xd0 - 0x78];
  Node1()
  {
    FUN_0011e8a8(this, DAT_0037ffe4);
    vt = DAT_003b0f08;
  }
};
struct Node4 : Node {
  char padn4[0xe0 - 0x78];
  Node4()
  {
    FUN_0011e7fc(this, DAT_0037ffe4);
    vt = DAT_003b0ec4;
  }
};
void *operator new(unsigned int);
struct Wrap1 : virtual Node {
};
struct Wrap2 : virtual Wrap1 {
};
struct PtrVec {
  Node **data;
  unsigned size;
  unsigned cap;
  Node *&at(unsigned i) { return data[i]; }
  Node *&back() { return at(size - 1); }
};
struct Self {
  void *vptr;
  PtrVec vec1;
  PtrVec vec2;
  char pad1c[0x54 - 0x1c];
  Node *f54;
  Wrap1 *f58;
  Node *f5c;
  Node *f60;
  Wrap2 *f64;
  int f68;
  char pad6c[4];
  int f70;
  float f74;
  float f78;
  unsigned char b7c;
  unsigned char b7d;
  char pad7e[6];
  unsigned char b84;
  char pad85[3];
  int f88;
  PtrVec vec3;
};

extern "C" {
extern char DAT_002cc260[];
extern char DAT_003b0ea4[];
extern void *FUN_00000bcc(unsigned);
extern void FUN_0010873c(Self *);
extern void FUN_00108dac(Self *);
extern void FUN_0010d16c(PtrVec *, Node **, Tag);
extern Wrap1 *FUN_001124f4(void *, int);
extern Node *FUN_0011678c(void *);
extern Wrap2 *FUN_0011d3d0(void *, int);
extern void FUN_00120fbc(PtrVec *, int);
}

static inline void PushBack(PtrVec &v, Node *&o, Tag)
{
  if (v.size < v.cap) {
    v.size++;
    v.back() = o;
  } else {
    FUN_0010d16c(&v, &o, Tag());
  }
}

extern "C" Self *FUN_0011e248(Self *self)
{
  FUN_0010873c(self);
  self->vptr = DAT_003b0ea4;
  self->f54 = 0;
  self->f58 = 0;
  self->f5c = 0;
  self->f60 = 0;
  self->f68 = 0;
  self->f70 = 0;
  self->f74 = 1.0f;
  self->f78 = 1.0f;
  self->b7c = 0;
  self->b7d = 0;
  self->b84 = 0;
  self->f88 = 0;
  self->vec3.data = 0;
  self->vec3.size = 0;
  self->vec3.cap = 0;

  Node *p1 = new Node1;
  self->f60 = p1;
  Node *local_4 = self->f60;
  local_4->index = self->vec1.size;
  PushBack(self->vec1, local_4, Tag());
  PushBack(self->vec2, local_4, Tag());

  Node *p2 = (Node *)FUN_00000bcc(0x910);
  if (p2 != 0) {
    p2 = FUN_0011678c(p2);
  }
  self->f54 = p2;
  p2->parent = self->f60;
  Node *local_8 = self->f54;
  local_8->index = self->vec1.size;
  PushBack(self->vec1, local_8, Tag());
  PushBack(self->vec2, local_8, Tag());

  Wrap1 *w1 = (Wrap1 *)FUN_00000bcc(0x1b0);
  if (w1 != 0) {
    w1 = FUN_001124f4(w1, 1);
  }
  self->f58 = w1;
  w1->parent = self->f60;
  Node *local_c = self->f58;
  local_c->index = self->vec1.size;
  PushBack(self->vec1, local_c, Tag());
  PushBack(self->vec2, local_c, Tag());

  Node *p4 = new Node4;
  self->f5c = p4;
  p4->parent = self->f60;
  Node *local_10 = self->f5c;
  local_10->index = self->vec1.size;
  PushBack(self->vec1, local_10, Tag());
  PushBack(self->vec2, local_10, Tag());

  Wrap2 *w2 = (Wrap2 *)FUN_00000bcc(0x1c0);
  if (w2 != 0) {
    w2 = FUN_0011d3d0(w2, 1);
  }
  self->f64 = w2;
  w2->parent = self->f54;
  Node *local_14 = self->f64;
  local_14->index = self->vec1.size;
  PushBack(self->vec1, local_14, Tag());
  PushBack(self->vec2, local_14, Tag());

  Mat4 *m = self->vec1.data[0];
  *m = *(const Mat4 *)DAT_002cc260;
  self->vec1.data[0]->r3.x = 240.0f;
  self->vec1.data[0]->r3.y = 136.0f;
  FUN_00108dac(self);
  if (self->vec3.cap < 4) {
    FUN_00120fbc(&self->vec3, 4);
  }
  return self;
}
