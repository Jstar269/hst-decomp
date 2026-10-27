/* HSTMATCH module=hstp_trans_main.prx start=0x001eb5f0 end=0x001eb66c symbol=FUN_001eb5f0 lang=c99 data=0x3939bc */
/* Hand-written reconstruction from the disassembly (adapted from the exact EBOOT twin src/eboot/indexed_table_store_001dd3cc.c: addresses substituted; the six DAT_003939bc.. words are the anonymous .data initialiser of the local table {3,4,5,2,1,0}, placed with data=); exact match verified; names and types await human review. */
extern int DAT_00393988;

typedef struct Dst { char pad[0x24]; int a; int b; } Dst;
typedef struct Src { char pad[0x54]; int idx; char pad2[8]; Dst *dst; } Src;

void FUN_001eb5f0(Src *self)
{
  int tab[6] = { 3, 4, 5, 2, 1, 0 };
  int v = DAT_00393988 + tab[self->idx];
  Dst *d = self->dst;
  d->a = v;
  d->b = v;
}
