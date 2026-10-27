/* HSTMATCH module=hstp_trans_main.prx start=0x001dba30 end=0x001dbaac symbol=FUN_001dba30 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* True when the object has a current item (index 0xe8 in range of the item array at 0x4c/0x50 and the slot
   non-null) and FUN_00298b14 accepts that item. Current() is the getter retail also emits out of line just before
   this function (FUN_001db9e8, same body); here it is inlined as a const member, which is why retail re-reads the
   index for the call argument (type-keyed CSE: a non-const getter shares the first load). Names provisional. */
struct Item;
extern "C" bool FUN_00298b14(Item *);

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

extern "C" bool FUN_001dba30(Obj *o)
{
  return o->Current() != 0 && FUN_00298b14(o->items[o->idx]);
}
