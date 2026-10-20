/* HSTMATCH module=EBOOT.BIN start=0x001a48a4 end=0x001a4954 symbol=FUN_001a48a4 lang=c++ */

struct Item {
    int id;
};

template<typename T>
struct Vector {
    T *data;
    volatile int count;

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

    int size() const { return items.count; }
};

extern "C" void FUN_001a48a4(ScrollList *o, int target_id)
{
    Vector<Item *> &items = o->items;
    Vector<Item *>::Iter end = items.end();
    Vector<Item *>::Iter it = items.begin();
    int count = items.count;
    int i = 0;

    for (; it != end; ++it, ++i) {
        if ((*it)->id == target_id) {
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
// near miss from lane s10172123g5r1-1 (unreviewed)
