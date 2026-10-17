/* HSTMATCH module=hstp_trans_main.prx start=0x00225fb4 end=0x00226050 symbol=FUN_00225fb4 lang=c99 */
/* Clone of src/eboot/tab_lookup_fill_00216fb0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag gen-a1) corrected by hand: typed Out/Ent/Res structs and indexed loop over out[i]/ent[i]; exact match verified; names and types await human review. */
typedef struct Res { int a; int pad[7]; int b; } Res;
typedef struct Ent { unsigned char id; char name[32]; } Ent;
typedef struct Out { Res *r; int b; int a; } Out;
extern Res *FUN_00108124(void *, const char *);

void FUN_00225fb4(Out *out, void **tab, Ent *ent, int n)
{
  int i;
  for (i = 0; i < n; i++) {
    Res *r = FUN_00108124(tab[ent[i].id], ent[i].name);
    if (r != 0) {
      out[i].r = r;
      out[i].b = r->b;
      out[i].a = r->a;
    }
  }
}
