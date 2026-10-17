/* HSTMATCH module=hstp_trans_main.prx start=0x0016cd30 end=0x0016cf24 symbol=FUN_0016cd30 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Reads a table through a local reader object (derived class of the FUN_00065884 base, two sub-objects built with
   FUN_0008d97c and torn down with FUN_0006778c) and appends one 20-byte record of five floats per row to a
   vector (inline push_back; the empty Tag argument of the out-of-line grow call is passed by value).
   Matching idioms: the reader is a real C++ class (base class whose constructor stores the vptr, members with
   inline constructors/destructors, destructor storing the vptr) -- written as inline init/exit statements the
   object address is folded into sp offsets instead of living in s0; the record is cleared with an explicit
   memset call. Names provisional. */
inline void *operator new(unsigned, void *p) { return p; }

extern "C" {
extern char DAT_003b0388[];
extern char DAT_00385e50[];
extern char DAT_00385e70[];
extern char DAT_00385e74[];
extern char DAT_00385e7c[];
extern char DAT_00385e88[];
extern char DAT_00385e90[];
extern char DAT_00385e98[];
extern void FUN_00065884(void *);
extern void FUN_000658cc(void *, int);
extern void FUN_0008d97c(void *);
extern void FUN_0006778c(void *, int);
extern int FUN_00066260(void *, char *, int, int, char *);
extern int FUN_00065fa4(void *);
extern float FUN_0006682c(void *, int, char *);
extern void *FUN_000114c0(void *, int, int);
extern void FUN_00171adc(void *, int);
}

struct Tag {};

struct Rec {
  float a, b, c, d, e;
  Rec() {}
  Rec(const Rec &o) : a(o.a), b(o.b), c(o.c), d(o.d), e(o.e) {}
};

struct RecVec {
  Rec *data;
  unsigned size;
  unsigned cap;
  void push_back(const Rec &x);
};

extern "C" void FUN_00171a98(RecVec *, const Rec *, Tag);

inline void RecVec::push_back(const Rec &x)
{
  if (size < cap) {
    new (data + size) Rec(x);
    ++size;
  } else {
    FUN_00171a98(this, &x, Tag());
  }
}

struct Str {
  int w[4];
  Str() { FUN_0008d97c(this); }
  ~Str() { FUN_0006778c(this, 0); }
};

struct Base16 {
  int w[4];
  Base16() {
    FUN_00065884(this);
    *(char **)this = DAT_003b0388;
  }
  ~Base16() { FUN_000658cc(this, 0); }
};

struct Res : Base16 {
  Str a;
  Str b;
  ~Res() { *(char **)this = DAT_003b0388; }
};

extern "C" void FUN_0016cd30(RecVec *v)
{
  Res r;
  if (FUN_00066260(&r, DAT_00385e50, 0, 1, DAT_00385e70)) {
    int n = FUN_00065fa4(&r);
    if (v->cap < (unsigned)(n - 1)) {
      FUN_00171adc(v, n - 1);
    }
    for (int i = 1; i < n; i++) {
      Rec rec;
      FUN_000114c0(&rec, 0, sizeof(Rec));
      rec.a = FUN_0006682c(&r, i, DAT_00385e74);
      rec.b = FUN_0006682c(&r, i, DAT_00385e7c);
      rec.c = FUN_0006682c(&r, i, DAT_00385e88);
      rec.d = FUN_0006682c(&r, i, DAT_00385e90);
      rec.e = FUN_0006682c(&r, i, DAT_00385e98);
      v->push_back(rec);
    }
  }
}
