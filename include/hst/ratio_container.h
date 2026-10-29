/* Container of 0xa0-byte elements whose count fields feed the ratio/percentage calculators. */
#ifndef HST_RATIO_CONTAINER_H
#define HST_RATIO_CONTAINER_H

typedef struct RatioElem {
  char pad0[0x20];
  int unk20;         /* 0x20 */
  int unk24;         /* 0x24 */
  int unk28;         /* 0x28 */
  char pad2c[4];
  int unk30;         /* 0x30 */
  int unk34;         /* 0x34 */
  char pad38[0xa0 - 0x38];
} RatioElem;

typedef struct RatioContainer {
  char pad0[8];
  int countA;        /* 0x08 element count of the first list */
  int countB;        /* 0x0c element count of the second list */
  char pad10[0xc0 - 0x10];
  RatioElem items[1]; /* 0xc0 */
} RatioContainer;

#endif
