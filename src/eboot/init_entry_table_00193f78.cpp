/* HSTMATCH module=EBOOT.BIN start=0x00193f78 end=0x00194030 symbol=FUN_00193f78 lang=c++ */
/* Clone of src/sharing_main/init_entry_table_001a0788.cpp (hstclone.py tag c034920): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" void *FUN_000114c0(void *, int, int);

struct Entry {
  char pad[16];
  short a;
  short b;
};

struct Obj {
  char hdr[20];
  Entry e[4];
  char tail[12];
};

extern "C" Obj *FUN_00193f78(Obj *o)
{
  Entry *p = o->e;
  do {
    FUN_000114c0(p, 0, 20);
    p->a = -1;
    p->b = -1;
    p++;
  } while (p < o->e + 4);
  FUN_000114c0(o, 0, 112);
  for (int i = 0; i < 4; i++) {
    Entry *e = &o->e[i];
    FUN_000114c0(e, 0, 20);
    e->a = -1;
    e->b = -1;
  }
  return o;
}
