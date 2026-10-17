/* HSTMATCH module=hstp_trans_main.prx start=0x00266378 end=0x002664fc symbol=FUN_00266378 lang=c++ */
/* Clone of src/eboot/slot_text_pair_00255ec8.cpp (hstclone.py tag s10170158a1r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idioms: the slot base is formed offset-first from a named `off = slot * 4`; the first slot pointer is
   taken before the first test and the second inside the first `if` (nested ifs, not `&&`). */
extern char DAT_002d10cc[];
extern char DAT_002d10d0[];
extern char DAT_002d10d4[];
extern char DAT_003a57e0[];

struct Hdr { char pad[8]; int count; };
struct Row { const char **strs; int count; int pad; };
struct Bank { int pad0; int loaded; Hdr *hdr; Row *rows; };
struct Widget { char pad[0xf8]; const char *text; char pad2[0x138 - 0xfc]; int dirty; };

extern "C" Bank *FUN_001991d4(int);
extern "C" void FUN_00113a50(Widget *);

static inline const char *Text(Bank *b, int group, int idx)
{
  if (b->loaded == 0) return DAT_002d10d4;
  if (group < 0 || group >= b->hdr->count) return DAT_002d10d0;
  if (idx < 0 || idx >= b->rows[group].count) return DAT_002d10cc;
  return b->rows[group].strs[idx];
}

struct Self {
  char pad[0x2e0];
  Widget *a[4];
  Widget *b[4];
};

extern "C" void FUN_00266378(Self *self, int slot, int idx, int flag)
{
  int off = slot * 4;
  Self *s4 = (Self *)(off + (int)self);
  Widget **pa = &s4->a[0];
  if (*pa != 0) {
    Widget **pb = &s4->b[0];
    if (*pb != 0) {
      if (flag != 0) {
        const char *s = Text(FUN_001991d4(0x13), 0, 0);
        Widget *w = *pa;
        w->text = s;
        w->dirty = 1;
        FUN_00113a50(w);
        w = *pb;
        w->text = DAT_003a57e0;
        w->dirty = 1;
        FUN_00113a50(w);
      } else {
        const char *s = Text(FUN_001991d4(14), 1, idx);
        Widget *w = *pa;
        w->text = DAT_003a57e0;
        w->dirty = 1;
        FUN_00113a50(w);
        w = *pb;
        w->text = s;
        w->dirty = 1;
        FUN_00113a50(w);
      }
    }
  }
}
