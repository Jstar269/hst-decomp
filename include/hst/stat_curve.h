/* Row tables behind the 0x1642xx-0x164exx ratio and clamp sources: the shared table head and the curve row layout. */
#ifndef HST_STAT_CURVE_H
#define HST_STAT_CURVE_H

#define STAT_RECORD_SIZE 0x22c /* bytes per record of the indexed record table */
#define STAT_CURVE_ROW_SIZE 0x14 /* bytes per curve row */
#define STAT_ID_GROUP_DIVISOR 10  /* a record id divided by this gives its group */
#define STAT_GROUP_LAST 50        /* group whose value is the last curve row */
#define STAT_LEVEL_COUNT 2        /* levels with a percent scale */

/* Table head: rows (or records), how many, and for the record table a short index by id. */
typedef struct StatTable {
  char *base;      /* 0x00 */
  int count;       /* 0x04 */
  int unk08;       /* 0x08 */
  short *index;    /* 0x0c record index by id (record table only) */
} StatTable;

/* One curve row: a key per column. */
typedef struct StatCurveRow {
  float col00;     /* 0x00 */
  float col04;     /* 0x04 */
  float col08;     /* 0x08 */
  int unk0c;       /* 0x0c */
  float col10;     /* 0x10 */
} StatCurveRow;    /* size 0x14 */

#endif
