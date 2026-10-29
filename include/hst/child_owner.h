/* Object whose first word is an owned child object (used by the deleting destructors that only delete it). */
#ifndef HST_CHILD_OWNER_H
#define HST_CHILD_OWNER_H

typedef struct ChildOwner {
  void *child;    /* 0x0 owned child with a virtual destructor */
} ChildOwner;

#endif
