/* HSTMATCH module=EBOOT.BIN start=0x001ca1bc end=0x001ca238 symbol=FUN_001ca1bc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
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
    unsigned short id = record->id;
    FUN_0022aff4(id, Max(wanted, count));
  }
}
