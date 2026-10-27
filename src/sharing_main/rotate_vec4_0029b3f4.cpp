/* HSTMATCH module=hstp_trans_main.prx start=0x0029b3f4 end=0x0029b470 symbol=FUN_0029b3f4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Out-of-line forward-iterator rotate over 16-byte float records (std::rotate shape). The record's user-declared
   memberwise copy constructor keeps the swap temporary in four FPRs; with the implicit one it goes through a stack slot. */
struct Vec4 {
    float x, y, z, w;
    Vec4(const Vec4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
};

template <class T> inline void swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

extern "C" void FUN_0029b3f4(Vec4 *first, Vec4 *middle, Vec4 *last)
{
    Vec4 *i = middle;

    while (true) {
        swap(*first, *i);
        if (++first == middle) {
            if (++i == last)
                return;
            middle = i;
        } else if (++i == last) {
            i = middle;
        }
    }
}
