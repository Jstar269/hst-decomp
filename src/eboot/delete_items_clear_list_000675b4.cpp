/* HSTMATCH module=EBOOT.BIN start=0x000675b4 end=0x00067640 symbol=FUN_000675b4 lang=c++ */
/* Clone of src/sharing_main/delete_items_clear_list_00068a08.cpp (hstclone.py tag a0db26EBhs): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Shape: delete every list element through an inline for_each with an empty by-value functor (its slot is the never-written frame-top word), then an inline List::clear() forwarding to the out-of-line erase FUN_0006792c; a named end local keeps &head in s0. */
struct Item {
    virtual ~Item();
};

struct Node {
    Node *prev;
    Node *next;
    Item *value;
};

struct DeleteItem {
    void operator()(Item *p) const { delete p; }
};

static inline void ForEach(Node *first, Node *last, DeleteItem f)
{
    for (; first != last; first = first->next) {
        f(first->value);
    }
}

struct List;
extern "C" void FUN_0006792c(Node **, List *, Node **, Node **);

struct List {
    int size;
    Node head;
    void clear()
    {
        Node *out;
        Node *first;
        Node *last;
        last = &head;
        first = head.next;
        FUN_0006792c(&out, this, &first, &last);
    }
};

struct Obj {
    char pad[0x3c];
    List items;
};

extern "C" void FUN_000675b4(Obj *self)
{
    Node *end = &self->items.head;
    ForEach(self->items.head.next, end, DeleteItem());
    self->items.clear();
}
