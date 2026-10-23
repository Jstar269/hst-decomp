/* HSTMATCH module=EBOOT.BIN start=0x001ca1bc end=0x001ca238 symbol=FUN_001ca1bc lang=c++ */
extern "C" {
extern int FUN_00193118(int handle);
extern void *FUN_0022a930(void);
extern int FUN_0022aff4(unsigned short id, int value);
extern int FUN_0022b010(unsigned short id);
extern int FUN_0022c84c(void);
}

struct ItemRec {
  unsigned char pad00[0x10];
  unsigned short id;          /* 0x10 */
};

struct World {
  unsigned char pad00[0xab44];
  int count;                  /* 0xab44 */
};

static inline const int &Max(const int &a, const int &b)
{
  return b < a ? a : b;
}

extern "C" void FUN_001ca1bc(void)
{
  ItemRec *record;
  World *world;
  int count;
  int wanted;

  record = (ItemRec *)FUN_00193118(FUN_0022c84c());
  if (record != 0) {
    wanted = FUN_0022b010(record->id);
    world = (World *)FUN_0022a930();
    count = world->count + 1;
    FUN_0022aff4(record->id, Max(wanted, count));
  }
}
// NEAR 8 of 31 words, ours 31 words = retail. Structure and every operand match;
// left: retail stores the `count` temporary to 28(sp) *before* `slt at,v1,v0`
// and fills the `beqz` delay with `lhu a0,16(s0)` (the second read of the id),
// ours delays the store into the beqz slot and emits the lhu after the join.
// Ruled out: declaring the count temp after `wanted` (9), inlining `world->count
// + 1` into the Max call (9, and the slots swap), an if-statement Max body (8,
// same), count declared inside the if block (9). `int count; int wanted;` order
// is the one that gives retail's 24(sp)/28(sp) slots.
// near miss from lane fm5 (unreviewed)
