/* HSTMATCH module=hstp_trans_main.prx start=0x0015681c end=0x0015688c symbol=__dt__10D_0015681cFv */
/* Clone of src/eboot/dtor_00054cbc.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_0015681c { int v; ~Elem_0015681c() {} };
class V_0015681c {
public:
    Elem_0015681c *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_0015681c() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_0015681c : public V_0015681c { public: ~D_0015681c(); };
D_0015681c::~D_0015681c() { size = 0; }
