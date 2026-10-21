/* HSTMATCH module=hstp_trans_main.prx start=0x0020d484 end=0x0020d528 symbol=FUN_0020d484 lang=c99 */
/* Clone of src/eboot/table_entry_lookup_001fecb4.c (hstclone.py tag c21sn35s): addresses substituted; exact match verified; names and types await human review. */
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

extern char DAT_002d10cc;
extern char DAT_002d10d0;
extern char DAT_002d10d4;
extern Manager *FUN_001991d4(int);

void *FUN_0020d484(int param_1)
{
  Manager *m;
  void *r;

  if (param_1 == 0x14) {
    param_1 = 0x10;
  }
  m = FUN_001991d4(9);
  if (m->ready == 0) {
    r = &DAT_002d10d4;
  }
  else if (m->header->count < 2) {
    r = &DAT_002d10d0;
  }
  else if ((param_1 < 0) || (param_1 >= m->table->count)) {
    r = &DAT_002d10cc;
  }
  else {
    r = m->table->items[param_1];
  }
  return r;
}
