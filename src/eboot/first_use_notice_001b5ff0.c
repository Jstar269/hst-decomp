/* HSTMATCH module=EBOOT.BIN start=0x001b5ff0 end=0x001b6098 symbol=FUN_001b5ff0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: ternary (x >= 0 ? tab[x] : 0) for the if/else assignment, single && condition (owner == cur && played == 0) instead of nested ifs with a duplicated tail load, &DAT_0034179c symbol address, typed structs; readability pass; exact match verified; names and types await human review. */
#include "hst/court_view.h"

#define SOUND_FIRST_USE 0x9b /* sound played the first time the item is used */

/* Item record: two vectors, the event kind and the owner it belongs to. */
typedef struct Item { char pad0[0x10]; char a[0x10]; char b[0x18]; int kind; int pad1; int owner; } Item;
/* Notice object; flag is set once the first-use sound has played. */
typedef struct Notice { char pad[0x7b]; unsigned char played; } Notice;

extern CourtView * DAT_003402a0;
extern char DAT_0034179c;
extern void FUN_001b2bb8(char *, int);
extern void FUN_001b5cb4(Notice *, int, char *, int, char *);

/* Play the first-use sound when the item belongs to the court's current entry, then forward the item to the
   event sound function. */
void FUN_001b5ff0(Notice *notice, Item *item, int vec)
{
  int cur;

  cur = DAT_003402a0->selected >= 0 ? DAT_003402a0->table[DAT_003402a0->selected] : 0;
  if (item->owner == cur && notice->played == 0) {
    FUN_001b2bb8(&DAT_0034179c, SOUND_FIRST_USE);
    notice->played = 1;
  }
  FUN_001b5cb4(notice, item->kind, item->a, vec, item->b);
}
