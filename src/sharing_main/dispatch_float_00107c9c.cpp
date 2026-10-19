/* HSTMATCH module=hstp_trans_main.prx start=0x00107c9c end=0x00107d3c symbol=FUN_00107c9c lang=c++ */
/* Clone of src/eboot/dispatch_float_00102230.cpp (hstclone.py tag s10172123g1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct Listener {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void OnEvent(float val);
};

struct Item {
    char pad[0x20];
    Listener *listener;
};

struct Iter;

struct Container {
    char pad[0x10];
    Item **items;
    int count;
    char pad2[0x8];
    float value;

    Iter begin();
    Iter end();
};

struct Iter {
    Item **p;
    Iter() {}
    Iter(Item **q) : p(q) {}
    Item *operator*() const { return *p; }
    Iter &operator++() { ++p; return *this; }
};

inline Iter Container::begin() { return Iter(items); }
inline Iter Container::end() { return Iter(items + count); }

static inline int operator!=(const Iter &a, const Iter &b) { return (a.p == b.p) ^ 1; }

extern "C" void FUN_00107c9c(Container *self, float val)
{
    self->value = val;
    Iter it = self->begin();
    Iter end = self->end();
    if (it != end) {
        do {
            Item *item = *it;
            if (item->listener != 0) {
                item->listener->OnEvent(val);
            }
            ++it;
            end = self->end();
        } while (it != end);
    }
}
