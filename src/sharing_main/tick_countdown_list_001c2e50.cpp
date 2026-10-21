/* HSTMATCH module=hstp_trans_main.prx start=0x001c2e50 end=0x001c2f68 symbol=FUN_001c2e50 lang=c++ */
/* Clone of src/eboot/tick_countdown_list_001b523c.cpp (hstclone.py tag c21sn6s): addresses substituted; exact match verified; names and types await human review. */
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
void FUN_001c4fe8(Obj *);
void FUN_001c5224(Obj *);
void FUN_001c5324(Obj *);
void FUN_001c5800(Obj *);
void FUN_001c5ae4(Obj *);
void FUN_001c5ca4(Obj *);
void FUN_001c5d10(Obj *);
void FUN_001c5ee4(Obj *);
}

extern "C" void FUN_001c2e50(Obj *self)
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
    FUN_001c4fe8(self);
    FUN_001c5224(self);
    FUN_001c5324(self);
    FUN_001c5800(self);
    FUN_001c5ae4(self);
    FUN_001c5ca4(self);
    FUN_001c5d10(self);
    FUN_001c5ee4(self);
}
