/* Object with a mode word, an embedded sub-object, two five-entry value histories and a frame counter. */
#ifndef HST_HIST_OBJ_H
#define HST_HIST_OBJ_H

#define HIST_DEPTH 5

typedef struct HistObj {
  char pad00[0x3c];
  int unk3c;                    /* 0x3c */
  char pad40[0x10];
  char unk50[1];                /* 0x50 embedded sub-object, passed by address (extent unknown) */
  char pad51[0x17cc - 0x51];
  int histA[HIST_DEPTH];        /* 0x17cc newest first */
  int histB[HIST_DEPTH];        /* 0x17e0 newest first */
  char pad17f4[0x1850 - 0x17f4];
  int unk1850;                  /* 0x1850 */
} HistObj;

#endif
