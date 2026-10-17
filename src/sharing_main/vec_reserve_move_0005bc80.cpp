/* HSTMATCH module=hstp_trans_main.prx start=0x0005bc80 end=0x0005bd74 symbol=FUN_0005bc80 lang=c++ */
/* Hand-written reconstruction from the disassembly (twin of src/eboot/vec_reserve_member_00050dd8.cpp, here with the out-of-line destructor 0x5c10c and the empty tag temporaries of the sibling vec_append_0005bd74.cpp); exact match verified; names and types await human review. */
/* Container reserve(n): allocate a temporary vector of capacity n, move the old elements into it, clear the old
   storage, swap, and let the temporary's destructor (0x5c10c, called out of line) free the old block.
   Matching idiom: the empty tag arguments E_0005bc80 of the inline Move/Clear helpers (and of the out-of-line
   reserve) reserve the retail frame slots; distance() takes its iterators by const reference, which keeps
   end - begin unfolded. Names provisional. */
#pragma inline_depth(8)
extern "C" {
void *FUN_00011090(void *dst, const void *src, unsigned n);
void *FUN_000114c0(void *p, int c, unsigned n);
}
struct E_0005bc80 {};
struct Elem_0005c10c { int v; ~Elem_0005c10c() {} };
template <class T> inline void Swap_0005bc80(T &a, T &b) { T t = a; a = b; b = t; }
inline int Distance_0005bc80(Elem_0005c10c *const &a, Elem_0005c10c *const &b) { return b - a; }
class V_0005c10c {
public:
    Elem_0005c10c *data;
    int size;
    unsigned capacity;
    V_0005c10c() : data(0), size(0), capacity(0) {}
    ~V_0005c10c();
};
inline void Move_0005bc80(Elem_0005c10c *dst, Elem_0005c10c *src, unsigned bytes, E_0005bc80) { FUN_00011090(dst, src, bytes); FUN_000114c0(src, 0, bytes); }
inline void Clear_0005bc80(V_0005c10c *v, E_0005bc80) { v->size = 0; }
extern "C" void FUN_0005c088(V_0005c10c *v, unsigned n, E_0005bc80 a);
extern "C" void FUN_0005bc80(V_0005c10c *v, unsigned n)
{
    V_0005c10c buf;
    FUN_0005c088(&buf, n, E_0005bc80());
    Elem_0005c10c *old = v->data;
    int count = Distance_0005bc80(old, old + v->size);
    Move_0005bc80(buf.data + buf.size, old, count * 4, E_0005bc80());
    buf.size += count;
    Clear_0005bc80(v, E_0005bc80());
    Swap_0005bc80(v->capacity, buf.capacity);
    Swap_0005bc80(v->data, buf.data);
    Swap_0005bc80(v->size, buf.size);
}
