/* Layout pane object with a state id at 0x414, two polymorphic child nodes and a few handle fields (0x22f000 sources). */
#ifndef HST_STATEFUL_PANE_H
#define HST_STATEFUL_PANE_H

#ifdef __cplusplus
/* Child node: a polymorphic object; the sources call slots 1, 2 and 3. */
struct PaneNode {
  virtual void slot0();
  virtual void slot1(int arg);
  virtual void slot2();
  virtual void slot3();
};
#else
typedef struct PaneNode PaneNode;
#endif

/* Record the pane keeps a pointer to; only a flag byte is written. */
typedef struct PaneStateSub {
  char pad00[4];
  unsigned char unk04; /* 0x04 */
} PaneStateSub;

typedef struct StatefulPane {
  char pad00[0x54];
  unsigned char unk54;      /* 0x54 */
  char pad55[0xa4 - 0x55];
  int unka4;                /* 0xa4 */
  int unka8;                /* 0xa8 id; ids 0x28..0x31 select a table entry */
  int unkac;                /* 0xac id, -1 when none */
  int handle;               /* 0xb0 handle released through the table, -1 when none */
  int unkb4;                /* 0xb4 */
  unsigned char unkb8;      /* 0xb8 */
  char padb9[0x210 - 0xb9];
  PaneNode *node210;        /* 0x210 */
  PaneNode *node214;        /* 0x214 */
  char pad218[4];
  PaneStateSub *sub;            /* 0x21c */
  char pad220[0x414 - 0x220];
  int state;                /* 0x414 current state id (0..8) */
} StatefulPane;

/* Global manager object; the pane's state machine waits while it is busy. */
typedef struct StateMgr {
  char pad00[0x5d0];
  int busy;                 /* 0x5d0 */
} StateMgr;

#endif
