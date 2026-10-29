/* HSTMATCH module=EBOOT.BIN start=0x002acbf8 end=0x002acd28 symbol=FUN_002acbf8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: assigned the allocation result in the null-check expression and shared its return path; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/spawn_owner.h"

extern u8 DAT_002bc410;
extern u8 DAT_0030779c;
extern char DAT_002cc2b4[];
extern char DAT_002cc2bc[];
extern char DAT_002cc2c4[];
extern int FUN_00000bcc();
extern int FUN_00014934();
extern u32 FUN_00056098();
extern u32 * FUN_000fbf84();
extern u32 * FUN_000fc00c();
extern u32 * FUN_000fc0a0();

/* Remaining uses of the three named layers. */
typedef struct LayerBudget {
  char pad00[0x54];
  int page01;         /* 0x54 uses left for the layer called "page01" */
  int page02;         /* 0x58 uses left for the layer called "page02" */
  int infobg;         /* 0x5c uses left for the layer called "infobg" */
} LayerBudget;

/* Creates the object for the layer called name. *in_budget is set when the name is one of the three known
   layers and a use was still left; that use is consumed. */
SpawnedObj * FUN_002acbf8(LayerBudget *budget,int name,u8 *in_budget)
{
  int cmp;
  int left;
  SpawnedObj *obj;
  
  cmp = FUN_00014934(name,DAT_002cc2c4);
  if (cmp == 0) {
    left = budget->page01;
    budget->page01 = left + -1;
    *in_budget = 0 < left;
  }
  else {
    cmp = FUN_00014934(name,DAT_002cc2bc);
    if (cmp == 0) {
      left = budget->page02;
      budget->page02 = left + -1;
      *in_budget = 0 < left;
    }
    else {
      cmp = FUN_00014934(name,DAT_002cc2b4);
      if (cmp == 0) {
        left = budget->infobg;
        budget->infobg = left + -1;
        *in_budget = 0 < left;
      }
      else {
        *in_budget = 0;
      }
    }
  }
  if ((obj = (SpawnedObj *)FUN_00000bcc(SPAWNED_OBJ_SIZE)) == (SpawnedObj *)0x0) goto done;
  FUN_000fc0a0(obj);
  FUN_00056098(obj->matA);
  obj->vtable = &DAT_0030779c;
  obj->unk70 = 0;
  obj->link = SPAWNED_NO_LINK;
  obj->unk78 = 1.0f;
  obj->unk7c = 1.0f;
  FUN_00056098(obj->matB);
  obj->name = name;
  FUN_000fc00c(obj,&DAT_002bc410);
  FUN_000fbf84(obj->matB,&DAT_002bc410);
done:
  return obj;
}
