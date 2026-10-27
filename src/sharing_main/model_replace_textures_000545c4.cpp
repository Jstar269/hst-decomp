/* HSTMATCH module=hstp_trans_main.prx start=0x000545c4 end=0x00054928 symbol=FUN_000545c4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* model.cpp: renames every texture whose name contains names[0] at its end to names[1], loads the new texture
   and records it in m_TexID/m_TexName, collects the old ids once and releases them afterwards. Matching idioms:
   #pragma opt_strength_reduction off (retail rescales the index each pass); the out-of-line grow call goes
   through an inline Grow taking an unused by-value Tag (one hidden slot per site = retail's frame); the search
   loop reads the size through the const size() getter so push_back's size test reloads it; `int i;` declared
   before the list pointer orders the two spill slots. */
#pragma opt_strength_reduction off
struct Tag {};

template <class T> struct Vec {
  T *data_;
  unsigned size_;
  unsigned cap_;
  unsigned size() const { return size_; }
  void push_back(const T &x);
};

struct Hdr {
  char pad0[8];
  unsigned short f8;
};

struct Grp {
  Hdr *hdr;
};

struct Tex {
  char pad0[0x18];
  char *name;
  int id;
};

struct Data {
  char pad0[0x10];
  char list[4];
};

struct Model {
  char pad0[8];
  Data *data;
  char pad0c[0x14 - 0xc];
  unsigned char loaded;
  char pad15[3];
  Vec<int> m_TexID;
  Vec<char *> m_TexName;
};

extern "C" {
extern char DAT_00376a74[];   /* "assertion \"%s\" failed: file \"%s\", line %d\n" */
extern char DAT_00376aa0[];   /* "m_TexID.size() == 0" */
extern char DAT_00376ab4[];   /* "m_TexName.size() == 0" */
extern char DAT_00376a64[];   /* "model.cpp" */
extern char DAT_003ba4b0[];

void FUN_00054928(...);
void FUN_00048fb8(void);
void FUN_00049020(void);
int FUN_0002e868(void *);
Grp *FUN_0002e678(void *, int);
int FUN_0002e434(Grp *);
Tex **FUN_0002e3f8(Grp *, int);
char *FUN_000149a8(char *, const char *);          /* strcpy */
char *FUN_00014d64(char *, const char *);          /* strstr */
int FUN_00014934(const char *, const char *);      /* strcmp */
int FUN_0004ff3c(void *, char *, int, int, int, int, int, int);
void FUN_0005505c(Vec<int> *, const int *, Tag);
void FUN_00055108(Vec<char *> *, char *const *, Tag);
void FUN_000506b8(void *, int);
void FUN_000550a0(Vec<int> *, int);
}

inline void Grow(Vec<int> *v, const int &x, Tag) { FUN_0005505c(v, &x, Tag()); }
inline void Grow(Vec<char *> *v, char *const &x, Tag) { FUN_00055108(v, &x, Tag()); }

template <class T> inline void Vec<T>::push_back(const T &x)
{
  if (size_ < cap_) {
    ++size_;
    data_[size_ - 1] = x;
  } else {
    Grow(this, x, Tag());
  }
}

#define ASSERT(c, text, line) \
  do { if (!(c)) { FUN_00054928(DAT_00376a74, text, DAT_00376a64, line); for (;;) {} } } while (0)

extern "C" void FUN_000545c4(Model *self, int a1, char **names, int a3)
{
  if (self->data != 0) {
    ASSERT(self->m_TexID.size() == 0, DAT_00376aa0, 392);
    ASSERT(self->m_TexName.size() == 0, DAT_00376ab4, 393);
    Vec<int> ids;
    ids.data_ = 0;
    ids.size_ = 0;
    ids.cap_ = 0;
    FUN_00048fb8();
    int i;
    void *list = self->data->list;
    int n = FUN_0002e868(list);
    for (i = 0; i < n; i++) {
      Grp *grp = FUN_0002e678(list, i);
      int m = FUN_0002e434(grp);
      for (int j = 0; j < m; j++) {
        Tex *tex = *FUN_0002e3f8(grp, j);
        char buf[128];
        FUN_000149a8(buf, tex->name);
        char *p = FUN_00014d64(buf, names[0]);
        if (p != 0 && FUN_00014934(p, names[0]) == 0) {
          FUN_000149a8(p, names[1]);
          FUN_00049020();
          int id = FUN_0004ff3c(DAT_003ba4b0, buf, a1, 0, 0, a3, 0x40, 0);
          self->m_TexID.push_back(id);
          self->m_TexName.push_back(tex->name);
          int old = tex->id;
          for (int k = 0; k < ids.size(); k++) {
            if (old == ids.data_[k]) {
              old = -1;
              break;
            }
          }
          if (old >= 0) ids.push_back(old);
          tex->id = id;
          FUN_00048fb8();
        }
      }
      grp->hdr->f8++;
    }
    FUN_00049020();
    for (int k = 0; k < ids.size_; k++) {
      FUN_000506b8(DAT_003ba4b0, ids.data_[k]);
    }
    self->loaded = 1;
    FUN_000550a0(&ids, 0);
  }
}
