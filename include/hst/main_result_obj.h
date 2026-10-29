/* Object built by the main-result constructor: vtable, a mode word, a child object and two looked-up items. */
#ifndef HST_MAIN_RESULT_OBJ_H
#define HST_MAIN_RESULT_OBJ_H

typedef struct MainResultObj {
  const void *vtable;  /* 0x00 */
  char pad04[0x54 - 4];
  int mode;            /* 0x54 set to 5 by the constructor */
  void *child;         /* 0x58 */
  void *items[2];      /* 0x5c looked up from the child */
  char pad64[0x8c - 0x64];
  void *unk8c;         /* 0x8c */
} MainResultObj;

#endif
