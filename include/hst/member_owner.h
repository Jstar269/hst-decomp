/* Object that owns a block of released-on-destroy members (constructed zeroed, released by its member-release helper). */
#ifndef HST_MEMBER_OWNER_H
#define HST_MEMBER_OWNER_H

enum { OWNED_MEMBERS = 18 };

typedef struct MemberOwner {
  const void *vtable;                   /* 0x0 */
  char pad04[0x50];
  void *members[OWNED_MEMBERS];         /* 0x54 owned pointers, all cleared by the constructor */
  char pad9c[0x156 - 0x9c];
  unsigned char unk156;                 /* 0x156 */
} MemberOwner;

#endif
