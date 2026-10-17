/* HSTMATCH module=EBOOT.BIN start=0x0017e48c end=0x0017e4fc symbol=__dt__10D_0017e48cFv */
/* Clone of src/eboot/dtor_000b6320.cpp (hstclone.py tag c2): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_0017e48c { int v; ~Elem_0017e48c() {} };
class V_0017e48c {
public:
    Elem_0017e48c *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_0017e48c() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_0017e48c : public V_0017e48c { public: ~D_0017e48c(); };
D_0017e48c::~D_0017e48c() { size = 0; }
