/* HSTMATCH module=EBOOT.BIN start=0x00258a68 end=0x0025950c symbol=FUN_00258a68 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified (matching idioms: SetPos takes its offset by const reference so the offset load stays inside the null test; the id count is an explicit goto loop with a separate unsigned counter; the entry-kind test is a switch with case 1 before 'case 3: default:'; IsNull as !(p != 0) in a bool helper, as in FUN_0025950c); names and types await human review. */
extern char DAT_002c0e18[];
extern char DAT_002c0e1c[];
extern char DAT_002c0e20[];
extern char DAT_002fcc74[];

enum { ENTRY_COUNT = 4, ENTRY_COUNT_SHORT = 2, ID_COUNT = 4, ID_END = 0xff };

/* Game flag bits that give the level written to the sub object (bit 18 highest). */
enum { GAME_FLAG_TIER1 = 0x10000, GAME_FLAG_TIER2 = 0x20000, GAME_FLAG_TIER3 = 0x40000 };

struct Hdr { char pad[8]; int count; };
struct Row { const char **strs; int count; int pad; };
struct Bank { int pad0; int loaded; Hdr *hdr; Row *rows; };
struct Widget { char pad[0x24]; int unk24; int unk28; char pad2[0xf8 - 0x2c]; const char *text; char pad3[0x138 - 0xfc]; int dirty; };
struct Node { char pad[0xe]; unsigned short flags; };

extern "C" {
Bank *FUN_0018c9f4(int);
void FUN_0010d4a8(Widget *);
int FUN_00014934(const char *, const char *);
void FUN_00255d74(void *, int, int);
void FUN_00255ec8(void *, int, int, bool);
void FUN_0025604c(void *, int, int);
void *FUN_00258608(void *, int, int);
void FUN_001d61e4(void *);
void FUN_00114fb8(void *);
void FUN_001d7690(void *, int);
void FUN_001d2124(Widget *);
void FUN_0025950c(Widget *, const char *, int, int);
}

/* String `idx` of group `group` in a text bank; fallback strings for an unloaded bank or an out-of-range group or index. */
static inline const char *Text(Bank *b, int group, int idx)
{
  if (b->loaded == 0) return DAT_002c0e20;
  if (group < 0 || group >= b->hdr->count) return DAT_002c0e1c;
  if (idx < 0 || idx >= b->rows[group].count) return DAT_002c0e18;
  return b->rows[group].strs[idx];
}

static inline bool IsNull(const char *p) { return !(p != 0); }

/* Set a widget's text and mark it dirty; notify (FUN_0010d4a8) unless the text is unchanged and it was already dirty. */
static inline void SetText(Widget *w, const char *s)
{
  int notify = 1;
  int changed = 1;
  int bad = 1;
  if (!IsNull(w->text) && !IsNull(s)) bad = 0;
  if (bad == 0 && FUN_00014934(w->text, s) == 0) changed = 0;
  if (changed == 0) {
    if (w->dirty == 1) notify = 0;
  }
  w->text = s;
  w->dirty = 1;
  if (notify) FUN_0010d4a8(w);
}

/* Set both range words of a widget to v + off (does nothing for a null widget). */
static inline void SetPos(Widget *w, int v, const int &off)
{
  if (w != 0) {
    int x = v + off;
    w->unk24 = x;
    w->unk28 = x;
  }
}

struct Entry {
  char pad0[0x40];
  short unk40;
  char pad42[0x4e - 0x42];
  unsigned char kind;
  char pad4f[0x60 - 0x4f];
  unsigned short unk60;
  char pad62[0xa7 - 0x62];
  unsigned char unka7;
  char pada8[0x10c - 0xa8];
  char name[0x140 - 0x10c];
  unsigned char unk140;
  unsigned char useDefault;
  char pad142[0x458 - 0x142];
};

struct Game {
  int unk0;
  int unk4;
  char pad8[0x70 - 8];
  unsigned flags;
  char pad74[0x90 - 0x74];
  unsigned char active[4];
  char pad94[0x1aa0 - 0x94];
  Entry entries[4];
};

struct EntryUi {
  Widget *widget0;
  char pad4[0xc - 4];
  Node *flags_node;
  Widget *item10[5];
  char pad24[0x80 - 0x24];
  Widget *widget80;
  char pad84[0xa4 - 0x84];
};

struct Self {
  char pad0[0x150];
  unsigned char unk150[4];
  char pad154[0x15c - 0x154];
  int vals[10][4];
  int ids[4][4];
  char pad23c[0x270 - 0x23c];
  char sub[0x288 - 0x270];
  EntryUi ui[3];
  char pad474[0x500 - 0x474];
  int unk500;
  int unk504;
  char pad508[0x520 - 0x508];
  int mode[4];
  char pad530[0x544 - 0x530];
  int active_index;
  unsigned char same[4];
  char pad54c[0x590 - 0x54c];
  Widget *name_widget[4];
  Widget *slot_widget[4][4];
  Widget *widget5e0[4];
  Widget *widget5f0[4];
  Widget *widget600[4];
  Widget *widget610[4];
  Widget *widget620[4];
  char pad630[0x640 - 0x630];
  Game *game;
  unsigned char two_entries;
};

