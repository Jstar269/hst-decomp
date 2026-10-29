/* HSTMATCH module=EBOOT.BIN start=0x00170930 end=0x00170a08 symbol=FUN_00170930 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: bool flags as ints, byte fields as unsigned char behind an inline predicate, range check split into if/else-if, start value kept in its own local (register order); readability pass (names, structs, constants); exact match verified; names and types await human review. */

typedef struct SlotList {
  int unk0;
  int count;                  /* 0x04 number of slots */
} SlotList;

typedef struct SlotEntry {
  char pad0[8];
  unsigned char busy8;        /* 0x08 */
  char pad9[2];
  unsigned char busyb;        /* 0x0b */
  unsigned char busyc;        /* 0x0c */
} SlotEntry;

typedef struct SlotOwner {
  char pad0[0x1d4];
  SlotList *slots;            /* 0x1d4 */
} SlotOwner;

extern SlotEntry * FUN_00179178();

static inline int Free(SlotEntry *e) { if (e->busy8 != 0 || e->busyb != 0 || e->busyc != 0) return 0; return 1; }

/* Steps from `start` by `step` (wrapping back to `start` once past either end) until a free slot is found; returns its index. */
int FUN_00170930(SlotOwner *owner,int start_in,int step)
{
  int cur;
  int wrapped;
  int count;
  int start;
  SlotEntry *entry;
  count = owner->slots->count;
  cur = start_in;
  start = start_in;
  wrapped = 0;
  do {
    cur = cur + step;
    if (cur < 0) { cur = start; wrapped = 1; } else if (cur >= count) { cur = start; wrapped = 1; }
    entry = FUN_00179178(owner,cur);
  } while (!Free(entry) && !wrapped);
  return cur;
}
