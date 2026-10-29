/* HSTMATCH module=EBOOT.BIN start=0x001b523c end=0x001b5354 symbol=FUN_001b523c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Delayed sound start: wait delay frames, and for the sound in *waitFor to stop playing, then start sound key. */
struct Entry { int key; int delay; int *handleOut; int *waitFor; };
struct Node { Node *prev; Node *next; Entry value; };
struct It {
    Node *node;
    It(Node *n) : node(n) {}
    It(const It &o) : node(o.node) {}
    Entry &operator*() const { return node->value; }
};
struct List { int size; Node *prev; Node *next; };
struct Owner { char pad[0x3c]; List pending; /* 0x3c entries waiting to start */ };

extern int DAT_0034179c;
extern "C" {
void FUN_001b1be0(int *);
int FUN_001b1f7c(int *, int);
int FUN_001b2bb8(int *, int);
It FUN_001b9598(List *, It);
void FUN_001b7328(Owner *);
void FUN_001b7564(Owner *);
void FUN_001b7664(Owner *);
void FUN_001b7b40(Owner *);
void FUN_001b7e24(Owner *);
void FUN_001b7fe4(Owner *);
void FUN_001b8050(Owner *);
void FUN_001b8224(Owner *);
}

/* Per-frame update: count down the pending entries, start those that are due (storing the new handle), then run
   the eight sub-updates. */
extern "C" void FUN_001b523c(Owner *self)
{
    FUN_001b1be0(&DAT_0034179c);
    It it(self->pending.next);
    Node *end = (Node *)&self->pending.prev;
    while (it.node != end) {
        Entry &e = *it;
        if (--e.delay <= 0 && (e.waitFor == 0 || FUN_001b1f7c(&DAT_0034179c, *e.waitFor) == 0)) {
            int handle = FUN_001b2bb8(&DAT_0034179c, e.key);
            if (e.handleOut != 0) {
                *e.handleOut = handle;
            }
            it = FUN_001b9598(&self->pending, it);
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
