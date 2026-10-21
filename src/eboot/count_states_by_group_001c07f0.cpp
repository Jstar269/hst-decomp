/* HSTMATCH module=EBOOT.BIN start=0x001c07f0 end=0x001c09e8 symbol=FUN_001c07f0 lang=c++ rodata=0x002c6328 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Counts the entries whose state byte is 4 or 5 in the group selected by sel (a 15-entry record table with stride 56 and four 640-byte arrays); each element is reached through a bounds-checked pointer written as if (i >= 0 && i < N) p = &arr[i]; else p = 0; (the ternary form lays out a bnezl select instead of retail's beqz/b). */
struct Entry {
  char pad0[4];
  unsigned char state;
  char pad5[0x33];
};
struct Pair {
  unsigned char v;
  unsigned char w;
};
struct Obj {
  Entry entries[15];
  char pad[0x34c - 0x348];
  Pair pairs[640];
  unsigned char a[640];
  unsigned char b[640];
  unsigned char c[640];
};

static inline bool Hit(unsigned char v) { return (unsigned)(v - 4) < 2; }

extern "C" int FUN_001c07f0(Obj *o, int sel)
{
  int count;
  int i;
  switch (sel) {
  case 0:
    count = 0;
    i = 0;
    do {
      unsigned char *p;
      if (i >= 0 && i < 15) {
        p = &o->entries[i].state;
      } else {
        p = 0;
      }
      if (Hit(*p)) {
        count++;
      }
      i++;
    } while (i < 15);
    break;
  case 1:
    count = 0;
    i = 0;
    do {
      unsigned char *p;
      if (i >= 0 && i < 640) {
        p = &o->a[i];
      } else {
        p = 0;
      }
      if (Hit(*p)) {
        count++;
      }
      i++;
    } while (i < 640);
    break;
  case 2:
    count = 0;
    i = 0;
    do {
      unsigned char *p;
      if (i >= 0 && i < 640) {
        p = &o->b[i];
      } else {
        p = 0;
      }
      if (Hit(*p)) {
        count++;
      }
      i++;
    } while (i < 640);
    break;
  case 3:
  case 4:
    count = 0;
    i = 0;
    do {
      unsigned char *p;
      if (i >= 0 && i < 640) {
        p = &o->c[i];
      } else {
        p = 0;
      }
      if (Hit(*p)) {
        count++;
      }
      i++;
    } while (i < 640);
    break;
  case 5:
    count = 0;
    i = 0;
    do {
      unsigned char *p;
      if (i >= 0 && i < 640) {
        p = &o->pairs[i].v;
      } else {
        p = 0;
      }
      if (Hit(*p)) {
        count++;
      }
      i++;
    } while (i < 640);
    break;
  default:
    count = 0;
    break;
  }
  return count;
}
