/* HSTMATCH module=hstp_trans_main.prx start=0x001a3590 end=0x001a3818 symbol=FUN_001a3590 lang=c++ data=0x00388f58 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Places sprites for a panel: one sprite of the first group (< 6) and, depending on kind (10: four, 9: none, else one), sprites of the second group (< 12) whose two colour words get the per-slot base plus the offset; every placed sprite gets its rectangle from the info block (x, y - 3, then x/y plus size * 20). Matching idioms: the slot index `*b + 18` is held in a local (one shared base pointer for the sprite and value arrays, which are 30 entries each), the rectangle size is added without a (short) cast (a cast adds seh), and the per-slot offset is passed as `const int &` so tab[i] is loaded after the visibility call rather than kept in a saved register. Names provisional. */
struct Sprite {
  int f0;
  short x, y, x2, y2;
  char padc[0x24 - 0xc];
  int f24, f28;
};
struct Info {
  int pad0;
  int x;
  int y;
  float w;
  float h;
};
struct Self {
  int pad0;
  Sprite *sprites[30];
  int vals[30];
};
extern "C" void FUN_00105470(Sprite *, int);

static inline void Place(Sprite *s, const Info *p)
{
  s->x = p->x;
  s->y = p->y - 3;
  s->x2 = s->x + (int)(p->w * 20.0f);
  s->y2 = s->y + (int)(p->h * 20.0f);
}

static inline void Slot(Self *self, int *b, const int &add, const Info *info)
{
  if (*b < 12) {
    int i = *b + 18;
    Sprite *s = self->sprites[i];
    FUN_00105470(s, 0);
    int v = self->vals[i] + add;
    s->f24 = v;
    s->f28 = v;
    Place(s, info);
    *b = *b + 1;
  }
}

extern "C" void FUN_001a3590(Self *self, int *a, int *b, int kind, const Info *info)
{
  if (*a < 6) {
    Sprite *s = self->sprites[*a];
    FUN_00105470(s, 0);
    Place(s, info);
    *a = *a + 1;
  }
  if (kind == 10) {
    int tab[4] = {0, 1, 2, 3};
    for (int i = 0; i < 4; i++) Slot(self, b, tab[i], info);
  } else if (kind != 9) {
    Slot(self, b, kind, info);
  }
}
