/* Object with a mode, a position pair, two sub-objects and a state/velocity block. */
#ifndef HST_POSED_OBJ_H
#define HST_POSED_OBJ_H

/* Four-float vector with 16-byte alignment, as stored in the velocity field. */
typedef struct ObjVec4 {
  float x, y, z, w;
} __attribute__((aligned(16))) ObjVec4;

typedef struct PosedObj {
  char pad00[0x3c];
  int mode;                 /* 0x3c, changing it sets the dirty flag */
  float pos[4];             /* 0x40 */
  float pos2[4];            /* 0x50 */
  char pad60[0xe0 - 0x60];
  char sub_e0[0x290 - 0xe0];  /* 0xe0, sub-object */
  char sub_290[0x454 - 0x290];  /* 0x290, sub-object */
  int state;                /* 0x454 */
  int kind;                 /* 0x458, index into the per-kind float tables */
  int time;                 /* 0x45c */
  int pad460;
  unsigned char dirty;      /* 0x464 */
  char pad465[0xb];
  ObjVec4 vel;              /* 0x470 */
  char pad480[0x60];
  int started;              /* 0x4e0 */
} PosedObj;

#endif
