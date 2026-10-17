/* HSTMATCH module=EBOOT.BIN start=0x000bf8b4 end=0x000bf924 symbol=__dt__10D_000bf8b4Fv */
/* Clone of src/eboot/dtor_000b6320.cpp (hstclone.py tag c2): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_000bf8b4 { int v; ~Elem_000bf8b4() {} };
class V_000bf8b4 {
public:
    Elem_000bf8b4 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_000bf8b4() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_000bf8b4 : public V_000bf8b4 { public: ~D_000bf8b4(); };
D_000bf8b4::~D_000bf8b4() { size = 0; }
