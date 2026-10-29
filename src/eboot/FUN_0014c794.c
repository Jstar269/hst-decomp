/* HSTMATCH module=EBOOT.BIN start=0x0014c794 end=0x0014c820 symbol=FUN_0014c794 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256c) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/module_ctx.h"

extern void FUN_0014f32c();
extern DListHead * FUN_0014f528(DListHead *);

/* Construct a context over a module: start at its first rule and clear the node list. */
ModuleCtx * FUN_0014c794(ModuleCtx *self,ModuleTable *table,ModuleRules *module,int arg)
{
  ModuleRules *rules;
  u8 eraseResult [4];
  DListLinks *first;
  DListLinks *last;
  
  self->table = table;
  self->module = module;
  self->owned = 0;
  self->arg = arg;
  self->flag = 0;
  FUN_0014f528(&self->nodes);
  rules = self->module;
  if (rules != (ModuleRules *)0x0) {
    if (rules->size == 0) {
      self->cur = &rules->head;
    }
    else {
      self->cur = rules->head.next;
    }
  }
  last = &self->nodes.sentinel;
  first = self->nodes.sentinel.next;
  FUN_0014f32c(eraseResult,&self->nodes,&first,&last);
  return self;
}
