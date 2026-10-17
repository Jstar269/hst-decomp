/* HSTMATCH module=EBOOT.BIN start=0x0026968c end=0x002696fc symbol=__dt__10D_0026968cFv */
/* Clone of src/eboot/dtor_000b6320.cpp (hstclone.py tag c2): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_0026968c { int v; ~Elem_0026968c() {} };
class V_0026968c {
public:
    Elem_0026968c *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_0026968c() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_0026968c : public V_0026968c { public: ~D_0026968c(); };
D_0026968c::~D_0026968c() { size = 0; }
