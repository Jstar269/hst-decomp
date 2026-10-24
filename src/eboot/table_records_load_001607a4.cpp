/* HSTMATCH module=EBOOT.BIN start=0x001607a4 end=0x00160998 symbol=FUN_001607a4 lang=c++ */
/* LoadGradeParam: data/common/parameter/grade.csv; see docs/DATA-TABLES.md */
/* Clone of src/sharing_main/table_records_load_0016cd30.cpp (hstclone.py tag s10170158a2r1e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Reads a table through a local reader object (derived class of the FUN_000649c0 base, two sub-objects built with
   FUN_0008c230 and torn down with FUN_00066338) and appends one 20-byte record of five floats per row to a
   vector (inline push_back; the empty Tag argument of the out-of-line grow call is passed by value).
   Matching idioms: the reader is a real C++ class (base class whose constructor stores the vptr, members with
   inline constructors/destructors, destructor storing the vptr) -- written as inline init/exit statements the
   object address is folded into sp offsets instead of living in s0; the record is cleared with an explicit
   memset call. Names provisional. */
inline void *operator new(unsigned, void *p) { return p; }

extern "C" {
extern char DAT_003070bc[];
extern char DAT_002de894[];
extern char DAT_002de8b4[];
extern char DAT_002de8b8[];
extern char DAT_002de8c0[];
extern char DAT_002de8cc[];
extern char DAT_002de8d4[];
extern char DAT_002de8dc[];
extern void FUN_000649c0(void *);
extern void FUN_00064a08(void *, int);
extern void FUN_0008c230(void *);
extern void FUN_00066338(void *, int);
extern int FUN_000651b8(void *, char *, int, int, char *);
extern int FUN_000650e0(void *);
extern float FUN_000655f8(void *, int, char *);
extern void *FUN_000114c0(void *, int, int);
extern void FUN_001658ec(void *, int);
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

extern "C" void FUN_001658a8(RecVec *, const Rec *, Tag);

inline void RecVec::push_back(const Rec &x)
{
  if (size < cap) {
    new (data + size) Rec(x);
    ++size;
  } else {
    FUN_001658a8(this, &x, Tag());
  }
}

struct Str {
  int w[4];
  Str() { FUN_0008c230(this); }
  ~Str() { FUN_00066338(this, 0); }
};

struct Base16 {
  int w[4];
  Base16() {
    FUN_000649c0(this);
    *(char **)this = DAT_003070bc;
  }
  ~Base16() { FUN_00064a08(this, 0); }
};

struct Res : Base16 {
  Str a;
  Str b;
  ~Res() { *(char **)this = DAT_003070bc; }
};

extern "C" void FUN_001607a4(RecVec *v)
{
  Res r;
  if (FUN_000651b8(&r, DAT_002de894, 0, 1, DAT_002de8b4)) {
    int n = FUN_000650e0(&r);
    if (v->cap < (unsigned)(n - 1)) {
      FUN_001658ec(v, n - 1);
    }
    for (int i = 1; i < n; i++) {
      Rec rec;
      FUN_000114c0(&rec, 0, sizeof(Rec));
      rec.a = FUN_000655f8(&r, i, DAT_002de8b8);
      rec.b = FUN_000655f8(&r, i, DAT_002de8c0);
      rec.c = FUN_000655f8(&r, i, DAT_002de8cc);
      rec.d = FUN_000655f8(&r, i, DAT_002de8d4);
      rec.e = FUN_000655f8(&r, i, DAT_002de8dc);
      v->push_back(rec);
    }
  }
}
