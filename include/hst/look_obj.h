/* Look/overlay state object with two vectors, scale values and two draw handles. */
#ifndef HST_LOOK_OBJ_H
#define HST_LOOK_OBJ_H

typedef struct LookVec4 {
  float x, y, z, w;
#ifdef __cplusplus
  LookVec4() {}
  LookVec4(const LookVec4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
#endif
} __attribute__((aligned(16))) LookVec4;

typedef struct LookObj {
  LookVec4 unk00;                 /* 0x000 vector scaled by unkE0 */
  float unk10;                    /* 0x010 angle in radians, used as a fraction of a quarter turn */
  int unk14;                      /* 0x014 count of entries drawn by the overlay */
  int unk18;                      /* 0x018 passed to the draw helper */
  char pad1c[0xdc - 0x1c];
  float unkdc;                    /* 0x0dc scale of the direction vector */
  float unke0;                    /* 0x0e0 scale of unk00 */
  int unke4;                      /* 0x0e4 step of the overlay fade */
  char pade8[0xf0 - 0xe8];
  unsigned int unkf0;             /* 0x0f0 packed colour, its top byte is replaced by the overlay alpha */
  float unkf4;                    /* 0x0f4 threshold subtracted from the ratio */
  char padf8[0x4e4 - 0xf8];
  unsigned char active;           /* 0x4e4 set when the look produced a visible overlay */
  char pad4e5[0x4f0 - 0x4e5];
  LookVec4 unk4f0;                /* 0x4f0 */
  LookVec4 unk500;                /* 0x500 */
  float unk510;                   /* 0x510 ratio, 0..1 of the overlay progress */
  float unk514;                   /* 0x514 */
  int unk518;                     /* 0x518 capped at 128 */
  int unk51c;                     /* 0x51c capped at 128 */
  int unk520;                     /* 0x520 draw handle */
  int unk524;                     /* 0x524 draw handle */
} LookObj;

#endif
