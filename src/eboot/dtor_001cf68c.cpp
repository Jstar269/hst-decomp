/* HSTMATCH module=EBOOT.BIN start=0x001cf68c end=0x001cf6fc symbol=__dt__10D_001cf68cFv */
/* Clone of src/eboot/dtor_000b6320.cpp (hstclone.py tag c2): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_001cf68c { int v; ~Elem_001cf68c() {} };
class V_001cf68c {
public:
    Elem_001cf68c *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_001cf68c() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_001cf68c : public V_001cf68c { public: ~D_001cf68c(); };
D_001cf68c::~D_001cf68c() { size = 0; }
