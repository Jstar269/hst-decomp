/* Cursor page menu object and its child node layout (the 0x2246xx-0x2249xx sources: constructor, reset, step, highlight). */
#ifndef HST_PAGE_MENU_H
#define HST_PAGE_MENU_H

#include "hst/types.h"
#include "hst/ui_node.h"

#define PAGE_MENU_ENTRIES 2     /* selectable entries (each owns four child nodes) */
#define PAGE_MENU_SETS 2        /* two parallel sets of per-entry value blocks */
#define PAGE_MENU_BLOCK_WORDS 8 /* words per value block */
#define PAGE_MENU_NODES 9       /* base node, then four per entry */

typedef struct PageMenu {
    const void *vtable;                 /* 0x00 */
    char pad04[0x54 - 4];
    u8 unk54;                           /* 0x54 */
    char pad55[3];
    int slot[3];                        /* 0x58 */
    UiNode *node[PAGE_MENU_NODES];    /* 0x64 */
    void *hook;                         /* 0x88 optional helper object */
    void *unk8c;                        /* 0x8c */
    int cursor;                         /* 0x90 selected entry */
    int count;                          /* 0x94 number of entries */
    float block[PAGE_MENU_SETS][PAGE_MENU_ENTRIES][PAGE_MENU_BLOCK_WORDS]; /* 0x98 */
    u8 unk118;                          /* 0x118 */
} PageMenu;

#endif
