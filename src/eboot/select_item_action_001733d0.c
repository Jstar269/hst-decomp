/* HSTMATCH module=EBOOT.BIN start=0x001733d0 end=0x001734b8 symbol=FUN_001733d0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: typed structs (entry byte flags unsigned char), Ghidra's bool block written as if (f8 != 0 || fb != 0 || fc != 0) free = 0; else free = 1; then if (free == 0) {release} else {indirect call + FUN_0017d1f8}; exact match verified; names and types await human review. */
typedef struct Entry {
  char pad[8];
  unsigned char f8;
  char pad1[2];
  unsigned char fb;
  unsigned char fc;
} Entry;
typedef struct Rec { Entry **list; int a; int b; } Rec;
typedef struct Sub { char pad[0x59]; unsigned char f59; } Sub;
typedef struct Sel { int pad0; int i; int j; char pad1[0x18 - 0xc]; Rec *tab; } Sel;
typedef struct Obj {
  char pad[0x178];
  Sub *sub;
  char pad1[0x550 - 0x17c];
  int (*fn)(int);
} Obj;
extern void FUN_0017d1f0(Sub *);
extern void FUN_0017d1f8(Sub *, int, int, int);

void FUN_001733d0(Obj *o, Sel *s, int id)
{
  Entry *e = s->tab[s->j].list[s->i];
  int free_;
  if (id == 0x7fff) {
    o->sub->f59 = 0;
    FUN_0017d1f0(o->sub);
  } else if (id != 0x7ffe) {
    if (e->f8 != 0 || e->fb != 0 || e->fc != 0) free_ = 0; else free_ = 1;
    if (free_ == 0) {
      o->sub->f59 = 0;
      FUN_0017d1f0(o->sub);
    } else {
      int r = o->fn(id);
      FUN_0017d1f8(o->sub, r, id, 1);
    }
  }
}
