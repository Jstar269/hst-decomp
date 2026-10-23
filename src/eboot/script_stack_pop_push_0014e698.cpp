/* HSTMATCH module=EBOOT.BIN start=0x0014e698 end=0x0014e7d0 symbol=FUN_0014e698 lang=c++ helpers=FUN_0014c610@0x0014c610-0x0014c63c */
/* Hand-written reconstruction from the disassembly (near miss wip/script_stack_pop_push_0014e698.cpp, completed with its same-file static helper FUN_0014c610 defined in front of it and placed at its own retail address by helpers=); exact match verified; names and types await human review. */
struct Node { Node *prev; Node *next; int value; };
struct List { int size_; Node *head_; };
struct Obj { char pad[0x18]; List list; };
struct EraseIt {
  Node *node;
  EraseIt(Node *n) : node(n) {}
  EraseIt(const EraseIt &o) : node(o.node) {}
};
struct InsertIt {
  Node *node_;
  InsertIt(Node *n) : node_(n) {}
};

extern "C" {
static void FUN_0014c610(...) {}
extern unsigned char DAT_003402f0;
extern char DAT_002dc240[];
extern char DAT_002dc24c[];
extern char DAT_002dc32c[];
extern char DAT_002dc31c[];
extern char DAT_002dc324[];
EraseIt FUN_0014f3cc(List *l, EraseIt pos);
InsertIt FUN_0014f43c(List *l, const InsertIt &pos, const int &x);
}


extern "C" int FUN_0014e698(int unused, Obj *obj)
{
  Node *first = obj->list.head_;
  int state = first->value;
  FUN_0014f3cc(&obj->list, EraseIt(first));
  if (DAT_003402f0 != 0) {
    if (DAT_003402f0 != 0) {
      FUN_0014c610(DAT_002dc240);
      for (int i = 0; i < obj->list.size_ + 1; i++)
        FUN_0014c610(DAT_002dc24c);
    }
    FUN_0014c610(DAT_002dc32c);
  }
  if (state == 1) {
    int v = 0;
    FUN_0014f43c(&obj->list, InsertIt((Node *)&obj->list.head_), v);
    if (DAT_003402f0 != 0)
      FUN_0014c610(DAT_002dc31c);
  } else {
    int v = 2;
    FUN_0014f43c(&obj->list, InsertIt((Node *)&obj->list.head_), v);
    if (DAT_003402f0 != 0)
      FUN_0014c610(DAT_002dc324);
  }
  return 0;
}
