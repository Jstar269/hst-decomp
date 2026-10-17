/* HSTMATCH module=hstp_trans_main.prx start=0x0015673c end=0x001567ac symbol=__dt__10D_0015673cFv */
/* Clone of src/eboot/dtor_00054cbc.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_0015673c { int v; ~Elem_0015673c() {} };
class V_0015673c {
public:
    Elem_0015673c *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_0015673c() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_0015673c : public V_0015673c { public: ~D_0015673c(); };
D_0015673c::~D_0015673c() { size = 0; }
