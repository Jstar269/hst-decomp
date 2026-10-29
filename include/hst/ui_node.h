/* Child UI node and the host object that keeps a counted array of them (the 0x1063xx-0x10d3xx and 0x2246xx sources). */
#ifndef HST_UI_NODE_H
#define HST_UI_NODE_H

#include "hst/types.h"

typedef struct UiNode {
    int unk00;          /* 0x00 */
    char pad04[0xa];
    u16 flags;          /* 0x0e bit 0 set when the node is switched on */
    char pad10[0x10];
    void *child;        /* 0x20 owned object with a virtual toggle method */
    int unk24;          /* 0x24 */
    int unk28;          /* 0x28 */
} UiNode;

/* Start of every object that owns a node array. */
typedef struct NodeHost {
    const void *vtable; /* 0x00 */
    char pad04[0xc];
    UiNode **nodes;     /* 0x10 */
    int count;          /* 0x14 */
} NodeHost;

#endif
