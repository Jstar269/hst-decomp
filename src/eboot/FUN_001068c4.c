/* HSTMATCH module=EBOOT.BIN start=0x001068c4 end=0x001068d8 symbol=FUN_001068c4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag u1ge) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/ui_node.h"

typedef struct GroupHost {
  NodeHost base;   /* 0x00 */
  char pad18[0xb8];
  char group[4];   /* 0xd0 collection the first node is added to */
} GroupHost;

extern void FUN_0027fc70();

void FUN_001068c4(GroupHost *host)
{
  FUN_0027fc70(host->group,host->base.nodes[0],1);
}
