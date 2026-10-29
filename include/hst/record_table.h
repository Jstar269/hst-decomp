/* Object holding a table of 15 four-row records (filled, reset and queried by the 0x1c1000 sources). */
#ifndef HST_RECORD_TABLE_H
#define HST_RECORD_TABLE_H

#include "hst/types.h"

#define RECORD_COUNT 15 /* records in the table */
#define RECORD_ROWS 4   /* rows per record */
#define ROW_CELLS 4     /* 16-bit cells per row */

typedef struct RecordRow {
  s16 cell[ROW_CELLS];    /* 0x00 */
  char pad08[4];
} RecordRow;              /* size 0x0c */

typedef struct RecordEntry {
  u8 unk0;                /* 0x00 set to 4 when the source entry's kind byte is 1 */
  u8 unk1;                /* 0x01 */
  s16 unk2;               /* 0x02 */
  int unk4;               /* 0x04 */
  RecordRow row[RECORD_ROWS]; /* 0x08 */
} RecordEntry;            /* size 0x38 */

typedef struct RecordTable {
  int handle;             /* 0x00 passed to the base-class reset */
  char pad04[0x1c];
  int unk20;              /* 0x20 */
  int unk24;              /* 0x24 */
  int unk28;              /* 0x28 */
  int unk2c;              /* 0x2c */
  int unk30;              /* 0x30 */
  int unk34;              /* 0x34 */
  int unk38;              /* 0x38 */
  int unk3c;              /* 0x3c */
  s16 unk40;              /* 0x40 */
  char pad42;
  s8 unk43;               /* 0x43 */
  char pad44[0x6c];
  s8 unkb0;               /* 0xb0 */
  s8 unkb1;               /* 0xb1 */
  s8 unkb2;               /* 0xb2 */
  s8 unkb3;               /* 0xb3 */
  s8 unkb4;               /* 0xb4 */
  char padb5[7];
  s8 unkbc;               /* 0xbc */
  s8 unkbd;               /* 0xbd */
  char padbe[2];
  int unkc0;              /* 0xc0 -1 when none */
  s8 unkc4;               /* 0xc4 */
  s8 unkc5;               /* 0xc5 */
  s8 unkc6;               /* 0xc6 */
  s8 unkc7;               /* 0xc7 */
  RecordEntry rec[RECORD_COUNT]; /* 0xc8 */
  s16 unk410;             /* 0x410 */
  u8 pair[2][2];          /* 0x412 two cleared byte pairs */
  char pad416[0x8416 - 0x416];
  u16 unk8416;            /* 0x8416 */
  u16 unk8418;            /* 0x8418 */
  u16 unk841a;            /* 0x841a */
  u16 unk841c;            /* 0x841c */
  u16 unk841e;            /* 0x841e */
  char pad8420[0x8430 - 0x8420];
  int unk8430;            /* 0x8430 */
  char pad8434[4];
  int unk8438;            /* 0x8438 */
} RecordTable;

#endif
