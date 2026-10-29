/* Global owner of a per-side tally block (counter words) and the side-info record used to compare sides. */
#ifndef HST_SIDE_TALLY_H
#define HST_SIDE_TALLY_H

typedef struct SideTally {
  char pad00[0x54];
  int unk54;        /* 0x54 */
  int unk58;        /* 0x58 */
  char pad5c[0x1f0 - 0x5c];
  int unk1f0;       /* 0x1f0 */
  int unk1f4;       /* 0x1f4 */
  int unk1f8;       /* 0x1f8 */
} SideTally;

typedef struct TallyOwner {
  char pad00[0xa0];
  SideTally *tally; /* 0xa0 */
} TallyOwner;

typedef struct SideInfo {
  char pad00[0x144];
  int unk144;       /* 0x144 side identifier compared with the arguments */
} SideInfo;

#endif
