/* Member-session object seen with its owned per-member objects (slots at 0x1dc) and the small records they point to. */
#ifndef HST_MEMBER_HOST_H
#define HST_MEMBER_HOST_H

#include "hst/member_session.h"

#define MEMBER_HOST_NO_CURRENT (-1) /* cur / found value when no member is selected */

#ifdef __cplusplus
/* Any object with a virtual destructor, owned through a base pointer. */
struct OwnedObj {
  virtual ~OwnedObj();
};
#endif

/* 0x14-byte record created per member; its vtable word is filled in by the creator. */
typedef struct MemberObjRec {
  const void *vptr;  /* 0x00 */
  int unk4;          /* 0x04 */
  int unk8;          /* 0x08 */
  int unkc;          /* 0x0c */
  unsigned char unk10; /* 0x10 */
} MemberObjRec;      /* size 0x14 */

#ifdef __cplusplus
typedef struct MemberHost {
  char pad00[0x58];
  MemberSlot members[MEMBER_MAX]; /* 0x58 */
  char pad0c8[0x190 - 0x58 - 7 * MEMBER_MAX];
  int count;                      /* 0x190 */
  int unk194;                     /* 0x194 */
  int cur;                        /* 0x198 index of the current member */
  char pad19c[0x1dc - 0x19c];
  OwnedObj *slots[MEMBER_MAX];    /* 0x1dc owned objects, one per member */
  unsigned char flags[MEMBER_MAX]; /* 0x21c */
  char pad22c[0x26c - 0x22c];
  OwnedObj *obj26c;               /* 0x26c */
} MemberHost;
#endif

#endif
