/* Partial view of the court object (the object held by one global pointer): a selection table and the mode word. */
#ifndef HST_COURT_VIEW_H
#define HST_COURT_VIEW_H

typedef struct CourtView {
  char pad000[0x140];
  int *table;       /* 0x140 entries indexed by selected */
  char pad144[0xd60 - 0x144];
  int selected;     /* 0xd60 index into table, negative when nothing is selected */
  char padd64[0x1364 - 0xd64];
  int mode;         /* 0x1364 */
} CourtView;

#endif
