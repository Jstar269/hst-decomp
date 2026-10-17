/* HSTMATCH module=EBOOT.BIN start=0x00170820 end=0x00170874 symbol=FUN_00170820 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-a2/v0) corrected by hand: struct views for the entry table, local entry pointer `e = t->ents + t->idx`, wrap flag tested `!= 0` with the wrapped value first in both branches; exact match verified; names and types await human review. */
typedef struct Ent_00170820 {
  int f0;
  int count;
  int f8;
} Ent_00170820;

typedef struct Tbl_00170820 {
  char pad000[8];
  int idx;
  char pad00c[0xc];
  Ent_00170820 *ents;
} Tbl_00170820;

int FUN_00170820(int param_1, Tbl_00170820 *t, int cur, int delta, int wrap)
{
  int x = cur + delta;
  Ent_00170820 *e = t->ents + t->idx;
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
