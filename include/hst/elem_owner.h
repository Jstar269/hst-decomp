/* Object of the 0xe9000 sources: two 0x50-byte elements, one owned member deleted through its virtual destructor, and a few plain fields. */
#ifndef HST_ELEM_OWNER_H
#define HST_ELEM_OWNER_H

#include "hst/types.h"

#define OWNER_ELEM_COUNT 2

#ifdef __cplusplus
/* Owned member: only its virtual destructor is used. */
struct MemberObj {
  virtual ~MemberObj();
};
#else
typedef struct MemberObj MemberObj;
#endif

/* Element of the array in the owner (0x50 bytes); its vtable pointer sits at 0x40. */
typedef struct ElemSlot {
  char pad00[0x40];
  void *vtable;                     /* 0x40 */
  char pad44[0xc];
} ElemSlot;

typedef struct ElemOwner {
  void *vtable;                     /* 0x000 */
  char pad04[0x38];
  u32 unk3c;                        /* 0x03c constructor argument */
  char pad40[0x540 - 0x40];
  MemberObj *member;                /* 0x540 deleted and cleared by the member delete */
  char pad544[0x550 - 0x544];
  ElemSlot elem[OWNER_ELEM_COUNT];  /* 0x550 */
  float unk5f0;                     /* 0x5f0 */
  int unk5f4;                       /* 0x5f4 */
  int unk5f8;                       /* 0x5f8 */
  int unk5fc;                       /* 0x5fc */
} ElemOwner;

#endif
