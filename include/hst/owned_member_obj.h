/* Object with a vtable and one owned member (a polymorphic sub-object deleted by the destructor). */
#ifndef HST_OWNED_MEMBER_OBJ_H
#define HST_OWNED_MEMBER_OBJ_H

#include "hst/types.h"

typedef struct OwnedMemberObj {
  u32 vtable;          /* 0x00 */
  char pad04[0x38];    /* base part set up by its own constructor */
  void *member;        /* 0x3c owned sub-object, deleted and cleared by the destructor */
  u8 unk40;            /* 0x40 */
  u8 unk41;            /* 0x41 */
  char pad42[2];
  u32 unk44;           /* 0x44 */
} OwnedMemberObj;

#endif
