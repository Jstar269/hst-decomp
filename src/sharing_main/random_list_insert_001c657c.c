/* HSTMATCH module=hstp_trans_main.prx start=0x001c657c end=0x001c66d8 symbol=FUN_001c657c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: the two LCG draws as an inline Rand01() helper, the (obj, float) parameter order (the int parameter's `move s0,a0` precedes the jal, the float's `mov.s` fills its slot), and the stack temporaries as typed {item, returned iterator, position iterator} for the list-insert call; exact match verified; names and types await human review. */
/* With probability `chance` (first draw below it), calls 0x1c0ce8 with id 176; then, on a second draw below 0.5, inserts the 16-byte item {0xb5, 0x1e, 0, 0} at the end of the list at +0x3c (size, then the sentinel node at +0x40) through 0x1c72f4. Twin of 0x1c66d8 (id 177, item 0xb7). */
typedef struct Item { int a, b, c, d; } Item;
typedef struct Node { struct Node *prev, *next; } Node;
typedef struct Iter { Node *node; } Iter;
typedef struct List { int size; Node sentinel; } List;
typedef struct Obj { char pad[0x3c]; List list; } Obj;

extern unsigned int *FUN_001c2a1c(void);
extern void FUN_001c0ce8(void *, int);
extern void FUN_001c72f4(Iter *, List *, Iter *, Item *);
extern char DAT_003eaad8[];

/* uniform float in [0, 1) from the shared 15-bit LCG (seed behind 0x1c2a1c) */
static inline float Rand01(void)
{
  unsigned int *seed = FUN_001c2a1c();
  *seed = *seed * 0x343fd + 0x269ec3;
  return (float)((*seed >> 16) & 0x7fff) * (1.0f / 32768.0f);
}

void FUN_001c657c(Obj *o, float chance)
{
  if (Rand01() < chance) {
    FUN_001c0ce8(DAT_003eaad8, 176);
    if (Rand01() < 0.5f) {
      Item item;
      Iter ret;
      Iter pos;
      item.a = 0xb5;
      item.b = 0x1e;
      item.c = 0;
      item.d = 0;
      pos.node = &o->list.sentinel;
      FUN_001c72f4(&ret, &o->list, &pos, &item);
    }
  }
}
