/* HSTMATCH module=EBOOT.BIN start=0x001afa18 end=0x001afa80 symbol=FUN_001afa18 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Item { char pad[0x24]; int a; int b; };
struct Owner { char pad[0x48]; struct Item *item; };
struct Self { int pad; struct Owner *owner; int arg; };
struct Cfg { char pad[0x3a1]; unsigned char flag; };

extern struct Cfg *FUN_0019d474(void);
extern void FUN_001abe98(int);

void FUN_001afa18(struct Self *self)
{
  struct Owner *o = self->owner;
  struct Cfg *c = FUN_0019d474();
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
  FUN_001abe98(self->arg);
}
