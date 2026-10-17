/* HSTMATCH module=EBOOT.BIN start=0x001dd3cc end=0x001dd448 symbol=FUN_001dd3cc lang=c99 data=0x2ebab0 */
/* Ghidra pseudocode (hstgen.py tag v0c) corrected by hand: the six DAT_002ebab0.. words are the anonymous .data initialiser of a local int table {3,4,5,2,1,0} (placed with data=), typed structs for the two objects, the field loads written after the table copy; exact match verified; names and types await human review. */
extern int DAT_002eba7c;

typedef struct Dst { char pad[0x24]; int a; int b; } Dst;
typedef struct Src { char pad[0x54]; int idx; char pad2[8]; Dst *dst; } Src;

void FUN_001dd3cc(Src *self)
{
  int tab[6] = { 3, 4, 5, 2, 1, 0 };
  int v = DAT_002eba7c + tab[self->idx];
  Dst *d = self->dst;
  d->a = v;
  d->b = v;
}
