/* HSTMATCH module=EBOOT.BIN start=0x001aa9a8 end=0x001aaab0 symbol=FUN_001aa9a8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct { char pad[10]; unsigned char enabled; char tail[37]; } Entry;
typedef struct { char pad[0x88]; unsigned char *checks; char gap1[0xd4]; Entry *entries; char gap2[0x140]; unsigned char clear; } Manager;
extern void FUN_000ffb3c(int, int);
extern Manager *FUN_0019d474(void);

void FUN_001aa9a8(char *base, int idx, int selector)
{
  int *first = (int *)(base + (selector + 8) * 20 + 44);
  int *second = (int *)(base + (selector + 9) * 20 + 44);
  int active = 0;
  Manager *manager = FUN_0019d474();
  int index = idx * 3;
  Entry *entries = manager->entries;
  if (((Entry *)((char *)entries + (index << 4)))->enabled != 0)
    active = 1;
  FUN_000ffb3c(*first, 1);
  FUN_000ffb3c(*second, 1);
  manager = FUN_0019d474();
  if ((manager->clear != 0) &&
      (manager = FUN_0019d474(), manager->checks[idx + 20] == 0)) {
    FUN_000ffb3c(*first, 0);
    FUN_000ffb3c(*second, 0);
  }
  if (active != 0)
    FUN_000ffb3c(*second, 0);
}
