/* Growable-array header (data, size, capacity) and the helpers its reserve/shrink sources share. */
#ifndef HST_VEC_RESERVE_H
#define HST_VEC_RESERVE_H

typedef struct RawVec {
  void *data;        /* 0x00 element storage */
  int size;          /* 0x04 elements in use */
  unsigned capacity; /* 0x08 elements allocated */
} RawVec;

#ifdef __cplusplus
/* newlib reent block: stderr stream at +0xc. */
struct Reent {
  int pad[3];
  void *err;
};

extern "C" {
Reent *FUN_0000fe3c(void);
int FUN_00165ef4(void *stream, const char *format, ...); /* fprintf */
void FUN_0000d518(void);                                  /* abort */
void FUN_000043b4(void);                                  /* length-error handler */
void *FUN_00000bcc(unsigned size);                        /* operator new */
}

#endif

#endif
