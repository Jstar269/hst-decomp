/* HSTMATCH module=hstp_trans_main.prx start=0x001c142c end=0x001c14ac symbol=FUN_001c142c lang=c99 */
/* Clone of src/eboot/release_resource_slot_001b31ac.c (hstclone.py tag c45): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed structs, bool flag computed as slti then re-tested, one shared join store instead of the duplicated else branch; exact match verified; names and types await human review. */
typedef struct Res { int x; } Res;
typedef struct Obj {
  char pad[0x58];
  Res *tab[1];
} Obj;
typedef struct Holder {
  char pad[0x788];
  int f788;
  char pad1[0x4c];
  int sel;
  unsigned char f7dc;
} Holder;

extern int FUN_00063304(Res *, int);

void FUN_001c142c(Holder **param_1)
{
  Holder *h;
  int idx;
  int ok;
  Res **pp;
  
  h = *param_1;
  idx = h->sel * 2 + 0x16a;
  ok = idx < 0x1da;
  if (ok) {
    ok = ((int *)h)[idx] != 0;
  }
  if (ok) {
    pp = (Res **)&((int *)h)[idx];
    if (*pp != 0) {
      FUN_00063304(*pp, 1);
      *pp = 0;
    }
  }
  h->f788 = 0;
  h->f7dc = 0;
}
