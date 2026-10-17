/* HSTMATCH module=EBOOT.BIN start=0x0027a2f4 end=0x0027a394 symbol=FUN_0027a2f4 lang=c++ */
/* Clone of src/eboot/list_erase_0014f188.cpp (hstclone.py tag c13): addresses substituted; exact match verified; names and types await human review. */
/* Doubly-linked list erase(first, last): unlink [first, last), then free each node, advancing first and
   decrementing the size; the result iterator is last. Names provisional. */
struct Node_0027a2f4 { Node_0027a2f4 *prev; Node_0027a2f4 *next; };
struct It_0027a2f4 { Node_0027a2f4 *node; };
extern "C" void FUN_0027a2f4(It_0027a2f4 *ret, int *size, It_0027a2f4 *first, It_0027a2f4 *last)
{
    Node_0027a2f4 *f = first->node;
    Node_0027a2f4 *l = last->node;
    if (f == l) {
        ret->node = l;
        return;
    }
    Node_0027a2f4 *lp = l->prev;
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
