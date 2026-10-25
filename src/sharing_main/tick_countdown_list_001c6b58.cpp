/* HSTMATCH module=hstp_trans_main.prx start=0x001c6b58 end=0x001c6c2c symbol=FUN_001c6b58 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct Entry { int key; int count; int *out; int *dep; };
struct Node { Node *prev; Node *next; Entry value; };
struct It {
    Node *node;
    It(Node *n) : node(n) {}
    It(const It &o) : node(o.node) {}
    Entry &operator*() const { return node->value; }
};
struct List { int size; Node *prev; Node *next; };
struct Obj { char pad[0x3c]; List list; };

extern int DAT_003eaad8;
extern "C" {
void FUN_001bfbd8(int *);
int FUN_001c0010(int *, int);
int FUN_001c0ce8(int *, int);
It FUN_001c7284(List *, It);
}

extern "C" void FUN_001c6b58(Obj *self)
{
    FUN_001bfbd8(&DAT_003eaad8);
    It it(self->list.next);
    Node *end = (Node *)&self->list.prev;
    while (it.node != end) {
        Entry &e = *it;
        if (--e.count <= 0 && (e.dep == 0 || FUN_001c0010(&DAT_003eaad8, *e.dep) == 0)) {
            int r = FUN_001c0ce8(&DAT_003eaad8, e.key);
            if (e.out != 0) {
                *e.out = r;
            }
            it = FUN_001c7284(&self->list, it);
        } else {
            it.node = it.node->next;
        }
    }
}
