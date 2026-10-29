/* Global configuration block read by the quad-slot sources: two index words. */
#ifndef HST_QUAD_CONFIG_H
#define HST_QUAD_CONFIG_H

typedef struct QuadConfig {
  char pad00[0x4c];
  int unk4c; /* 0x4c indexes a stride-3 table in the entry record */
  int unk50; /* 0x50 index compared with the slot loop counter */
} QuadConfig;

#endif
