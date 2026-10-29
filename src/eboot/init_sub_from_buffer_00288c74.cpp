/* HSTMATCH module=EBOOT.BIN start=0x00288c74 end=0x00288cf4 symbol=FUN_00288c74 lang=c++ data=0x002feb20 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: C++ mode, struct member access and virtual method call on slot 11; readability pass; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002feb20-0x002feb2e) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/npc_obj.h"

enum { NAME_BUFFER_SIZE = 64 };

extern "C" void FUN_000143b0(void*, const void*, int, int);
extern "C" NpcSub* FUN_00193024(void*);

/* In mode 2 or 3: build the resource name from the two numbers and look the sub record up by it. */
extern "C" void FUN_00288c74(NpcObj *npc)
{
  bool match;
  int mode;
  char name[NAME_BUFFER_SIZE];
  
  mode = npc->mode();
  match = mode == 2;
  if (!match) {
    mode = npc->mode();
    match = mode == 3;
  }
  if (match) {
    FUN_000143b0(name, "Npc_%03d_%02d", npc->npc_num, npc->sub_num);
    npc->sub = FUN_00193024(name);
  }
}
