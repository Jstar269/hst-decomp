/* HSTMATCH module=hstp_trans_main.prx start=0x0016a9fc end=0x0016aae4 symbol=FUN_0016a9fc lang=c++ */
/* Hand-written reconstruction from the disassembly (near miss, 3 words); names and types await human review. */
struct Mgr;
class Item {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
    Mgr *owner;
    char pad[8];
    char flag;
};

struct Tag {};
template <class T> struct It {
    T *p_;
    It(T *p) : p_(p) {}
};
template <class T> inline It<T> operator-(It<T> a, int n, Tag) { a.p_ -= n; return a; }

struct Alloc {};
struct PVec;
extern "C" void FUN_0016c824(PVec *v, Item *const *x, Alloc a);
struct PVec {
    Item **data;
    unsigned size;
    unsigned capacity;
    It<Item *> end() { return It<Item *>(data + size); }
    void push_back(Item *const &x, Tag, Tag)
    {
        if (size < capacity) {
            ++size;
            unsigned i = size - 1;
            data[i] = x;
        } else {
            FUN_0016c824(this, &x, Alloc());
        }
    }
};
struct Mgr {
    char pad[0x14];
    PVec items;
};

extern "C" It<Item *> FUN_0016a9fc(Mgr *m, Item *item)
{
    if (item != 0) {
        item->owner = m;
        if (item->v3() != 0) item->flag = 0;
        m->items.push_back(item, Tag(), Tag());
        return operator-(m->items.end(), 1, Tag());
    }
    return m->items.end();
}
// Near miss, 3 words differ: code identical, only two iterator-temporary stack slots: ours by-value copy `a` (read back and also the dead result store) at 24(sp);
// retail copy at 28(sp) (read back) and a SEPARATE dead result store to 44(sp). Item* param at 20(sp), end() temp at 36(sp) and the 48-byte frame match.
// Found: unused empty by-value `Tag` params (push_back x2, operator- x1; 011/110/201/300 distributions give 5 words) place the temps; `unsigned i = size - 1; data[i] = x;` (not data[size - 1]) gives retail's addiu -1 / sll order.
// Ruled out for the separate 44(sp) result object: operator- bodies returning a named local / copy-initialised local / `It(a.p_-n)`, `It r = ...; return r;`, explicit `It(...)` cast at the return, member operator-/-=/+= chains (scalarize the temps), const-ref param; tag counts 0..3 on end/push_back/operator-.
