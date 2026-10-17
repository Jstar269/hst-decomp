/* HSTMATCH module=hstp_trans_main.prx start=0x0019f69c end=0x0019f728 symbol=FUN_0019f69c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct VC_0 { virtual ~VC_0(); };
struct Node { Node *prev; Node *next; VC_0 *item; };
struct Obj { int f0; int f4; Node sentinel; };

extern "C" void FUN_0019f728(char *, int *, Node **, Node **);

extern "C" void FUN_0019f69c(Obj *self)
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
    FUN_0019f728(ret, &self->f4, &first, &last);
}
