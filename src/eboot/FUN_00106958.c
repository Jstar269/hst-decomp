/* HSTMATCH module=EBOOT.BIN start=0x00106958 end=0x00106a34 symbol=FUN_00106958 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/ui_node.h"

typedef struct ChoiceHost {
  NodeHost base;   /* 0x00 */
  char pad18[0xb8];
  int selected;    /* 0xd0 index of the chosen node (used in single mode) */
  int mode;        /* 0xd4 how many nodes take part */
  char group[4];   /* 0xd8 collection the nodes are added to */
} ChoiceHost;

enum {
  MODE_SINGLE = 2, /* only the selected node */
  MODE_PAIR = 3    /* nodes 1 and 2 */
};                 /* any other mode: nodes 1 to 4 */

extern void FUN_0027fc70();

/* Add the nodes for the current mode to the group; the flag is set on the last one added. */
void FUN_00106958(ChoiceHost *host)
{
  if (host->mode == MODE_SINGLE) {
    FUN_0027fc70(host->group,host->base.nodes[host->selected],1);
  }
  else if (host->mode == MODE_PAIR) {
    FUN_0027fc70(host->group,host->base.nodes[1],0);
    FUN_0027fc70(host->group,host->base.nodes[2],1);
  }
  else {
    FUN_0027fc70(host->group,host->base.nodes[1],0);
    FUN_0027fc70(host->group,host->base.nodes[2],0);
    FUN_0027fc70(host->group,host->base.nodes[3],0);
    FUN_0027fc70(host->group,host->base.nodes[4],1);
  }
}
