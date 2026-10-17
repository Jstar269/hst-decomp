/* HSTMATCH module=EBOOT.BIN start=0x000ff414 end=0x000ff4fc symbol=FUN_000ff414 lang=c++ */
/* Clone of src/sharing_main/lower_bound_item_00104cac.cpp (hstclone.py tag u1r2e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct Tag_000ff414 {};
struct Item_000ff414 {
    unsigned int id;
    const char *str;
    int pad[3];
};

extern "C" int FUN_00014934(const char *, const char *);

extern "C" Item_000ff414 *FUN_000ff414(Item_000ff414 *first, Item_000ff414 *last, const Item_000ff414 *val, Tag_000ff414)
{
    int len = ((char *)last - (char *)first) / (int)sizeof(Item_000ff414);
    while (len > 0) {
        int half = len / 2;
        Item_000ff414 *mid = first + half;
        int comp;
        if (mid->id == val->id) {
            bool b = false;
            if (val->str[0] != '\0') {
                if (FUN_00014934(mid->str, val->str) > 0) {
                    b = true;
                }
            }
            comp = b;
        } else {
            comp = mid->id < val->id;
        }
        if (comp) {
            first = mid + 1;
            len = len - (half + 1);
        } else {
            len = half;
        }
    }
    return first;
}
