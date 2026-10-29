/* HSTMATCH module=EBOOT.BIN start=0x0027f3cc end=0x0027f480 symbol=FUN_0027f3cc lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed the deleting virtual call and modeled count clearing through an allocator-tagged shrink; readability pass; exact match verified; names and types await human review. */

#define ITEM_SIZE 0x28 /* bytes per stored item */

extern "C" void FUN_00000a00(void *);

struct Item {
  virtual void destroy(int);
};
struct AllocatorTag {};
struct VectorView {
  int *data;
  int size;
  void shrink(int n,AllocatorTag tag) { size -= n; }
};

/* Deleting destructor of an item vector: destroys the items from the back, frees the data block and
   frees the object when delete_flag > 0. */
extern "C" int * FUN_0027f3cc(int *self,short delete_flag)
{
  int remaining;
  Item *item;
  
  if (self != (int *)0x0) {
    remaining = self[1];
    item = (Item *)(*self + remaining * ITEM_SIZE);
    ((VectorView *)self)->shrink(remaining,AllocatorTag());
    for (; remaining != 0; remaining = remaining + -1) {
      item = (Item *)((char *)item - ITEM_SIZE);
      item->destroy(-1);
    }
    if (*self != 0) {
      FUN_00000a00((void *)*self);
    }
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
