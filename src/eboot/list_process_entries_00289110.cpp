/* HSTMATCH module=EBOOT.BIN start=0x00289110 end=0x002891ec symbol=FUN_00289110 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Item { int id; int count; int a; float f; int b; };
struct ListNode { ListNode *prev; ListNode *next; Item v; };
struct ListIt {
    ListNode *n;
    ListIt(ListNode *p) : n(p) {}
    ListIt(const ListIt &o) : n(o.n) {}
};
struct NodeList {
    int size;
    ListNode head;
};
struct Obj {
    char pad[0x64];
    NodeList list;
};
extern "C" {
void FUN_002879e0(Obj *, int, float, int, int, int);
ListIt FUN_002894d4(NodeList *l, ListIt pos);
}

extern "C" void FUN_00289110(Obj *o)
{
    bool found;
    for (int n = 0; n < 300; n++) {
        found = false;
        ListIt it(o->list.head.next);
        ListNode *end = &o->list.head;
        while (it.n != end) {
            Item *v = &it.n->v;
            if (v->id != 0x49) {
                it.n = it.n->next;
            } else {
                found = true;
                if (--v->count <= 0) {
                    FUN_002879e0(o, v->a, v->f, v->b, 0, 1);
                    it = FUN_002894d4(&o->list, it);
                } else {
                    it.n = it.n->next;
                }
            }
        }
        if (!found) break;
    }
}
// Notes: up to 300 passes over the doubly-linked list at +0x64; an entry with id 0x49 has its count decremented
// and, when it reaches zero, FUN_002879e0 is called for it and it is erased with the erase(pos) at 0x2894d4.
// Matching idioms: `found` is declared before the for statement (n gets s2, found s3), the item pointer `v` is
// taken before the id test (all item accesses go through one register), and FUN_002879e0 is prototyped
// (Obj *, int, float, int, int, int) so the argument loads follow retail's order.
