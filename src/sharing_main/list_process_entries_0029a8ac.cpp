/* HSTMATCH module=hstp_trans_main.prx start=0x0029a8ac end=0x0029a988 symbol=FUN_0029a8ac lang=c++ */
/* Clone of src/eboot/list_process_entries_00289110.cpp (hstclone.py tag s10170158a3r1s): addresses substituted; exact match verified; names and types await human review. */
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
void FUN_00299114(Obj *, int, float, int, int, int);
ListIt FUN_0029ac70(NodeList *l, ListIt pos);
}

extern "C" void FUN_0029a8ac(Obj *o)
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
                    FUN_00299114(o, v->a, v->f, v->b, 0, 1);
                    it = FUN_0029ac70(&o->list, it);
                } else {
                    it.n = it.n->next;
                }
            }
        }
        if (!found) break;
    }
}
// Notes: up to 300 passes over the doubly-linked list at +0x64; an entry with id 0x49 has its count decremented
// and, when it reaches zero, FUN_00299114 is called for it and it is erased with the erase(pos) at 0x2894d4.
// Matching idioms: `found` is declared before the for statement (n gets s2, found s3), the item pointer `v` is
// taken before the id test (all item accesses go through one register), and FUN_00299114 is prototyped
// (Obj *, int, float, int, int, int) so the argument loads follow retail's order.
