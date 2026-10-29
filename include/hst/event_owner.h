/* Owner of a table of event objects, the event currently being driven and its transform data. */
#ifndef HST_EVENT_OWNER_H
#define HST_EVENT_OWNER_H

typedef struct EventOwner {
  char pad00[0x4c];
  void **table;       /* 0x4c event objects, indexed by slot */
  int unk50;          /* 0x50 */
  char pad54[0x98 - 0x54];
  void *current;      /* 0x98 event object being driven */
  char pad9c[4];
  float unka0[4];     /* 0xa0 transform data handed to the event object */
  char padb0[0xc0 - 0xb0];
  int unkc0;          /* 0xc0 */
  char padc4[0xf3 - 0xc4];
  char unkf3;         /* 0xf3 cleared when the active flag is off */
  char padf4[0x17c - 0xf4];
  void *unk17c;       /* 0x17c */
} EventOwner;

#endif
