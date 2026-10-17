/* HSTMATCH module=EBOOT.BIN start=0x00192e8c end=0x00192f18 symbol=FUN_00192e8c lang=c++ */
/* Clone of src/sharing_main/delete_list_items_0019f69c.cpp (hstclone.py tag s10170158a1r3e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct VC_0 { virtual ~VC_0(); };
struct Node { Node *prev; Node *next; VC_0 *item; };
struct Obj { int f0; int f4; Node sentinel; };

extern "C" void FUN_00192f18(char *, int *, Node **, Node **);

extern "C" void FUN_00192e8c(Obj *self)
{
    char ret[12];
    Node *first;
    Node *last;
    Node *n = self->sentinel.next;
    Node *end = &self->sentinel;
    if (n != end) {
        do {
            delete n->item;
            n = n->next;
        } while (n != end);
    }
    last = &self->sentinel;
    first = self->sentinel.next;
    FUN_00192f18(ret, &self->f4, &first, &last);
}
