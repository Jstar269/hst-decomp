/* HSTMATCH module=EBOOT.BIN start=0x001fecb4 end=0x001fed58 symbol=FUN_001fecb4 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Header {
  char pad0[8];
  int count;  /* 0x08 */
} Header;

typedef struct Table {
  char pad0[0xc];
  void **items;  /* 0x0c */
  int count;     /* 0x10 */
} Table;

typedef struct Manager {
  char pad0[4];
  int ready;      /* 0x04 */
  Header *header; /* 0x08 */
  Table *table;   /* 0x0c */
} Manager;

enum {
  TABLE_KIND = 9,       /* resource table this lookup reads */
  INDEX_ALIAS_FROM = 0x14,
  INDEX_ALIAS_TO = 0x10 /* index 0x14 is looked up as 0x10 */
};

extern char DAT_002c0e18;
extern char DAT_002c0e1c;
extern char DAT_002c0e20;
extern Manager *FUN_0018c9f4(int);

void *FUN_001fecb4(int index)
{
  Manager *m;
  void *r;

  if (index == INDEX_ALIAS_FROM) {
    index = INDEX_ALIAS_TO;
  }
  m = FUN_0018c9f4(TABLE_KIND);
  if (m->ready == 0) {
    r = &DAT_002c0e20;
  }
  else if (m->header->count < 2) {
    r = &DAT_002c0e1c;
  }
  else if ((index < 0) || (index >= m->table->count)) {
    r = &DAT_002c0e18;
  }
  else {
    r = m->table->items[index];
  }
  return r;
}
