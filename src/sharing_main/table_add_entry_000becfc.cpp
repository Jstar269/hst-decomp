/* HSTMATCH module=hstp_trans_main.prx start=0x000becfc end=0x000bee48 symbol=FUN_000becfc lang=c++ */
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
void FUN_000bd6f0(const char *);
extern char DAT_0037bbe0[];
}

extern "C" void FUN_000becfc(Table *t, const Mac6 *mac, int a2, int a3, int slot)
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
  FUN_000bd6f0(DAT_0037bbe0);
}
