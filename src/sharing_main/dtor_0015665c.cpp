/* HSTMATCH module=hstp_trans_main.prx start=0x0015665c end=0x001566cc symbol=__dt__10D_0015665cFv */
/* Clone of src/eboot/dtor_00054cbc.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_0015665c { int v; ~Elem_0015665c() {} };
class V_0015665c {
public:
    Elem_0015665c *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_0015665c() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_0015665c : public V_0015665c { public: ~D_0015665c(); };
D_0015665c::~D_0015665c() { size = 0; }
