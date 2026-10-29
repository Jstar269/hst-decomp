/* Display controller object kept in a global singleton slot: owned object, state id and two words. */
#ifndef HST_DISP_CTX_H
#define HST_DISP_CTX_H

typedef struct DispCtx {
  void *obj;  /* 0x00 owned object (virtual interface) */
  int state;  /* 0x04 state id, switched on after changes */
  int unk8;   /* 0x08 set to 9 in states 2 and 4 */
  int unkc;   /* 0x0c initialised to -1 */
} DispCtx;

#endif
