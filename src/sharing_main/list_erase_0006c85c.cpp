/* HSTMATCH module=hstp_trans_main.prx start=0x0006c85c end=0x0006c8fc symbol=FUN_0006c85c lang=c++ */
/* Clone of src/eboot/list_erase_0001f64c.cpp (hstclone.py tag x9): addresses substituted; exact match verified; names and types await human review. */
/* Doubly-linked list erase(first, last): unlink [first, last), then free each node, advancing first and
   decrementing the size; the result iterator is last. Names provisional. */
struct Node_0006c85c { Node_0006c85c *prev; Node_0006c85c *next; };
struct It_0006c85c { Node_0006c85c *node; };
extern "C" void FUN_0006c85c(It_0006c85c *ret, int *size, It_0006c85c *first, It_0006c85c *last)
{
    Node_0006c85c *f = first->node;
    Node_0006c85c *l = last->node;
    if (f == l) {
        ret->node = l;
        return;
    }
    Node_0006c85c *lp = l->prev;
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
