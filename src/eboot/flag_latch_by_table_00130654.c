/* HSTMATCH module=EBOOT.BIN start=0x00130654 end=0x001306e0 symbol=FUN_00130654 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_0033b5d5;
extern char DAT_0033b5d6;

struct Ent { char pad[0x58]; int idx; };
struct Obj { char pad0[0x80]; struct Ent *ent; char pad1[8]; int mode; char pad2[0xa4]; unsigned char flag; };

unsigned char FUN_00130654(struct Obj *p)
{
  int off;
  if (p->mode == 1 && p->ent != 0) {
    off = p->ent->idx * 0x58;
    if ((&DAT_0033b5d5)[off] == 1 || (&DAT_0033b5d6)[off] == 1 ||
        (&DAT_0033b5d5)[off] == 2 || (&DAT_0033b5d6)[off] == 2) {
      p->flag = 1;
    }
  }
  return p->flag;
}
