/* Byte ring that the stream helpers read from, and the owner object that points at it. */
#ifndef HST_RING_OWNER_H
#define HST_RING_OWNER_H

typedef struct RingBuf {
  char pad00[0xc];
  int unk0c;       /* 0x0c position pair: both cleared on reset, */
  int unk10;       /* 0x10 their difference is the byte count available */
} RingBuf;

typedef struct RingOwner {
  char pad00[0x1c];
  RingBuf *ring;   /* 0x1c */
} RingOwner;

#endif
