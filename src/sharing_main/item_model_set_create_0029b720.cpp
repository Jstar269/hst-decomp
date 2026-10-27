/* HSTMATCH module=hstp_trans_main.prx start=0x0029b720 end=0x0029b9cc symbol=FUN_0029b720 lang=c++ */
/* Hand-written reconstruction from the disassembly: builds a 16-byte set of three models and one texture from sprintf'd paths (the model ctor FUN_00054130 and its deleting dtor FUN_000541d8, texture ctor FUN_000569a4); exact match verified; names and types await human review. */
struct Model;
struct Tex;
extern "C" void *FUN_00000bcc(unsigned);
extern "C" void FUN_00000a00(void *);
extern "C" void FUN_000143b0(char *, const char *, ...);
extern "C" Model *FUN_00054130(void *, char *, char *, char *, char *, int, int);
extern "C" void FUN_000541d8(Model *, int);
extern "C" Tex *FUN_000569a4(void *, char *, int);
extern char DAT_003a7b4c[];
extern char DAT_003a7b70[];
extern char DAT_003a7b88[];
extern char DAT_003a7b94[];
extern char DAT_003a7bbc[];
extern char DAT_003a7be4[];
extern char DAT_003a7c10[];
extern char DAT_003a7c3c[];

struct Model {
  char pad0[8];
  int f8;
};

struct ItemSet {
  Model *m0;
  Model *m1;
  Model *m2;
  Tex *tex;
  ItemSet() : m0(0), m1(0), m2(0), tex(0) {}
  void *operator new(unsigned n) { return FUN_00000bcc(n); }
};

extern "C" ItemSet *FUN_0029b720(void *self, const char *dir, int b, int c)
{
  char path[256];
  char path2[256];
  char path3[256];
  char images[256];
  char attr[256];
  ItemSet *set = new ItemSet;
  Model *m;

  FUN_000143b0(path, DAT_003a7b4c, dir, c, b, c);
  FUN_000143b0(images, DAT_003a7b70, dir);
  m = (Model *)FUN_00000bcc(0x30);
  if (m) m = FUN_00054130(m, path, images, 0, 0, 0, 3);
  set->m0 = m;
  if (m->f8 == 0) {
    if (m) {
      FUN_000541d8(m, 1);
      set->m0 = 0;
    }
    if (set) {
      delete set;
      set = 0;
    }
    return set;
  }
  FUN_000143b0(attr, DAT_003a7b88, dir);
  FUN_000143b0(path, DAT_003a7b94, dir, c, b, c);
  FUN_000143b0(path2, DAT_003a7bbc, dir, c, b, c);
  m = (Model *)FUN_00000bcc(0x30);
  if (m) m = FUN_00054130(m, path, attr, path2, attr, 0, 0);
  set->m1 = m;
  if (m->f8 == 0 && m) {
    FUN_000541d8(m, 1);
    set->m1 = 0;
  }
  FUN_000143b0(path, DAT_003a7be4, dir, c, b, c);
  m = (Model *)FUN_00000bcc(0x30);
  if (m) m = FUN_00054130(m, path, images, 0, 0, 0, 0);
  set->m2 = m;
  if (m->f8 == 0) {
    if (m) {
      FUN_000541d8(m, 1);
      set->m2 = 0;
    }
  }
  if (set->m2 != 0) {
    FUN_000143b0(path3, DAT_003a7c10, dir, c, b, c);
  } else {
    FUN_000143b0(path3, DAT_003a7c3c, dir, c, b, c);
  }
  Tex *t = (Tex *)FUN_00000bcc(0x10);
  if (t) t = FUN_000569a4(t, path3, 0);
  set->tex = t;
  return set;
}
