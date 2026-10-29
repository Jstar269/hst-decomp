/* 0xa0-byte record of counters, used as an array and by the small percent helpers (value pairs whose ratio is taken). */
#ifndef HST_STAT_RECORD_H
#define HST_STAT_RECORD_H

#define STAT_RECORD_BYTES 0xa0

typedef struct StatRecord {
  char pad00[0x28];
  int unk28;   /* 0x28 */
  int unk2c;   /* 0x2c */
  int unk30;   /* 0x30 */
  int unk34;   /* 0x34 */
  int unk38;   /* 0x38 */
  int unk3c;   /* 0x3c */
  char pad40[4];
  int unk44;   /* 0x44 */
  int unk48;   /* 0x48 */
  char pad4c[STAT_RECORD_BYTES - 0x4c];
} StatRecord;  /* size 0xa0 */

#endif
