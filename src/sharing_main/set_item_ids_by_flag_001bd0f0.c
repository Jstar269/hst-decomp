/* HSTMATCH module=hstp_trans_main.prx start=0x001bd0f0 end=0x001bd158 symbol=FUN_001bd0f0 lang=c99 */
/* Clone of src/eboot/set_item_ids_by_flag_001afa18.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Item { char pad[0x24]; int a; int b; };
struct Owner { char pad[0x48]; struct Item *item; };
struct Self { int pad; struct Owner *owner; int arg; };
struct Cfg { char pad[0x3a1]; unsigned char flag; };

extern struct Cfg *FUN_001aa91c(void);
extern void FUN_001b9500(int);

void FUN_001bd0f0(struct Self *self)
{
  struct Owner *o = self->owner;
  struct Cfg *c = FUN_001aa91c();
  struct Item **pp = &o->item;
  struct Item *it;
  if (c->flag) {
    it = *pp;
    it->a = 0x29;
    it->b = 0x29;
  } else {
    it = *pp;
    it->a = 0x28;
    it->b = 0x28;
  }
  FUN_001b9500(self->arg);
}
