/* HSTMATCH module=hstp_trans_main.prx start=0x001b7f74 end=0x001b807c symbol=FUN_001b7f74 lang=c99 */
/* Clone of src/eboot/FUN_001aa9a8.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct { char pad[10]; unsigned char enabled; char tail[37]; } Entry;
typedef struct { char pad[0x88]; unsigned char *checks; char gap1[0xd4]; Entry *entries; char gap2[0x140]; unsigned char clear; } Manager;
extern void FUN_00105470(int, int);
extern Manager *FUN_001aa91c(void);

void FUN_001b7f74(char *base, int idx, int selector)
{
  int *first = (int *)(base + (selector + 8) * 20 + 44);
  int *second = (int *)(base + (selector + 9) * 20 + 44);
  int active = 0;
  Manager *manager = FUN_001aa91c();
  int index = idx * 3;
  Entry *entries = manager->entries;
  if (((Entry *)((char *)entries + (index << 4)))->enabled != 0)
    active = 1;
  FUN_00105470(*first, 1);
  FUN_00105470(*second, 1);
  manager = FUN_001aa91c();
  if ((manager->clear != 0) &&
      (manager = FUN_001aa91c(), manager->checks[idx + 20] == 0)) {
    FUN_00105470(*first, 0);
    FUN_00105470(*second, 0);
  }
  if (active != 0)
    FUN_00105470(*second, 0);
}