/* Refresh the per-entry widgets (name, positions, level, id icons, texts) of the first four entries, or two when two_entries is set. */
extern "C" void FUN_00258a68(Self *self)
{
  for (int i = 0; i < (self->two_entries == 0 ? ENTRY_COUNT : ENTRY_COUNT_SHORT); i++) {
    Entry *e = &self->game->entries[i];
    const char *name;
    if (e->useDefault != 0)
      name = Text(FUN_0018c9f4(0x13), 0, 2);
    else
      name = e->name;
    Widget *w = self->name_widget[i];
    w->text = name;
    w->dirty = 1;
    FUN_0010d4a8(w);

    SetPos(self->ui[i].widget0, self->game->entries[i].unk140, self->unk500);

    unsigned flags = self->game->flags;
    int level;
    if (flags & GAME_FLAG_TIER3) level = 3;
    else if (flags & GAME_FLAG_TIER2) level = 2;
    else if (flags & GAME_FLAG_TIER1) level = 1;
    else level = 0;
    char c;
    switch (level) {
    case 1: c = 1; break;
    case 2: c = 15; break;
    case 3: c = 30; break;
    default: c = self->vals[9][i]; break;
    }
    FUN_00255d74(self->sub, i, c);
    int v = self->vals[0][i];
    FUN_00255ec8(self->sub, i, v, i != 0 && v < 15 && self->game->unk4 != 1);

    SetPos(self->ui[i].item10[0], self->vals[1][i], self->unk504);
    SetPos(self->ui[i].item10[1], self->vals[2][i], self->unk504);
    SetPos(self->ui[i].item10[2], self->vals[3][i], self->unk504);
    SetPos(self->ui[i].item10[3], self->vals[4][i], self->unk504);
    SetPos(self->ui[i].item10[4], self->vals[5][i], self->unk504);

    int j;
    int n;
    for (unsigned k = 0; k < ID_COUNT; k++) {
      if (self->ids[i][k] == ID_END) {
        n = k;
        goto found;
      }
    }
    n = ID_COUNT;
  found:
    for (j = 0; j < ID_COUNT; j++) {
      int id = self->ids[i][j];
      bool small = id < 13;
      const char *s;
      if (j < n) {
        if (id >= 14) id -= 14;
        s = Text(FUN_0018c9f4(11), 3, id);
      } else {
        s = 0;
      }
      if (s == 0 || (self->mode[i] != 1 && self->mode[i] != 2)) {
        FUN_001d61e4(FUN_00258608(self->sub, i, j + 20));
        FUN_001d61e4(FUN_00258608(self->sub, i, j + 16));
      } else {
        FUN_00114fb8(FUN_00258608(self->sub, i, j + 20));
        FUN_001d7690(FUN_00258608(self->sub, i, j + 20), !small);
        FUN_001d2124(self->slot_widget[i][j]);
        FUN_0025950c(self->slot_widget[i][j], s, 1, 0);
      }
    }

    e = &self->game->entries[i];
    const char *s;
    switch (e->kind) {
    case 1:
      s = Text(FUN_0018c9f4(7), 0, e->unk60);
      break;
    case 3:
    default:
      s = Text(FUN_0018c9f4(12), 0, e->unk40);
      break;
    }
    if (self->widget5e0[i] != 0) SetText(self->widget5e0[i], s);

    s = Text(FUN_0018c9f4(11), 1, self->vals[7][i]);
    if (self->widget5f0[i] != 0) SetText(self->widget5f0[i], s);

    FUN_0025604c(self->sub, i, self->game->entries[i].unka7);

    int off = self->vals[6][i];
    const char *a = Text(FUN_0018c9f4(13), 0, self->vals[8][i]);
    const char *b = Text(FUN_0018c9f4(13), 1, self->vals[8][i]);
    bool eq = FUN_00014934(a, b) == 0;
    self->same[i] = eq;
    Widget *t = self->ui[i].widget80;
    if (t != 0) t->unk24 = t->unk28 - off;
    if (eq) {
      if (self->widget610[i] != 0) SetText(self->widget610[i], DAT_002fcc74);
      if (self->widget620[i] != 0) SetText(self->widget620[i], b);
    } else {
      if (self->widget610[i] != 0) SetText(self->widget610[i], b);
      if (self->widget620[i] != 0) SetText(self->widget620[i], DAT_002fcc74);
    }
    self->unk150[i] = (self->ui[i].flags_node->flags & 3) != 0;
    if (self->game->active[i] != 0) self->active_index = i;
  }
}
