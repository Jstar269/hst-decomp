/* HSTMATCH module=EBOOT.BIN start=0x001fc2a8 end=0x001fc31c symbol=FUN_001fc2a8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p128a) corrected by hand: interleaved integer and float arguments and materialized the scaled index before adding the object base; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/part_holder.h"

extern void FUN_000edec0(void *slot,u32 *unk78,float param_3,float param_4,int param_5,int param_6,float param_7,float param_8,float param_9);
extern void FUN_000ffb3c();
extern void FUN_001031e8();

/* Part B refresh: show its widget unless enabled, then start the current slot. */
void FUN_001fc2a8(PartB *part)
{
  FUN_000ffb3c(part->widget7c,(part->enabled != 0) ^ 1);
  FUN_001031e8(part);
  FUN_000edec0(part->slot[part->cur],
               part->unk78,0.0f,0.0f,0,0,1.0f,1.0f,1.0f);
}
