/* Screen that replaces its model with one loaded from a record table (modes 1, 2 and 3). */
#ifndef HST_REPLACE_SCREEN_H
#define HST_REPLACE_SCREEN_H

#include "hst/types.h"

#define REPLACE_REC_SIZE 0x30   /* size of one record of the tables */
#define REPLACE_MODEL_SIZE 0x1c0 /* size of the model object */

/* Record of a table (48 bytes). */
typedef struct ReplaceRec {
  char pad00[8];
  u32 id;               /* 0x08 resource id loaded into the model */
  char pad0c[8];
  int kind;             /* 0x14 2 selects the face animation setup */
  char pad18[0x18];
} ReplaceRec;

/* Vector of records: data, size and capacity. */
typedef struct ReplaceVec {
  ReplaceRec *data;     /* 0x00 */
  int size;             /* 0x04 */
  int cap;              /* 0x08 */
} ReplaceVec;

typedef struct ReplaceScreen {
  char pad00[0xa8];
  ReplaceVec recs2;     /* 0xa8 records for mode 2 */
  ReplaceVec recs1;     /* 0xb4 records for mode 1 */
  ReplaceVec recs3;     /* 0xc0 records for mode 3 */
  char padcc[0xf0 - 0xcc];
  void *model;          /* 0xf0 */
  char padf4[0x180 - 0xf4];
  int unk180;           /* 0x180 negative when there is nothing to load */
} ReplaceScreen;

#endif
