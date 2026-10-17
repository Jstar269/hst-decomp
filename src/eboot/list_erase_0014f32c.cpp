/* HSTMATCH module=EBOOT.BIN start=0x0014f32c end=0x0014f3cc symbol=FUN_0014f32c lang=c++ */
/* Clone of src/eboot/list_erase_0014f188.cpp (hstclone.py tag c13): addresses substituted; exact match verified; names and types await human review. */
/* Doubly-linked list erase(first, last): unlink [first, last), then free each node, advancing first and
   decrementing the size; the result iterator is last. Names provisional. */
struct Node_0014f32c { Node_0014f32c *prev; Node_0014f32c *next; };
struct It_0014f32c { Node_0014f32c *node; };
extern "C" void FUN_0014f32c(It_0014f32c *ret, int *size, It_0014f32c *first, It_0014f32c *last)
{
    Node_0014f32c *f = first->node;
    Node_0014f32c *l = last->node;
    if (f == l) {
        ret->node = l;
        return;
    }
    Node_0014f32c *lp = l->prev;
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
