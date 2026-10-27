/* HSTMATCH module=hstp_trans_main.prx start=0x0001ef34 end=0x0001f054 symbol=FUN_0001ef34 lang=c++ data=0x003752c0 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (2 strings, 0x003752c0-0x0037532c) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* task.cpp: Task::AddChild(pchild) as the assertion texts name it: three asserts (each prints through the variadic
   stub 0x1ecfc and spins), ListChild.push_back(pchild) through the out-of-line list insert 0x1f784, both child
   iterators reset to ListChild.end(), parent link, and three slot values inherited from the parent. */
extern "C" {
void FUN_0001ecfc(...);
extern int DAT_003b915c; /* task_delete_cnt */
extern char DAT_0037521c[]; /* "assertion \"%s\" failed: file \"%s\", line %d\n" */
extern char DAT_00375248[]; /* "!task_delete_cnt" */
extern char DAT_0037525c[]; /* "task.cpp" */
}

struct Task;
struct Node {
  Node *prev_;
  Node *next_;
  Task *value_;
};
struct It {
  Node *node_;
  It() {}
  It(Node *n) : node_(n) {}
};
struct NodeBase {
  Node *prev_;
  Node *next_;
};
struct TaskList {
  unsigned size_;
  NodeBase end_;
  It end() { return It((Node *)&end_); }
};
extern "C" It FUN_0001f784(TaskList *l, const It &pos, Task *const &x);

struct Slot {
  unsigned char on;
  int value;
};

struct Task {
  void *vptr;
  int KeyCode;
  TaskList ListChild;
  It ProcChildIterator;
  It MessageChildIterator;
  Task *parent;
  int f20;
  Slot slot[3];
};

#define KEYCODE 0x1234567

/* Task::AddChild */
extern "C" void FUN_0001ef34(Task *self, Task *pchild)
{
  if (DAT_003b915c != 0) {
    FUN_0001ecfc(DAT_0037521c, DAT_00375248, DAT_0037525c, 198);
    for (;;) {
    }
  }
  if (pchild->KeyCode != KEYCODE) {
    FUN_0001ecfc(DAT_0037521c, "pchild->KeyCode == KEYCODE", DAT_0037525c, 200);
    for (;;) {
    }
  }
  if (!(self->ProcChildIterator.node_ == self->ListChild.end().node_ &&
        self->MessageChildIterator.node_ == self->ListChild.end().node_)) {
    FUN_0001ecfc(DAT_0037521c, "ProcChildIterator == ListChild.end() && MessageChildIterator == ListChild.end()", DAT_0037525c, 216);
    for (;;) {
    }
  }
  FUN_0001f784(&self->ListChild, self->ListChild.end(), pchild);
  self->ProcChildIterator = self->ListChild.end();
  self->MessageChildIterator = self->ListChild.end();
  pchild->parent = self;
  pchild->slot[0].value = self->slot[0].value;
  pchild->slot[1].value = self->slot[1].value;
  pchild->slot[2].value = self->slot[2].value;
}
