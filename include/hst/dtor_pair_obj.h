/* Object with a vtable and two embedded sub-objects (at 0x4 and 0x10) that its destructor tears down. */
#ifndef HST_DTOR_PAIR_OBJ_H
#define HST_DTOR_PAIR_OBJ_H

typedef struct DtorPairObj {
  const void *vtable; /* 0x00 */
  int unk4;           /* 0x04 start of the first sub-object */
  int unk8;           /* 0x08 */
  int unkc;           /* 0x0c */
  int unk10;          /* 0x10 start of the second sub-object */
  int unk14;          /* 0x14 */
  int unk18;          /* 0x18 */
} DtorPairObj;

#endif
