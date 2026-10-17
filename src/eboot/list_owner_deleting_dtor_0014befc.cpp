/* HSTMATCH module=EBOOT.BIN start=0x0014befc end=0x0014bfe0 symbol=FUN_0014befc lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: typed Link/Node/Obj structs, the virtual deleting-dtor call is `delete` of a polymorphic element, the dropped delete[]/delete arguments restored, the inlined list erase(first, last) call spelled out with its three locals; exact match verified; names and types await human review. */
struct Elem { virtual ~Elem(); };
struct Link { Link *prev; Link *next; };
struct Node : Link { Elem *e; };
struct Obj {
    int size;
    Link head;
    void *buf;
};
struct LIt { Link *n; LIt(Link *p) : n(p) {} };
struct It { Link *n; int pad[3]; };
extern "C" {
void FUN_000009e4(void *);
void FUN_00000a00(void *);
void FUN_0014f188(It *ret, Obj *l, Link **first, Link **last);
}

extern "C" Obj *FUN_0014befc(Obj *p, short flag)
{
    It ret;
    Link *first;
    Link *last;
    if (p != 0) {
        Link *end = &p->head;
        LIt it(end->next);
        while (it.n != end) {
            delete ((Node *)it.n)->e;
            it.n = it.n->next;
        }
        if (p->buf != 0) {
            FUN_000009e4(p->buf);
            p->buf = 0;
        }
        if (p != 0 && p != 0 && p != 0) {
            last = &p->head;
            first = p->head.next;
            FUN_0014f188(&ret, p, &first, &last);
        }
        if (0 < flag) FUN_00000a00(p);
    }
    return p;
}
// Matching idioms: the cursor is a one-pointer struct (LIt, keeps a stack home) with the end pointer read first
// (`Link *end = &p->head; LIt it(end->next);` gives s1 = cursor, s2 = end); the 16-byte iterator return slot `ret`
// and the two address-taken locals are declared at the function top (ret, first, last) and `last` is assigned
// before `first`; the triple `p != 0` test is retail's three inlined destructor layers.
