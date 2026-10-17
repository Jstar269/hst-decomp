/* HSTMATCH module=EBOOT.BIN start=0x0016675c end=0x001667cc symbol=__dt__10D_0016675cFv */
/* Clone of src/eboot/dtor_000b6320.cpp (hstclone.py tag c2): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_0016675c { int v; ~Elem_0016675c() {} };
class V_0016675c {
public:
    Elem_0016675c *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_0016675c() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_0016675c : public V_0016675c { public: ~D_0016675c(); };
D_0016675c::~D_0016675c() { size = 0; }
