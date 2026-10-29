/* Object that spins and grows each tick and carries a placement position and a 4x4 matrix. */
#ifndef HST_SPIN_OBJ_H
#define HST_SPIN_OBJ_H

typedef struct SpinVec4 {
  float x, y, z, w;
} __attribute__((aligned(16))) SpinVec4;

typedef struct SpinMat4 {
  SpinVec4 r0, r1, r2, r3;
} SpinMat4;

typedef struct SpinObj {
  char pad00[0x40];
  float timer;       /* 0x40 counts down each tick; the matrix is built while it is not negative */
  char pad44[0x310 - 0x44];
  float scale;       /* 0x310 grows each tick */
  int angle;         /* 0x314 degrees, wraps at 360 */
  int ticks;         /* 0x318 */
  char pad31c[0x330 - 0x31c];
  float px, py, pz;  /* 0x330 position */
  char pad33c[0x340 - 0x33c];
  SpinMat4 mat;      /* 0x340 */
} SpinObj;

#endif
