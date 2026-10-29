/* Object with a word at +0x40, a call counter and a pointer that gates the forwarded calls. */
#ifndef HST_STEP_OBJ_H
#define HST_STEP_OBJ_H

typedef struct StepObj {
  char pad00[0x40];
  unsigned unk40;     /* 0x40 */
  char pad44[0x64 - 0x44];
  int calls;          /* 0x64 incremented once per forwarded call */
  char pad68[0x90 - 0x68];
  void *gate;         /* 0x90 calls are forwarded only while this is set */
} StepObj;

#endif
