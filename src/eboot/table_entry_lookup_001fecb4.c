/* HSTMATCH module=EBOOT.BIN start=0x001fecb4 end=0x001fed58 symbol=FUN_001fecb4 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Header {
  char pad0[8];
  int count;
} Header;

typedef struct Table {
  char pad0[0xc];
  void **items;
  int count;
} Table;

typedef struct Manager {
  char pad0[4];
  int ready;
  Header *header;
  Table *table;
} Manager;

extern char DAT_002c0e18;
extern char DAT_002c0e1c;
extern char DAT_002c0e20;
extern Manager *FUN_0018c9f4(int);

void *FUN_001fecb4(int param_1)
{
  Manager *m;
  void *r;

  if (param_1 == 0x14) {
    param_1 = 0x10;
  }
  m = FUN_0018c9f4(9);
  if (m->ready == 0) {
    r = &DAT_002c0e20;
  }
  else if (m->header->count < 2) {
    r = &DAT_002c0e1c;
  }
  else if ((param_1 < 0) || (param_1 >= m->table->count)) {
    r = &DAT_002c0e18;
  }
  else {
    r = m->table->items[param_1];
  }
  return r;
}
