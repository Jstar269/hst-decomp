/* Object built by its constructor: six vectors, a sub-container, an owned object, the mode and its entry. */
#ifndef HST_STAGE_OBJ_H
#define HST_STAGE_OBJ_H

#include "hst/types.h"
#include "hst/vec.h"

/* Values of StageObj.mode that the mode setter handles. */
enum {
  STAGE_MODE_ENTRY_A = 2,   /* set up the entry for the given index */
  STAGE_MODE_ENTRY_B = 3,   /* same set-up as ENTRY_A */
  STAGE_MODE_FORWARD = 4    /* forward the call to the global object */
};

#define STAGE_ENTRY_TABLE_BASE 0x4e8  /* word index of the entry pointer table inside the global table */

typedef struct StageObj {
  void *vtbl;             /* 0x00 */
  char pad04[0x6c];
  Float4 vec70;           /* 0x70 */
  Float4 vec80;           /* 0x80 */
  Float4 vec90;           /* 0x90 */
  Float4 veca0;           /* 0xa0 */
  Float4 vecb0;           /* 0xb0 */
  Float4 vecc0;           /* 0xc0 */
  int sub[4];             /* 0xd0 sub-container with its own constructor and destructor */
  void *owned;            /* 0xe0 object deleted by the destructor */
  u8 unke4;               /* 0xe4 */
  char pade5[3];
  int unke8;              /* 0xe8 */
  u8 unkec;               /* 0xec */
  char padED[3];
  int mode;               /* 0xf0 */
  int unkf4;              /* 0xf4 */
  void **entry;           /* 0xf8 points at the entry pointer inside the global table */
  char padfc[4];
  char data100[0x50];     /* 0x100 */
  char data150[0xf0];     /* 0x150 */
  float unk240;           /* 0x240 */
} StageObj;

#endif
