/* HSTMATCH module=EBOOT.BIN start=0x001fe8c0 end=0x001fe974 symbol=FUN_001fe8c0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed the mixed word, byte, and float record members and grouped the two-float tail; readability pass; exact match verified; names and types await human review. */

#include "hst/key_record.h"

typedef struct { float f[4]; } Float4;
typedef struct { float f[2]; } Float2;
/* One 32-byte keyed record of the fixed 10-entry table (same layout as KeyRecord). */
typedef struct {
  unsigned int key;
  unsigned char bytes[4];
  union { Float4 vector; unsigned int u[4]; } vector;
  union { Float2 pair; float f[2]; unsigned int u[2]; } tail;
} Record;

/* Removes the record at the pointer: later records shift down and the last one is emptied. */
void FUN_001fe8c0(Record *rec)
{
  int i = 0;
  do {
    if (i == KEY_RECORD_COUNT - 1) {
      rec->key = KEY_RECORD_EMPTY;
      rec->bytes[0] = 0;
      rec->bytes[1] = 0;
      rec->bytes[2] = 0;
      rec->bytes[3] = 0;
      rec->vector.u[0] = KEY_RECORD_EMPTY;
      rec->vector.u[1] = KEY_RECORD_EMPTY;
      rec->vector.u[2] = KEY_RECORD_EMPTY;
      rec->vector.u[3] = KEY_RECORD_EMPTY;
      rec->tail.u[0] = KEY_RECORD_EMPTY;
      rec->tail.u[1] = KEY_RECORD_EMPTY;
    }
    else {
      rec->key = rec[1].key;
      rec->bytes[0] = rec[1].bytes[0];
      rec->bytes[1] = rec[1].bytes[1];
      rec->bytes[2] = rec[1].bytes[2];
      rec->bytes[3] = rec[1].bytes[3];
      rec->vector.vector = rec[1].vector.vector;
      rec->tail.pair = rec[1].tail.pair;
    }
    i = i + 1;
    rec = rec + 1;
  } while (i < KEY_RECORD_COUNT);
}
