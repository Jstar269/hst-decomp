/* HSTMATCH module=hstp_trans_main.prx start=0x0015a628 end=0x0015a760 symbol=FUN_0015a628 lang=c++ helpers=FUN_00157280@0x00157280-0x001572ac */
/* Clone of src/eboot/script_stack_pop_push_0014e698.cpp (hstclone.py tag a0db26h2): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (near miss wip/script_stack_pop_push_0015a628.cpp, completed with its same-file static helper FUN_00157280 defined in front of it and placed at its own retail address by helpers=); exact match verified; names and types await human review. */
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
static void FUN_00157280(...) {}
extern unsigned char DAT_003e9630;
extern char DAT_003836b8[];
extern char DAT_003836c4[];
extern char DAT_00383814[];
extern char DAT_00383804[];
extern char DAT_0038380c[];
EraseIt FUN_0015b3cc(List *l, EraseIt pos);
InsertIt FUN_0015b43c(List *l, const InsertIt &pos, const int &x);
}


extern "C" int FUN_0015a628(int unused, Obj *obj)
{
  Node *first = obj->list.head_;
  int state = first->value;
  FUN_0015b3cc(&obj->list, EraseIt(first));
  if (DAT_003e9630 != 0) {
    if (DAT_003e9630 != 0) {
      FUN_00157280(DAT_003836b8);
      for (int i = 0; i < obj->list.size_ + 1; i++)
        FUN_00157280(DAT_003836c4);
    }
    FUN_00157280(DAT_00383814);
  }
  if (state == 1) {
    int v = 0;
    FUN_0015b43c(&obj->list, InsertIt((Node *)&obj->list.head_), v);
    if (DAT_003e9630 != 0)
      FUN_00157280(DAT_00383804);
  } else {
    int v = 2;
    FUN_0015b43c(&obj->list, InsertIt((Node *)&obj->list.head_), v);
    if (DAT_003e9630 != 0)
      FUN_00157280(DAT_0038380c);
  }
  return 0;
}
