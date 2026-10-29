/* Kind selector of the id-to-table mapping: a flat id is split into a kind and an index inside that kind's table. */
#ifndef HST_ENTRY_KIND_H
#define HST_ENTRY_KIND_H

enum EntryKind {
  ENTRY_KIND_NONE = -1,   /* id outside every range */
  ENTRY_KIND_0 = 0,
  ENTRY_KIND_1 = 1,
  ENTRY_KIND_2 = 2,
  ENTRY_KIND_3 = 3,
  ENTRY_KIND_4 = 4,
  ENTRY_KIND_5 = 5,
  ENTRY_KIND_6 = 6,
  ENTRY_KIND_7 = 7,
  ENTRY_KIND_10 = 10,
  ENTRY_KIND_11 = 11
};

#endif
