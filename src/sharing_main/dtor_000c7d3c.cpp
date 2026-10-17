/* HSTMATCH module=hstp_trans_main.prx start=0x000c7d3c end=0x000c7dac symbol=__dt__10D_000c7d3cFv */
/* Clone of src/eboot/dtor_00054cbc.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_000c7d3c { int v; ~Elem_000c7d3c() {} };
class V_000c7d3c {
public:
    Elem_000c7d3c *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_000c7d3c() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_000c7d3c : public V_000c7d3c { public: ~D_000c7d3c(); };
D_000c7d3c::~D_000c7d3c() { size = 0; }
