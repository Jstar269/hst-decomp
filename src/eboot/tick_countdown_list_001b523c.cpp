/* HSTMATCH module=EBOOT.BIN start=0x001b523c end=0x001b5354 symbol=FUN_001b523c lang=c++ */
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

extern int DAT_0034179c;
extern "C" {
void FUN_001b1be0(int *);
int FUN_001b1f7c(int *, int);
int FUN_001b2bb8(int *, int);
It FUN_001b9598(List *, It);
void FUN_001b7328(Obj *);
void FUN_001b7564(Obj *);
void FUN_001b7664(Obj *);
void FUN_001b7b40(Obj *);
void FUN_001b7e24(Obj *);
void FUN_001b7fe4(Obj *);
void FUN_001b8050(Obj *);
void FUN_001b8224(Obj *);
}

extern "C" void FUN_001b523c(Obj *self)
{
    FUN_001b1be0(&DAT_0034179c);
    It it(self->list.next);
    Node *end = (Node *)&self->list.prev;
    while (it.node != end) {
        Entry &e = *it;
        if (--e.count <= 0 && (e.dep == 0 || FUN_001b1f7c(&DAT_0034179c, *e.dep) == 0)) {
            int r = FUN_001b2bb8(&DAT_0034179c, e.key);
            if (e.out != 0) {
                *e.out = r;
            }
            it = FUN_001b9598(&self->list, it);
        } else {
            it.node = it.node->next;
        }
    }
    FUN_001b7328(self);
    FUN_001b7564(self);
    FUN_001b7664(self);
    FUN_001b7b40(self);
    FUN_001b7e24(self);
    FUN_001b7fe4(self);
    FUN_001b8050(self);
    FUN_001b8224(self);
}
