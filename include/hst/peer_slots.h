/* View of the network object's table of 16 peer slots (6-byte address plus an in-use byte) and its matching handle. */
#ifndef HST_PEER_SLOTS_H
#define HST_PEER_SLOTS_H

enum { PEER_SLOT_COUNT = 16 };

typedef struct PeerSlot {
  char mac[6];          /* 0x00 6-byte peer address */
  unsigned char on;     /* 0x06 slot in use */
} PeerSlot;             /* size 7 */

typedef struct PeerTable {
  char pad00[0x58];
  PeerSlot slots[PEER_SLOT_COUNT]; /* 0x58 */
  char pad0c8[0x16c - 0x58 - 7 * PEER_SLOT_COUNT];
  int matching_id;      /* 0x16c matching handle */
  char pad170[0x198 - 0x170];
  int cur;              /* 0x198 index of the local slot, skipped by the scans */
} PeerTable;

#endif
