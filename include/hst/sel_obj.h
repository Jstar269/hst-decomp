/* Object with a flag byte and a handle that FUN_0025346c refreshes from a mode computed out of the flag. */
#ifndef HST_SEL_OBJ_H
#define HST_SEL_OBJ_H

typedef struct SelObj {
  char pad0[0x34];
  unsigned char unk34;          /* 0x34 selects mode 2 instead of 1 when refreshing */
  char pad35[3];
  int handle;                   /* 0x38 result of the last refresh */
  char sub3c[1];                /* 0x3c sub-object passed to the refresh call */
} SelObj;

#endif
