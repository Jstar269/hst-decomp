/* HSTMATCH module=hstp_trans_main.prx start=0x0015b32c end=0x0015b3cc symbol=FUN_0015b32c lang=c++ */
/* Clone of src/eboot/list_erase_0001f64c.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
/* Doubly-linked list erase(first, last): unlink [first, last), then free each node, advancing first and
   decrementing the size; the result iterator is last. Names provisional. */
struct Node_0015b32c { Node_0015b32c *prev; Node_0015b32c *next; };
struct It_0015b32c { Node_0015b32c *node; };
extern "C" void FUN_0015b32c(It_0015b32c *ret, int *size, It_0015b32c *first, It_0015b32c *last)
{
    Node_0015b32c *f = first->node;
    Node_0015b32c *l = last->node;
    if (f == l) {
        ret->node = l;
        return;
    }
    Node_0015b32c *lp = l->prev;
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
