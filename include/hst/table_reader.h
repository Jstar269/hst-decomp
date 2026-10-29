/* Reader state (16 bytes) used by the table-file helpers: initialise, open by name, fetch values by row and column, close. */
#ifndef HST_TABLE_READER_H
#define HST_TABLE_READER_H

typedef struct TableReader {
  int unk0;  /* 0x00 */
  int unk4;  /* 0x04 */
  int unk8;  /* 0x08 */
  int unkc;  /* 0x0c */
} TableReader;

#endif
