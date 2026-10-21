/* HSTMATCH module=hstp_trans_main.prx start=0x001b1e70 end=0x001b1f20 symbol=FUN_001b1e70 lang=c++ */
/* Clone of src/eboot/scroll_to_item_001a48a4.cpp (hstclone.py tag c21sn1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct Item {
    int id;
};

template<typename T>
struct Vector {
    T *data;
    int count;

    struct Iter {
        T *p;
        Iter(T *p_) : p(p_) {}
        T &operator*() const { return *p; }
        Iter &operator++() { ++p; return *this; }
        friend bool operator!=(const Iter &a, const Iter &b) {
            return !(a.p == b.p);
        }
    };

    Iter begin() const { return Iter(data); }
    Iter end() { return Iter(data + count); }
    int size() const { return count; }
};

struct ScrollList {
    char pad[0x2fc];
    int cursor_pos;       // 0x2fc
    int selected_idx;     // 0x300
    int scroll_offset;    // 0x304
    char pad2[0x384 - 0x308];
    Vector<Item *> items; // 0x384

};

extern "C" void FUN_001b1e70(ScrollList *o, int target_id)
{
    Vector<Item *> &items = o->items;
    int count = items.size();
    Vector<Item *>::Iter end = items.end();
    Vector<Item *>::Iter it = items.begin();
    int i = 0;

    for (; it != end; ++it, ++i) {
        int cur = (*it)->id;
        if (cur == target_id) {
            if (count < 10) {
                o->cursor_pos = i;
                o->scroll_offset = 0;
            } else if (!(i + 5 < count)) {
                o->scroll_offset = count - 9;
                o->cursor_pos = i - (count - 9);
            } else if (i - 3 <= 0) {
                o->cursor_pos = i;
                o->scroll_offset = 0;
            } else {
                o->cursor_pos = 3;
                o->scroll_offset = i - 3;
            }
            o->selected_idx = i;
            return;
        }
    }
}
