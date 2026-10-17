/* HSTMATCH module=EBOOT.BIN start=0x0006792c end=0x000679cc symbol=FUN_0006792c lang=c++ */
/* Clone of src/eboot/list_erase_0014f188.cpp (hstclone.py tag c13): addresses substituted; exact match verified; names and types await human review. */
/* Doubly-linked list erase(first, last): unlink [first, last), then free each node, advancing first and
   decrementing the size; the result iterator is last. Names provisional. */
struct Node_0006792c { Node_0006792c *prev; Node_0006792c *next; };
struct It_0006792c { Node_0006792c *node; };
extern "C" void FUN_0006792c(It_0006792c *ret, int *size, It_0006792c *first, It_0006792c *last)
{
    Node_0006792c *f = first->node;
    Node_0006792c *l = last->node;
    if (f == l) {
        ret->node = l;
        return;
    }
    Node_0006792c *lp = l->prev;
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
