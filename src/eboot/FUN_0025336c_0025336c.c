/* HSTMATCH module=EBOOT.BIN start=0x0025336c end=0x00253440 symbol=FUN_0025336c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: materialized both range predicates and formed the indexed row address through an offset-first comma expression; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/text_bank_lookup.h"

#define TEXT_BANK_LABELS 0x12

extern u32 DAT_003386c8;
extern u32 FUN_0008d994();
extern void FUN_00110a78(u32, const char *, int);
extern TextBank * FUN_0018c9f4(int);

/* Looks up string (group, index) of bank 0x12 and hands it to FUN_00110a78 together with the object from FUN_0008d994. */
void FUN_0025336c(int group,int index)
{
  const char *text;
  u32 target;

  text = TextGet(FUN_0018c9f4(TEXT_BANK_LABELS),group,index);
  target = FUN_0008d994(DAT_003386c8);
  FUN_00110a78(target,text,0);
}
