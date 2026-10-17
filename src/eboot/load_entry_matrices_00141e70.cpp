/* HSTMATCH module=EBOOT.BIN start=0x00141e70 end=0x001420a4 symbol=FUN_00141e70 lang=c++ */
/* Clone of src/sharing_main/load_entry_matrices_0014d4bc.cpp (hstclone.py tag c17b203): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Loads a placement file into a vector of entries: copies the path into the object, opens the file (0x4cd8c, 16-byte header whose word 3 is the record count), calls 0x152da8 on the vector (its size and an empty tag), and for each 32-byte record
   (position xyz, forward xyz, id, one unused word) starts from the constant matrix DAT_002bc410, writes the position into row 3 and the forward vector into row 2, orthonormalises the rows with the VFPU helpers
   (0x22540 normalise, 0x22520 cross product, w cleared by hand) and appends the entry (id + 64-byte aligned matrix) through the out-of-line push_back 0x14d11c. The file is freed at the end.
   The same code exists at 0x14cee8, 0x14d288 and 0x14d4bc with the vector member at +0x9ec, +0xaf8 and +0xc04 (0x10c apart) and the path 12 bytes behind it.
   Matching idioms: the record is read through a small local reader object (`p += 4` per field; a plain `*p++`, a reference helper or char arithmetic folds the unfolded `addiu v0,v0,4` chain retail keeps), `unsigned i = 0;` declared after the count,
   Vec4 with a user constructor (aligned 16) and Mat4 with four Vec4 members assigned whole from the extern const matrix (pipelined lwc1/swc1 with a fresh lui per word), and `e.m.r3 = e.m.r3;` for the final in-order self copy of row 3. Names provisional. */
struct Tag {};
struct Vec4 {
  float x, y, z, w;
  Vec4() {}
} __attribute__((aligned(16)));
struct Mat4 {
  Vec4 r0, r1, r2, r3;
  Mat4() {}
};
struct Entry {
  int id;
  Mat4 m;
};
struct EntryVec {
  Entry *data;
  unsigned size;
  unsigned cap;
};
struct Self {
  char pad[0xc04];
  EntryVec vec;
  char name[1];
};
extern const Mat4 DAT_002bc410;
extern "C" {
char *FUN_000149a8(char *, const char *);
int *FUN_0004cad0(const char *, int, int, int);
void FUN_000104e0(void *);
void FUN_001474c0(EntryVec *, unsigned, Tag);
void FUN_00141ad0(EntryVec *, const Entry *);
Vec4 *FUN_00022518(Vec4 *, const Vec4 *);
Vec4 *FUN_000224f8(Vec4 *, const Vec4 *, const Vec4 *);
}

struct Reader {
  const char *p;
  float Float() { float v = *(const float *)p; p += 4; return v; }
  int Int() { int v = *(const int *)p; p += 4; return v; }
  void Skip(int n) { p += n; }
};

extern "C" void FUN_00141e70(Self *self, const char *path)
{
  FUN_000149a8(self->name, path);
  int *h = FUN_0004cad0(path, 0, 16, 1);
  if (h != 0) {
    FUN_001474c0(&self->vec, self->vec.size, Tag());
    Reader rd;
    rd.p = (const char *)h;
    rd.Skip(8);
    rd.Int();
    unsigned n = rd.Int();
    unsigned i = 0;
    if (n != 0) {
      do {
        Entry e;
        e.m = DAT_002bc410;
        e.m.r3.x = rd.Float();
        e.m.r3.y = rd.Float();
        e.m.r3.z = rd.Float();
        e.m.r2.x = rd.Float();
        e.m.r2.y = rd.Float();
        e.m.r2.z = rd.Float();
        e.id = rd.Int();
        rd.Skip(4);
        FUN_00022518(&e.m.r1, &e.m.r1);
        e.m.r1.w = 0.0f;
        FUN_000224f8(&e.m.r0, &e.m.r1, &e.m.r2);
        FUN_00022518(&e.m.r0, &e.m.r0);
        e.m.r0.w = 0.0f;
        FUN_000224f8(&e.m.r2, &e.m.r0, &e.m.r1);
        e.m.r3 = e.m.r3;
        FUN_00141ad0(&self->vec, &e);
        i++;
      } while (i < n);
    }
    FUN_000104e0(h);
  }
}
