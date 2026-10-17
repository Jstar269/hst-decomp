/* HSTMATCH module=EBOOT.BIN start=0x002171e8 end=0x00217294 symbol=FUN_002171e8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed Out/Ent/Res structs and indexed loop over out[i]/ent[i] with child array lookup; exact match verified; names and types await human review. */

typedef struct ResChild {
  char pad[0x24];
  int b;
} ResChild;

typedef struct ResSub {
  char pad[0x10];
  ResChild **items;
} ResSub;

typedef struct Res {
  char pad[0x20];
  ResSub *sub;
} Res;

typedef struct Ent {
  unsigned char id;
  char name[32];
  unsigned char idx;
} Ent;

typedef struct Out {
  ResChild *item;
  int b;
  char pad[12];
} Out;

extern Res *FUN_001026b8(void *, const char *);

void FUN_002171e8(Out *out, void **tab, Ent *ent, int n)
{
  int i;
  for (i = 0; i < n; i++) {
    Res *r = FUN_001026b8(tab[ent[i].id], ent[i].name);
    if (r != 0) {
      ResChild *child = r->sub->items[ent[i].idx];
      out[i].item = child;
      out[i].b = child->b;
    }
  }
}
