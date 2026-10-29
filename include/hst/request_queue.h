/* Owner of a pending-request list and the 24-byte record queued onto it (request sources). */
#ifndef HST_REQUEST_QUEUE_H
#define HST_REQUEST_QUEUE_H

#include "hst/list_head.h"

/* Request record handed to the list-insert helper. */
typedef struct RequestRec {
  int type;       /* 0x00 request kind */
  int count;      /* 0x04 */
  int arg8;       /* 0x08 */
  int argc;       /* 0x0c */
  int arg10;      /* 0x10 */
  int arg14;      /* 0x14 */
} RequestRec;

typedef struct RequestOwner {
  char pad00[0x4c];
  int unk4c;      /* 0x4c */
  char pad50[0x64 - 0x50];
  DListHead queue; /* 0x64 pending requests: element count, then the sentinel links */
} RequestOwner;

#endif
