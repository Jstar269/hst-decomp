/* HSTMATCH module=EBOOT.BIN start=0x00165004 end=0x001650a8 symbol=FUN_00165004 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed entry/table structs, #pragma opt_strength_reduction off; exact match verified; names and types await human review. */
typedef unsigned int uint;

extern char DAT_002e03c4[];
extern void FUN_000143b0(char *buf, const char *fmt, ...);
extern int FUN_000146ec(const char *s1, const char *s2);
extern void FUN_0010a6f0(char *buf, int);

#pragma opt_strength_reduction off

struct Entry {
  char pad[2];
  char name[554];
};

struct Table {
  struct Entry *entries;
  uint count;
};

uint FUN_00165004(struct Table *param_1, const char *param_2)
{
  uint uVar2;
  char auStack_100[256];

  uVar2 = 0;
  if (param_1->count != 0) {
    do {
      if (FUN_000146ec(param_2, param_1->entries[uVar2].name) == 0) {
        return uVar2;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < param_1->count);
  }
  FUN_000143b0(auStack_100, DAT_002e03c4, param_2);
  FUN_0010a6f0(auStack_100, 0);
  return 0;
}
