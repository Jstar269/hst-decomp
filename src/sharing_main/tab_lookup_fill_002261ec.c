/* HSTMATCH module=hstp_trans_main.prx start=0x002261ec end=0x00226298 symbol=FUN_002261ec lang=c99 */
/* Clone of src/eboot/tab_lookup_fill_002171e8.c (hstclone.py tag u5fr3s): addresses substituted; exact match verified; names and types await human review. */
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

extern Res *FUN_00108124(void *, const char *);

void FUN_002261ec(Out *out, void **tab, Ent *ent, int n)
{
  int i;
  for (i = 0; i < n; i++) {
    Res *r = FUN_00108124(tab[ent[i].id], ent[i].name);
    if (r != 0) {
      ResChild *child = r->sub->items[ent[i].idx];
      out[i].item = child;
      out[i].b = child->b;
    }
  }
}
