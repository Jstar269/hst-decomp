/* HSTMATCH module=EBOOT.BIN start=0x0027f9b0 end=0x0027fa8c symbol=FUN_0027f9b0 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */

#define ITEM_SIZE 0x28 /* bytes per stored item */

extern "C" {
extern void FUN_00000a00(...);
extern int FUN_0027fa8c(...);
}
struct Item {  virtual void destroy(int); };

/* Item storage: data block, live item count and the index of the first live item. */
struct ItemStore {
  char *data;     /* 0x00 */
  int count;      /* 0x04 */
  int unk08;      /* 0x08 */
  int unk0c;      /* 0x0c */
  int first;      /* 0x10 */
};

/* Deleting destructor: destroys the live items from the back, releases the data block and frees the
   object when delete_flag > 0. */
extern "C" ItemStore * FUN_0027f9b0(ItemStore *self,short delete_flag)
{
  int *begin;
  int *end;

  if (self != (ItemStore *)0x0) {
    begin = (int *)(self->data + self->first * ITEM_SIZE);
    end = begin + self->count * 10;
    if (begin < end) {
      do {
        end = end + -10;
        ((Item *)(end))->destroy(-1);
      } while (begin < end);
      self->count = 0;
    }
    else {
      self->count = 0;
    }
    if ((self != (ItemStore *)0x0) && (FUN_0027fa8c(self), self->data != 0)) {
      FUN_00000a00(self->data);
    }
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
