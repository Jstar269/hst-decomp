/* HSTMATCH module=EBOOT.BIN start=0x00255ec8 end=0x0025604c symbol=FUN_00255ec8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idioms: the slot base is formed offset-first from a named `off = slot * 4`; the first slot pointer is
   taken before the first test and the second inside the first `if` (nested ifs, not `&&`). */
extern char DAT_002c0e18[];
extern char DAT_002c0e1c[];
extern char DAT_002c0e20[];
extern char DAT_002fcc74[];

/* Text bank: header with the group count, and per group a string array and its length. */
struct Hdr { char pad[8]; int count; };
struct Row { const char **strs; int count; int pad; };
struct Bank { int pad0; int loaded; Hdr *hdr; Row *rows; };
struct Widget { char pad[0xf8]; const char *text; char pad2[0x138 - 0xfc]; int dirty; };

extern "C" Bank *FUN_0018c9f4(int);
extern "C" void FUN_0010d4a8(Widget *);

/* String idx of group, or a placeholder string when the bank is not loaded or an index is out of range. */
static inline const char *Text(Bank *b, int group, int idx)
{
  if (b->loaded == 0) return DAT_002c0e20;
  if (group < 0 || group >= b->hdr->count) return DAT_002c0e1c;
  if (idx < 0 || idx >= b->rows[group].count) return DAT_002c0e18;
  return b->rows[group].strs[idx];
}

/* Owner with two widget arrays, one entry per slot. */
struct Self {
  char pad[0x2e0];
  Widget *a[4];
  Widget *b[4];
};

/* Sets the texts of the slot's two widgets: with flag the first gets the bank text and the second the shared string;
   otherwise the first gets the shared string and the second the text for idx. */
extern "C" void FUN_00255ec8(Self *self, int slot, int idx, int flag)
{
  int off = slot * 4;
  Self *s4 = (Self *)(off + (int)self);
  Widget **pa = &s4->a[0];
  if (*pa != 0) {
    Widget **pb = &s4->b[0];
    if (*pb != 0) {
      if (flag != 0) {
        const char *s = Text(FUN_0018c9f4(0x13), 0, 0);
        Widget *w = *pa;
        w->text = s;
        w->dirty = 1;
        FUN_0010d4a8(w);
        w = *pb;
        w->text = DAT_002fcc74;
        w->dirty = 1;
        FUN_0010d4a8(w);
      } else {
        const char *s = Text(FUN_0018c9f4(14), 1, idx);
        Widget *w = *pa;
        w->text = DAT_002fcc74;
        w->dirty = 1;
        FUN_0010d4a8(w);
        w = *pb;
        w->text = s;
        w->dirty = 1;
        FUN_0010d4a8(w);
      }
    }
  }
}
