/* C++ object with a 12-slot virtual interface (slot 11 returns the current mode id) and the request queue some of its subclasses carry. */
#ifndef HST_MODE_OBJ_H
#define HST_MODE_OBJ_H

struct VirtualModeObj {
  virtual int slot0();
  virtual int slot1();
  virtual int slot2();
  virtual int slot3();
  virtual int slot4();
  virtual int slot5();
  virtual int slot6();
  virtual int slot7();
  virtual int slot8();
  virtual int slot9();
  virtual int slot10();
  virtual int mode();
};

/* Node of a circular doubly linked list. */
struct QueueNode {
  QueueNode *prev; /* 0x00 */
  QueueNode *next; /* 0x04 */
};

/* List header: element count, then the sentinel node of the circular list. */
struct RequestList {
  int size;           /* 0x00 */
  QueueNode sentinel; /* 0x04 */
};

/* Mode object that queues request records into a circular list. */
struct QueueObj : VirtualModeObj {
  char pad04[0x60];
  RequestList queue;  /* 0x64 */
};

#endif
