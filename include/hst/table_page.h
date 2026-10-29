/* Layout of the page object with per-slot value arrays, entry lists and three byte tables. */
#ifndef HST_TABLE_PAGE_H
#define HST_TABLE_PAGE_H

#include "hst/types.h"

enum {
  TABLE_PAGE_SLOTS = 15,      /* entries in each per-slot value array */
  TABLE_PAGE_TABLES = 3,      /* byte tables, one per entry list */
  TABLE_PAGE_TABLE_SIZE = 0x280,
  TABLE_CELL_FLAGGED = 4      /* byte value the entry scans look for */
};

/* Pointer list of entry records; the first word of each record indexes a byte table. */
typedef struct EntryList {
  int **items;   /* 0x00 */
  u32 count;     /* 0x04 */
  u32 unk08;     /* 0x08 */
} EntryList;

typedef int (*PageGetFn)(int);
typedef void (*PageHookFn)(u32);

typedef struct TablePage {
  char pad00[0x3e];
  u8 unk3e;                                      /* 0x3e */
  char pad3f[0x46 - 0x3f];
  u8 active;                                     /* 0x46 */
  char pad47[0xb8 - 0x47];
  u32 unkb8;                                     /* 0xb8 */
  u32 unkbc;                                     /* 0xbc */
  u32 byteValues[TABLE_PAGE_SLOTS];              /* 0xc0 */
  u32 shortValues[TABLE_PAGE_SLOTS];             /* 0xfc */
  char pad138[0x1e4 - 0x138];
  EntryList listA;                               /* 0x1e4 */
  char pad1f0[0x1fc - 0x1f0];
  EntryList listB;                               /* 0x1fc */
  EntryList listC;                               /* 0x208 */
  char pad214[0x3e8 - 0x214];
  PageGetFn getEntry;                            /* 0x3e8 */
  char pad3ec[0x53c - 0x3ec];
  PageHookFn hook;                               /* 0x53c */
  char pad540[0x63b - 0x540];
  u8 tables[TABLE_PAGE_TABLES][TABLE_PAGE_TABLE_SIZE]; /* 0x63b */
} TablePage;

#endif
