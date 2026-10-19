/* HSTMATCH module=hstp_trans_main.prx start=0x001711f4 end=0x00171298 symbol=FUN_001711f4 lang=c99 */
/* Clone of src/eboot/find_entry_by_name_00165004.c (hstclone.py tag s10172123g4r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed entry/table structs, #pragma opt_strength_reduction off; exact match verified; names and types await human review. */
typedef unsigned int uint;

extern char DAT_00387980[];
extern void FUN_000143b0(char *buf, const char *fmt, ...);
extern int FUN_000146ec(const char *s1, const char *s2);
extern void FUN_001104b0(char *buf, int);

#pragma opt_strength_reduction off

struct Entry {
  char pad[2];
  char name[554];
};

struct Table {
  struct Entry *entries;
  uint count;
};

uint FUN_001711f4(struct Table *param_1, const char *param_2)
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
  FUN_000143b0(auStack_100, DAT_00387980, param_2);
  FUN_001104b0(auStack_100, 0);
  return 0;
}
