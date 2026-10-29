/* Object of the 0x1be000 sources: per-kind tables of 640 marks and a set of small flag arrays, filled from manager entries. */
#ifndef HST_FLAG_TABLES_H
#define HST_FLAG_TABLES_H

#include "hst/types.h"

#define MARK_COUNT 640       /* entries in each mark table */
#define SUB_REC_COUNT 15
#define SUB_ROW_COUNT 4
#define SUB_ROW_VALUE_COUNT 4
#define FLAG_A_COUNT 21
#define FLAG_B_COUNT 8
#define FLAG_C_COUNT 15
#define CELL_COUNT 12
#define CELL_FLAG_COUNT 4
#define SUB_BLOCK_SIZE 0x2000

/* Entry the manager lookup returns; only the state byte is read (negative: unusable, 1: marked directly). */
typedef struct MgrEntry {
  char pad00[0x60];
  s8 state;             /* 0x60 */
} MgrEntry;

typedef struct SubRow {
  s16 v[SUB_ROW_VALUE_COUNT]; /* 0x00 */
  int unk08;            /* 0x08 */
} SubRow;               /* size 0xc */

/* Record of kind 0 (56 bytes). */
typedef struct SubRec {
  u8 a;                 /* 0x00 */
  u8 b;                 /* 0x01 */
  s16 c;                /* 0x02 */
  float f;              /* 0x04 */
  SubRow rows[SUB_ROW_COUNT]; /* 0x08 */
} SubRec;

typedef struct MarkPair {
  u8 a;                 /* 0x0 */
  u8 b;                 /* 0x1 */
} MarkPair;

/* Five-byte cell: a kind byte and four flags. */
typedef struct FlagCell {
  u8 kind;
  u8 flags[CELL_FLAG_COUNT];
} FlagCell;

typedef struct FlagTables {
  int unk000;                       /* 0x000 */
  SubRec subs[SUB_REC_COUNT];       /* 0x004 kind 0 */
  MarkPair pairs[MARK_COUNT];       /* 0x34c kind 5 */
  u8 marks1[MARK_COUNT];            /* 0x84c kind 1 */
  u8 marks2[MARK_COUNT];            /* 0xacc kind 2 */
  u8 marks3[MARK_COUNT];            /* 0xd4c kind 3 */
  u8 flag_a[FLAG_A_COUNT];          /* 0xfcc */
  u8 flag_b[FLAG_B_COUNT];          /* 0xfe1 */
  char padfe9[0x1025 - 0xfe9];
  u8 flag_c[FLAG_C_COUNT];          /* 0x1025 */
  char pad1034[0x1378 - 0x1034];
  char sub_block[SUB_BLOCK_SIZE];   /* 0x1378 */
  char pad3378[0x3444 - 0x3378];
  FlagCell cells[CELL_COUNT];       /* 0x3444 */
} FlagTables;

#endif
