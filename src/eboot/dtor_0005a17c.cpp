/* HSTMATCH module=EBOOT.BIN start=0x0005a17c end=0x0005a1ec symbol=__dt__10D_0005a17cFv */
/* Clone of src/eboot/dtor_000b6320.cpp (hstclone.py tag c2): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_0005a17c { int v; ~Elem_0005a17c() {} };
class V_0005a17c {
public:
    Elem_0005a17c *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_0005a17c() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_0005a17c : public V_0005a17c { public: ~D_0005a17c(); };
D_0005a17c::~D_0005a17c() { size = 0; }
