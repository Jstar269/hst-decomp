/* Fixed table of 32-byte keyed records; an unused record holds KEY_RECORD_EMPTY as its key. */
#ifndef HST_KEY_RECORD_H
#define HST_KEY_RECORD_H

#define KEY_RECORD_COUNT 10
#define KEY_RECORD_EMPTY 0x7fffffff

typedef struct KeyRecord {
  int key;                       /* 0x00 */
  unsigned char bytes[4];        /* 0x04 */
  unsigned int words[6];         /* 0x08 */
} KeyRecord;

#endif
