/* HSTMATCH module=EBOOT.BIN start=0x00253a68 end=0x00253afc symbol=FUN_00253a68 lang=c99 helpers=FUN_0018c9f4@0x0018c9f4-0x0018ca94 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idiom: volatile offset read preserves the helper-returned base in v0 until the first indexed field load. */
#include "hst/types.h"
#include "hst/text_bank_lookup.h"
#include "hst/mode_text.h"

extern u8 DAT_002cc560;
extern TextBank * DAT_003415b0;      /* table of 0x10-byte TextBank records, indexed by bank id */
extern char DAT_003415b4;            /* set once the fallback bank has been registered */
extern char DAT_003415b8[];
/* Fallback record for bank 0x10 while the table is missing: first byte and loaded flag cleared. */
typedef struct EmptyBank { char flag; int loaded; } EmptyBank;
extern EmptyBank DAT_003415c4;
extern int DAT_002ca6c4[]; /* group column of DAT_002ca6c0 (the word at +4 of each ModeText), addressed as its own symbol */
extern u32 FUN_00000f74();
extern u32 FUN_0010ad1c();
extern void FUN_000fcb7c();

#define FALLBACK_BANK 0x10

/* Same function as the shared bank lookup; defined here as a same-file static (see helpers=). */
static TextBank * FUN_0018c9f4(int bankId)
{
  TextBank *bank;
  
  if ((DAT_003415b0 == 0) && (bankId == FALLBACK_BANK)) {
    if (DAT_003415b4 == 0) {
      DAT_003415c4.flag = 0;
      DAT_003415c4.loaded = 0;
      FUN_00000f74(&DAT_003415c4,FUN_000fcb7c,DAT_003415b8);
      DAT_003415b4 = 1;
    }
    FUN_0010ad1c(&DAT_003415c4,&DAT_002cc560);
    bank = (TextBank *)(&DAT_003415c4);
  }
  else {
    bank = DAT_003415b0 + bankId;
  }
  return bank;
}

/* Returns the string count of mode `mode`'s group, minus one for modes 2, 5 and 6. */
int FUN_00253a68(int mode)
{
  ModeText *entry = &DAT_002ca6c0[mode];
  TextBank *bank = FUN_0018c9f4(entry->bank);
  TextGroup *groups = *(TextGroup * volatile *)&bank->groups;
  int group = DAT_002ca6c4[mode * 2];
  int count = groups[group].count;

  switch (mode) {
  case 2:
  case 5:
  case 6:
    break;
  default:
    return count;
  }
  return count - 1;
}
