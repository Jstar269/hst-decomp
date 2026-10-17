/* HSTMATCH module=hstp_trans_main.prx start=0x0017ca98 end=0x0017caec symbol=FUN_0017ca98 lang=c99 */
/* Clone of src/eboot/clamp_or_wrap_index_00170820.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag gen-a2/v0) corrected by hand: struct views for the entry table, local entry pointer `e = t->ents + t->idx`, wrap flag tested `!= 0` with the wrapped value first in both branches; exact match verified; names and types await human review. */
typedef struct Ent_0017ca98 {
  int f0;
  int count;
  int f8;
} Ent_0017ca98;

typedef struct Tbl_0017ca98 {
  char pad000[8];
  int idx;
  char pad00c[0xc];
  Ent_0017ca98 *ents;
} Tbl_0017ca98;

int FUN_0017ca98(int param_1, Tbl_0017ca98 *t, int cur, int delta, int wrap)
{
  int x = cur + delta;
  Ent_0017ca98 *e = t->ents + t->idx;
  int n = e->count;
  if (x < 0) {
    if (wrap != 0) {
      x = n - 1;
    } else {
      x = 0;
    }
  } else if (x >= n) {
    if (wrap != 0) {
      x = 0;
    } else {
      x = n - 1;
    }
  }
  return x;
}
