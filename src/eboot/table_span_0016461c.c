/* HSTMATCH module=EBOOT.BIN start=0x0016461c end=0x001646a0 symbol=FUN_0016461c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Entry {
  int f00;
  int f04;
  float value;                /* 0x08 */
  int f0c;
  int f10;
};

struct Table {
  struct Entry *entries;      /* 0x00 */
  int count;                  /* 0x04 */
};

extern struct Table *DAT_00341510;

int FUN_0016461c(int param_1)
{
  float v = *(float *)(param_1 + 0x50);
  struct Entry *entries;
  int count;
  float first;
  float last;
  float clamped;

  entries = DAT_00341510->entries;
  count = DAT_00341510->count;
  first = entries[0].value;
  last = *(float *)((char *)entries + (count - 1) * 0x14 + 8);
  /* keep v inside [first, last]; the negated upper test is what the retail code emits */
  clamped = v < first ? first : (!(v > last) ? v : last);
  return (int)((last - clamped) * 2.0f + 0.5f);
}
