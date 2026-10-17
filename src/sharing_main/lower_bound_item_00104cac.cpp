/* HSTMATCH module=hstp_trans_main.prx start=0x00104cac end=0x00104d94 symbol=FUN_00104cac lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct Tag_00104cac {};
struct Item_00104cac {
    unsigned int id;
    const char *str;
    int pad[3];
};

extern "C" int FUN_00014934(const char *, const char *);

extern "C" Item_00104cac *FUN_00104cac(Item_00104cac *first, Item_00104cac *last, const Item_00104cac *val, Tag_00104cac)
{
    int len = ((char *)last - (char *)first) / (int)sizeof(Item_00104cac);
    while (len > 0) {
        int half = len / 2;
        Item_00104cac *mid = first + half;
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
