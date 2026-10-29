/* HSTMATCH module=EBOOT.BIN start=0x0014c214 end=0x0014c274 symbol=FUN_0014c214 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/module_ctx.h"

extern ModuleCtx * FUN_0014c794(ModuleCtx *,ModuleTable *,ModuleRules *,int);
extern int FUN_0014c820();
extern ModuleCtx * FUN_0014c914(ModuleCtx *,ModuleCtx *);
extern DListHead * FUN_0014f528(DListHead *);

/* Build the context of module number moduleNo of the table into *dest (via a temporary). */
u32 FUN_0014c214(ModuleCtx *dest,ModuleTable *table,int moduleNo,int arg)
{
  ModuleCtx temp;
  ModuleEntry *entry = table->entries + moduleNo;
  
  FUN_0014c794(&temp,table,entry->module,arg);
  dest->owned = 0;
  FUN_0014f528(&dest->nodes);
  FUN_0014c914(dest,&temp);
  FUN_0014c820(&temp,0xffffffff);
  return 0;
}
