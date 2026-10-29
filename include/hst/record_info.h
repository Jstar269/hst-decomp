/* Info record looked up by id and built by the record constructor: halfword values, two 16-byte sub-objects, byte settings. */
#ifndef HST_RECORD_INFO_H
#define HST_RECORD_INFO_H

enum { INFO_VALUES = 6, INFO_EXTRA = 8, INFO_REPEATS = 4 };

typedef struct RecordInfo {
  short vals[INFO_VALUES];            /* 0x0 */
  char pad0c[0x52 - 0x0c];
  short unk52;                        /* 0x52 */
  char unk54[0x10];                   /* 0x54 sub-object */
  unsigned char unk64;                /* 0x64 limited to below 0x16 */
  unsigned char unk65;                /* 0x65 */
  unsigned char unk66;                /* 0x66 */
  unsigned char unk67;                /* 0x67 */
  char unk68[0x10];                   /* 0x68 copy of the sub-object at 0x54 */
  short unk78;                        /* 0x78 copy of unk52 */
  char pad7a[2];
  unsigned char unk7c[3 * INFO_REPEATS]; /* 0x7c four 3-byte groups */
  char pad88[2];
  short extra[INFO_EXTRA];            /* 0x8a */
  char pad9a[2];
  unsigned char unk9c;                /* 0x9c */
  unsigned char unk9d;                /* 0x9d */
  unsigned char unk9e;                /* 0x9e */
  unsigned char unk9f;                /* 0x9f */
  unsigned char unka0;                /* 0xa0 */
  char pada1[0xc8 - 0xa1];
  unsigned char unkc8;                /* 0xc8 */
  unsigned char unkc9;                /* 0xc9 */
  char padca;
  unsigned char unkcb;                /* 0xcb */
  char unkcc[0xec - 0xcc];            /* 0xcc sub-object */
  unsigned char unkec;                /* 0xec */
  char pade[0x101 - 0xed];
  unsigned char unk101;               /* 0x101 */
} RecordInfo;

#endif
