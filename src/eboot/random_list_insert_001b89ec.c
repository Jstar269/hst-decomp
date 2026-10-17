/* HSTMATCH module=EBOOT.BIN start=0x001b89ec end=0x001b8b48 symbol=FUN_001b89ec lang=c99 */
/* Clone of src/sharing_main/random_list_insert_001c66d8.c (hstclone.py tag x1237e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: the two LCG draws as an inline Rand01() helper, the (obj, float) parameter order (the int parameter's `move s0,a0` precedes the jal, the float's `mov.s` fills its slot), and the stack temporaries as typed {item, returned iterator, position iterator} for the list-insert call; exact match verified; names and types await human review. */
/* With probability `chance` (first draw below it), calls 0x1c0ce8 with id 177; then, on a second draw below 0.5, inserts the 16-byte item {0xb7, 0x1e, 0, 0} at the end of the list at +0x3c (size, then the sentinel node at +0x40) through 0x1c72f4. Twin of 0x1c657c (id 176, item 0xb5). */
typedef struct Item { int a, b, c, d; } Item;
typedef struct Node { struct Node *prev, *next; } Node;
typedef struct Iter { Node *node; } Iter;
typedef struct List { int size; Node sentinel; } List;
typedef struct Obj { char pad[0x3c]; List list; } Obj;

extern unsigned int *FUN_001b4e08(void);
extern void FUN_001b2bb8(void *, int);
extern void FUN_001b9608(Iter *, List *, Iter *, Item *);
extern char DAT_0034179c[];

/* uniform float in [0, 1) from the shared 15-bit LCG (seed behind 0x1c2a1c) */
static inline float Rand01(void)
{
  unsigned int *seed = FUN_001b4e08();
  *seed = *seed * 0x343fd + 0x269ec3;
  return (float)((*seed >> 16) & 0x7fff) * (1.0f / 32768.0f);
}

void FUN_001b89ec(Obj *o, float chance)
{
  if (Rand01() < chance) {
    FUN_001b2bb8(DAT_0034179c, 177);
    if (Rand01() < 0.5f) {
      Item item;
      Iter ret;
      Iter pos;
      item.a = 0xb7;
      item.b = 0x1e;
      item.c = 0;
      item.d = 0;
      pos.node = &o->list.sentinel;
      FUN_001b9608(&ret, &o->list, &pos, &item);
    }
  }
}
