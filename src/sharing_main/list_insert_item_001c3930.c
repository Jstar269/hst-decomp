/* HSTMATCH module=hstp_trans_main.prx start=0x001c3930 end=0x001c3974 symbol=FUN_001c3930 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: the stack temporaries as typed {item, returned iterator, position iterator} for the list-insert call (recipe of 0x1c657c); exact match verified; names and types await human review. */
/* Appends the 16-byte item {a, b, this+100, this+100} at the end of the list at +0xf0 (size, then the sentinel node at +0xf4) through 0x1c72f4. */
typedef struct Item { int a, b, c, d; } Item;
typedef struct Node { struct Node *prev, *next; } Node;
typedef struct Iter { Node *node; } Iter;
typedef struct List { int size; Node sentinel; } List;
typedef struct Obj { char pad[0xf0]; List list; } Obj;

extern void FUN_001c72f4(Iter *, List *, Iter *, Item *);

void FUN_001c3930(Obj *o, int a, int b)
{
  Item item;
  Iter ret;
  Iter pos;
  item.a = a;
  item.b = b;
  item.c = (int)((char *)o + 100);
  item.d = (int)((char *)o + 100);
  pos.node = &o->list.sentinel;
  FUN_001c72f4(&ret, &o->list, &pos, &item);
}
