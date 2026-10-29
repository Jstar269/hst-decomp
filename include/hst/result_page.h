/* Page object of the result-page handlers: the fields they touch, at their offsets (same object as ResultScreen). */
#ifndef HST_RESULT_PAGE_H
#define HST_RESULT_PAGE_H

#include "hst/result_screen.h"

typedef struct ResultPage {
  char pad00[0x3c];
  ResultUi *ui;        /* 0x3c widget table */
  char pad40[0x7d0];
  void *lay810;        /* 0x810 layout of the first page */
  char pad814[0x21e4 - 0x814];
  void *return_lay;    /* 0x21e4 layout of the return page */
  char pad21e8[0x2350 - 0x21e8];
  int unk2350;         /* 0x2350 set from the game's current selection */
  int unk2354;         /* 0x2354 */
  int unk2358;         /* 0x2358 */
  char pad235c[0x2464 - 0x235c];
  void *lay2464;       /* 0x2464 */
  char pad2468[4];
  ScoreBox *score_box; /* 0x246c */
  char pad2470[0x250c - 0x2470];
  void *lose_lay;      /* 0x250c layout of the lose page */
  char pad2510[0x2528 - 0x2510];
  int unk2528;         /* 0x2528 */
  char unk252c[0x8c];  /* 0x252c sub-object */
  void *overlay_lay;   /* 0x25b8 layout of the result overlay */
} ResultPage;

#endif
