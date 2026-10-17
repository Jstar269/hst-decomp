/* HSTMATCH module=hstp_trans_main.prx start=0x0005584c end=0x000558bc symbol=__dt__10D_0005584cFv */
/* Clone of src/eboot/dtor_00054cbc.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_0005584c { int v; ~Elem_0005584c() {} };
class V_0005584c {
public:
    Elem_0005584c *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_0005584c() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_0005584c : public V_0005584c { public: ~D_0005584c(); };
D_0005584c::~D_0005584c() { size = 0; }
