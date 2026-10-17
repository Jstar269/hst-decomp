/* HSTMATCH module=EBOOT.BIN start=0x00192f18 end=0x00192fb8 symbol=FUN_00192f18 lang=c++ */
/* Clone of src/eboot/list_erase_0014f188.cpp (hstclone.py tag c13): addresses substituted; exact match verified; names and types await human review. */
/* Doubly-linked list erase(first, last): unlink [first, last), then free each node, advancing first and
   decrementing the size; the result iterator is last. Names provisional. */
struct Node_00192f18 { Node_00192f18 *prev; Node_00192f18 *next; };
struct It_00192f18 { Node_00192f18 *node; };
extern "C" void FUN_00192f18(It_00192f18 *ret, int *size, It_00192f18 *first, It_00192f18 *last)
{
    Node_00192f18 *f = first->node;
    Node_00192f18 *l = last->node;
    if (f == l) {
        ret->node = l;
        return;
    }
    Node_00192f18 *lp = l->prev;
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
