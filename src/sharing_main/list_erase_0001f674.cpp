/* HSTMATCH module=hstp_trans_main.prx start=0x0001f674 end=0x0001f714 symbol=FUN_0001f674 lang=c++ */
/* Clone of src/eboot/list_erase_0001f64c.cpp (hstclone.py tag x9): addresses substituted; exact match verified; names and types await human review. */
/* Doubly-linked list erase(first, last): unlink [first, last), then free each node, advancing first and
   decrementing the size; the result iterator is last. Names provisional. */
struct Node_0001f674 { Node_0001f674 *prev; Node_0001f674 *next; };
struct It_0001f674 { Node_0001f674 *node; };
extern "C" void FUN_0001f674(It_0001f674 *ret, int *size, It_0001f674 *first, It_0001f674 *last)
{
    Node_0001f674 *f = first->node;
    Node_0001f674 *l = last->node;
    if (f == l) {
        ret->node = l;
        return;
    }
    Node_0001f674 *lp = l->prev;
    f->prev->next = lp->next;
    lp->next->prev = f->prev;
    while (f != l) {
        first->node = f->next;
        delete f;
        l = last->node;
        f = first->node;
        --*size;
    }
    ret->node = l;
}
