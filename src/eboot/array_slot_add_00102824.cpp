/* HSTMATCH module=EBOOT.BIN start=0x00102824 end=0x00102958 symbol=FUN_00102824 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag from inputs/generated/FUN_00102824.c) corrected by hand: C++ with trailing unused empty False parameter; loop-continue flag as int; readability pass; exact match verified; names and types await human review. */
// matching idioms: trailing unused empty `False` by-value parameter (retail frame is 16 bytes larger); `more = (p == end) ^ 1` flag instead of `!(p == end)` (C++ bool would add andi); declare `i` before `src` for the s-register order.
#include "hst/types.h"

enum { SLOT_COUNT = 50, NAME_SIZE = 65 }; /* slots in the table, bytes per name */

/* Entry whose id and name are copied into the first free slot. */
struct SlotEntry {
  char pad00[0x54];
  int id;            /* 0x54 */
  char unk58;        /* 0x58 */
  char name[NAME_SIZE]; /* 0x59 */
};

/* Array of entry pointers: element count at +8. */
struct EntryList {
  int unk0;          /* 0x0 */
  int *items;        /* 0x4 array of SlotEntry pointers (typed int * so the end test is not folded) */
  int count;         /* 0x8 */
};

extern "C" int DAT_0033b394[SLOT_COUNT]; /* slot ids, 0 = free */
extern "C" u8 DAT_0033a6e0[SLOT_COUNT][NAME_SIZE]; /* slot names */
extern "C" int DAT_0033b45c;             /* slots in use */
extern "C" u8 DAT_002d8a28;
extern "C" void FUN_000114c0(void *, int, int);
extern "C" void FUN_000149a8(void *, void *);
extern "C" void FUN_00014788(void *, u8 *);

struct False {};
/* Add every entry of the list to the table of slots, each into the first free slot (if any). */
extern "C" void FUN_00102824(EntryList *list, False)
{
  unsigned int i;
  unsigned char *src;
  SlotEntry **p;
  SlotEntry *e;
  int id;
  unsigned char *dst;
  int more;

  p = (SlotEntry **)list->items;
  more = (p == (SlotEntry **)list->items + list->count) ^ 1;
  while (more) {
    e = *p;
    id = e->id;
    src = (unsigned char *)e->name;
    if (DAT_0033b45c == 0) {
      FUN_000114c0(DAT_0033b394,0,SLOT_COUNT * 4);
    }
    for (i = 0; i < SLOT_COUNT; i++) {
      if (DAT_0033b394[i] == 0) {
        dst = DAT_0033a6e0[i];
        FUN_000149a8(dst,src);
        FUN_00014788(dst,&DAT_002d8a28);
        DAT_0033b394[i] = id;
        DAT_0033b45c = DAT_0033b45c + 1;
        break;
      }
    }
    p = p + 1;
    more = (p == (SlotEntry **)list->items + list->count) ^ 1;
  }
}
