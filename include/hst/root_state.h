/* Global root object: current mode word at 0x3c and pointers to subsystem objects. */
#ifndef HST_ROOT_STATE_H
#define HST_ROOT_STATE_H

#define ROOT_MODE_SPECIAL 7 /* mode value the update helpers treat as an override */

typedef struct RootState {
  char pad00[0x3c];
  int mode;       /* 0x3c */
  char pad40[0x88 - 0x40];
  void *unk88;    /* 0x88 */
  char pad8c[4];
  void *unk90;    /* 0x90 */
  char pad94[0x9c - 0x94];
  int unk9c;      /* 0x9c */
} RootState;

#endif
