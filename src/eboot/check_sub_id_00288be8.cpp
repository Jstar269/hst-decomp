/* HSTMATCH module=EBOOT.BIN start=0x00288be8 end=0x00288c74 symbol=FUN_00288be8 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: C++ mode, struct member access and virtual method call on slot 11; readability pass; exact match verified; names and types await human review. */
#include "hst/npc_obj.h"

extern "C" void FUN_00288c74(NpcObj *npc);

/* In mode 2 or 3: look the sub record up if needed and compare its id with `id`. */
extern "C" bool FUN_00288be8(NpcObj *npc, int id)
{
  bool match;
  int mode;
  
  mode = npc->mode();
  match = mode == 2;
  if (!match) {
    mode = npc->mode();
    match = mode == 3;
  }
  if (match) {
    if (npc->sub == 0) {
      FUN_00288c74(npc);
    }
    match = npc->sub->id == id;
  }
  else {
    match = false;
  }
  return match;
}
