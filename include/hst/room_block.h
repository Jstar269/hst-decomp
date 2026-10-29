/* 0x6c-byte sub-record shared by the room record and the sequence info record; cleared, then three shorts set to -1. */
#ifndef HST_ROOM_BLOCK_H
#define HST_ROOM_BLOCK_H

typedef struct RoomBlock {
  char unk0[0x24];                  /* 0x00 */
  short unk24;                      /* 0x24 -1 after reset */
  char unk26[0x68 - 0x26];          /* 0x26 */
  short unk68;                      /* 0x68 -1 after reset */
  short unk6a;                      /* 0x6a -1 after reset */
} RoomBlock;                        /* size 0x6c */

#endif
