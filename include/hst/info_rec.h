/* Record returned by FUN_0027edbc(table, index): three halfwords at 0x0a that say how many slots are lit. */
#ifndef HST_INFO_REC_H
#define HST_INFO_REC_H

typedef struct InfoRec {
  char pad0[0xa];
  short unkA;                   /* 0x0a added to a base index */
  short slotsA;                 /* 0x0c number of lit slots in the first row */
  short slotsB;                 /* 0x0e number of lit slots in the second row */
} InfoRec;

#endif
