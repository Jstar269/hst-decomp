/* HSTMATCH module=hstp_trans_main.prx start=0x0015827c end=0x00158308 symbol=FUN_0015827c lang=c99 */
/* Clone of src/eboot/FUN_0014c794.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/module_ctx.h"

extern void FUN_0015b32c();
extern DListHead * FUN_0015b528(DListHead *);

/* Construct a context over a module: start at its first rule and clear the node list. */
ModuleCtx * FUN_0015827c(ModuleCtx *self,ModuleTable *table,ModuleRules *module,int arg)
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
  FUN_0015b528(&self->nodes);
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
  FUN_0015b32c(eraseResult,&self->nodes,&first,&last);
  return self;
}
