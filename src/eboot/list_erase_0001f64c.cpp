/* HSTMATCH module=EBOOT.BIN start=0x0001f64c end=0x0001f6ec symbol=FUN_0001f64c lang=c++ */
/* Clone of src/eboot/list_erase_0014f188.cpp (hstclone.py tag c13): addresses substituted; exact match verified; names and types await human review. */
/* Doubly-linked list erase(first, last): unlink [first, last), then free each node, advancing first and
   decrementing the size; the result iterator is last. Names provisional. */
struct Node_0001f64c { Node_0001f64c *prev; Node_0001f64c *next; };
struct It_0001f64c { Node_0001f64c *node; };
extern "C" void FUN_0001f64c(It_0001f64c *ret, int *size, It_0001f64c *first, It_0001f64c *last)
{
    Node_0001f64c *f = first->node;
    Node_0001f64c *l = last->node;
    if (f == l) {
        ret->node = l;
        return;
    }
    Node_0001f64c *lp = l->prev;
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
