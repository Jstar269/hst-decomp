/* Script module runner context: module table entries, rule list of a module and the running context. */
#ifndef HST_MODULE_CTX_H
#define HST_MODULE_CTX_H

#include "hst/types.h"
#include "hst/list_head.h"

struct ModuleRule;
struct ModuleChild;

/* Node of a module's rule list. */
typedef struct ModuleNode {
    struct ModuleNode *prev;   /* 0x00 */
    struct ModuleNode *next;   /* 0x04 */
    struct ModuleRule *rule;   /* 0x08 */
} ModuleNode;

/* Rule list of one module: element count and the sentinel node. */
typedef struct ModuleRules {
    int size;                  /* 0x00 */
    ModuleNode head;           /* 0x04 */
} ModuleRules;

typedef struct ModuleEntry {
    int id;                    /* 0x00 */
    ModuleRules *module;       /* 0x04 */
} ModuleEntry;

/* Table of loaded modules; only the entry array is needed by the context code. */
typedef struct ModuleTable {
    ModuleEntry *entries;      /* 0x00 */
    int size;                  /* 0x04 */
    int capacity;              /* 0x08 */
} ModuleTable;

/* 36-byte context that walks the rules of one module. */
typedef struct ModuleCtx {
    ModuleTable *table;        /* 0x00 */
    ModuleRules *module;       /* 0x04 */
    struct ModuleChild *owned; /* 0x08 running child, released through its virtual destructor */
    int arg;                   /* 0x0c */
    u8 flag;                   /* 0x10 */
    char pad11[3];
    ModuleNode *cur;           /* 0x14 current rule node, the module's sentinel when finished */
    DListHead nodes;           /* 0x18 queued nodes: count, then the sentinel links */
} ModuleCtx;

#endif
