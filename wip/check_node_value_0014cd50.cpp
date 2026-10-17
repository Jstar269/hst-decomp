/* HSTMATCH module=EBOOT.BIN start=0x0014cd50 end=0x0014cdd0 symbol=FUN_0014cd50 lang=c++ */
/* Near-miss for check_node_value (32 words).
   Follows FUN_0014cd00.cpp. Checks whether node is valid (node != 0 && end != node + 4),
   then dispatches handler->getValue() or returns node->value, else 0.
   Differs only in bool temporary evaluation vs branch structure in node validation.
*/

struct Handler {
    virtual ~Handler();
    virtual void dummy();
    virtual int getValue();
};

struct Node {
    int pad0;
    int next;
    int pad8;
    int value;
};

struct Obj_0014cd50 {
    int pad0;
    Node *node;         /* +4 */
    Handler *handler;   /* +8 */
    int padc;
    int pad10;
    void *end;          /* +0x14 */
};

extern "C" int FUN_0014cd50(Obj_0014cd50 *self)
{
    Node *node = self->node;
    int has_item = 0;
    if (node != 0) {
        has_item = (node != 0) && (self->end != (void *)((char *)node + 4));
    }
    if (has_item) {
        if (self->handler != 0) {
            return self->handler->getValue();
        }
        return node->value;
    }
    return 0;
}
// near miss from lane u2r1-3 (unreviewed)
