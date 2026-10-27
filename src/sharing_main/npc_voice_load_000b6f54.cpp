/* HSTMATCH module=hstp_trans_main.prx start=0x000b6f54 end=0x000b7180 symbol=FUN_000b6f54 lang=c++ data=0x0037afd4 */
/* Clone of src/eboot/npc_voice_load_000b3cf4.cpp (hstclone.py tag c162207): addresses substituted; exact match verified; names and types await human review. Data: its string literals (2 strings, 0x0037afd4-0x0037affe) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* LoadNpcVoicePack: data/chara/parameter/npc_voicepack.csv; see docs/DATA-TABLES.md */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Tag {};
struct Name18 { char c[18]; };
struct Vec { Name18 *base; unsigned int count; unsigned int cap; };

struct Sprite;
struct Sub16;

extern "C" void FUN_0008c8c8(void *, int, Tag);
extern "C" {
void FUN_00065884(void *);
void FUN_0008d97c(void *);
int FUN_00066260(Sprite *, const char *, int, int, const char *);
int FUN_00065fa4(Sprite *);
int FUN_000661a8(Sprite *, int, int);
int FUN_00014d64(const char *, const char *);
void FUN_000114c0(void *, int, int);
int FUN_00066038(Sprite *, unsigned int, unsigned int);
void FUN_000b7650(Vec *, Name18 *, Tag);
void FUN_0006778c(void *, int);
void FUN_000658cc(void *, int);
extern int DAT_003b0388;
extern char DAT_0037b000[];
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
    *(char **)this = (char *)&DAT_003b0388;
  }
  ~Base16() { FUN_000658cc(this, 0); }
};

struct Sprite : Base16 {
  Str a;
  Str b;
  ~Sprite() { *(char **)this = (char *)&DAT_003b0388; }
};

extern "C" void FUN_000b6f54(Vec *v)
{
  int j;
  unsigned int r;
  unsigned int q;
  char *p;
  unsigned int i;
  int n;
  int sel;
  Name18 *dst;

  for (i = 0; i < 2; i++) {
    FUN_0008c8c8(&v[i], v[i].count, Tag());
  }
  Sprite spr;
  Name18 name;
  if (FUN_00066260(&spr, "data/chara/parameter/npc_voicepack.csv", 0, 0, ",") != 0) {
    n = FUN_00065fa4(&spr);
    j = 0;
    while (j < n) {
      i = FUN_000661a8(&spr, j, 0);
      sel = !FUN_00014d64((const char *)i, DAT_0037b000);
      j = j + 1;
      FUN_000114c0(&name, 0, 0x12);
      r = 0;
      p = name.c;
      do {
        for (q = 0; q < 3; q++) {
          p[q] = FUN_00066038(&spr, j, q);
        }
        j = j + 1;
        p = p + 3;
      } while (++r < 6);
      if (v[sel].count < v[sel].cap) {
        dst = v[sel].base + v[sel].count;
        if (dst != 0) {
          *dst = name;
        }
        v[sel].count = v[sel].count + 1;
      } else {
        FUN_000b7650(&v[sel], &name, Tag());
      }
    }
  }
}
