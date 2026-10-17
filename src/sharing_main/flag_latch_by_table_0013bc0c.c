/* HSTMATCH module=hstp_trans_main.prx start=0x0013bc0c end=0x0013bc98 symbol=FUN_0013bc0c lang=c99 */
/* Clone of src/eboot/flag_latch_by_table_00130654.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_003e4915;
extern char DAT_003e4916;

struct Ent { char pad[0x58]; int idx; };
struct Obj { char pad0[0x80]; struct Ent *ent; char pad1[8]; int mode; char pad2[0xa4]; unsigned char flag; };

unsigned char FUN_0013bc0c(struct Obj *p)
{
  int off;
  if (p->mode == 1 && p->ent != 0) {
    off = p->ent->idx * 0x58;
    if ((&DAT_003e4915)[off] == 1 || (&DAT_003e4916)[off] == 1 ||
        (&DAT_003e4915)[off] == 2 || (&DAT_003e4916)[off] == 2) {
      p->flag = 1;
    }
  }
  return p->flag;
}
