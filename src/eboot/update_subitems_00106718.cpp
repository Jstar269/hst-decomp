/* HSTMATCH module=EBOOT.BIN start=0x00106718 end=0x001067c0 symbol=FUN_00106718 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: structured node and host types, early return on non-zero skip, #pragma opt_strength_reduction off; readability pass; exact match verified; names and types await human review. */
#include "hst/ui_node.h"

#pragma opt_strength_reduction off

extern "C" void FUN_00101c18(void *, int);

/* The object owned by each node; only the virtual toggle is called. */
struct Toggle {
  virtual void d0();
  virtual void set(int);
};

enum { NODE_ON = 1 };

/* Switch on every node except the first, which is switched off; tell each node's child about it. */
extern "C" void FUN_00106718(NodeHost *host, int skip)
{
  if (skip != 0) {
    FUN_00101c18(host, 1);
    return;
  }

  for (int i = 0; i < host->count; ++i) {
    UiNode *node = host->nodes[i];
    if (i != 0) {
      node->flags |= NODE_ON;
    } else {
      node->flags &= 0xfffe;
    }
    if (node->child != 0) {
      ((Toggle *)node->child)->set(i != 0);
    }
  }
}
