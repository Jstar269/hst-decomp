/* HSTMATCH module=EBOOT.BIN start=0x001cd354 end=0x001cd3d0 symbol=FUN_001cd354 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* True when the object has a current item (index 0xe8 in range of the item array at 0x4c/0x50 and the slot
   non-null) and FUN_00287418 accepts that item. Current() is the getter retail also emits out of line just before
   this function (FUN_001cd30c, same body); here it is inlined as a const member, which is why retail re-reads the
   index for the call argument (type-keyed CSE: a non-const getter shares the first load). Names provisional. */
struct Item;
extern "C" bool FUN_00287418(Item *);

struct Obj {
  char pad0[0x4c];
  Item **items;
  unsigned int count;
  char pad1[0xe8 - 0x54];
  int idx;
  Item *Current() const {
    Item *p;
    Item *r;
    if (0 <= idx && idx < count && (p = items[idx]) != 0)
      r = p;
    else
      r = 0;
    return r;
  }
};

extern "C" bool FUN_001cd354(Obj *o)
{
  return o->Current() != 0 && FUN_00287418(o->items[o->idx]);
}
