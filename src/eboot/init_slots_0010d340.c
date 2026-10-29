/* HSTMATCH module=EBOOT.BIN start=0x0010d340 end=0x0010d3e4 symbol=FUN_0010d340 lang=c99 */
/* Hand-written reconstruction from the disassembly (the two field stores go through a block-scoped pointer so it dies at the second call and is reloaded for the last store; `opt_strength_reduction off` keeps the per-iteration `i * 4`); exact match verified; names and types await human review. */
#include "hst/ui_node.h"

typedef struct SlotHost {
    NodeHost base;      /* 0x00 */
    char pad18[0xb8];
    int unkd0;          /* 0xd0 copied into every node's two value fields */
    int unkd4;          /* 0xd4 stored in every node's first word */
} SlotHost;

extern void FUN_000ffb3c(UiNode *, int);
extern void FUN_000ffca4(UiNode *);
#pragma opt_strength_reduction off

/* Reset every node of the host to the host's two shared values. */
void FUN_0010d340(SlotHost *host)
{
    int i;

    for (i = 0; i < host->base.count; i++) {
        int v;

        FUN_000ffb3c(host->base.nodes[i], 0);
        v = host->unkd0;
        {
            UiNode *node = host->base.nodes[i];
            node->unk24 = v;
            node->unk28 = v;
        }
        FUN_000ffca4(host->base.nodes[i]);
        host->base.nodes[i]->unk00 = host->unkd4;
    }
}
