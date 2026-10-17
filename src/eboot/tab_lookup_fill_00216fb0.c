/* HSTMATCH module=EBOOT.BIN start=0x00216fb0 end=0x0021704c symbol=FUN_00216fb0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-a1) corrected by hand: typed Out/Ent/Res structs and indexed loop over out[i]/ent[i]; exact match verified; names and types await human review. */
typedef struct Res { int a; int pad[7]; int b; } Res;
typedef struct Ent { unsigned char id; char name[32]; } Ent;
typedef struct Out { Res *r; int b; int a; } Out;
extern Res *FUN_001026b8(void *, const char *);

void FUN_00216fb0(Out *out, void **tab, Ent *ent, int n)
{
  int i;
  for (i = 0; i < n; i++) {
    Res *r = FUN_001026b8(tab[ent[i].id], ent[i].name);
    if (r != 0) {
      out[i].r = r;
      out[i].b = r->b;
      out[i].a = r->a;
    }
  }
}
