/* HSTMATCH module=EBOOT.BIN start=0x000bb888 end=0x000bb9d4 symbol=FUN_000bb888 lang=c++ data=0x002d52d4 */
/* Clone of src/sharing_main/table_add_entry_000becfc.cpp (hstclone.py tag c042120): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002d52d4-0x002d52e4) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* 16 seven-byte slots (6-byte key at +0x58, used flag at +0x5e): add the key unless present, into slot `slot` or the first free one. Matching idioms: the 6-byte copy is the memberwise Mac6 assignment (user ctor => lb/lb/sb/sb loop); loop 2 has its own block-scope counter; the explicit-slot path is offset-first (`off = slot*7; off += (int)t`) with the flag address kept in a pointer. */
struct Mac6 {
  char c[6];
  Mac6() {}
};
struct Slot {
  Mac6 mac;
  unsigned char used;
};
struct Table {
  char pad[0x58];
  Slot slots[16];
};
extern "C" {
int FUN_0001100c(const void *, const void *, int);
void FUN_000ba3ac(const char *);
}

extern "C" void FUN_000bb888(Table *t, const Mac6 *mac, int a2, int a3, int slot)
{
  int i;
  for (i = 0; i < 16; i++) {
    if (t->slots[i].used != 0 && FUN_0001100c(&t->slots[i].mac, mac, 6) == 0)
      return;
  }
  if (slot < 0) {
    for (int j = 0; j < 16; j++) {
      if (t->slots[j].used == 0) {
        t->slots[j].mac = *mac;
        t->slots[j].used = 1;
        return;
      }
    }
  } else {
    int off = slot * 7;
    off += (int)t;
    Table *p = (Table *)off;
    unsigned char *flag = &p->slots[0].used;
    if (*flag == 0) {
      p->slots[0].mac = *mac;
      *flag = 1;
      return;
    }
  }
  FUN_000ba3ac("AddMember Fail\n");
}
