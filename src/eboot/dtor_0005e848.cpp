/* HSTMATCH module=EBOOT.BIN start=0x0005e848 end=0x0005e8b8 symbol=__dt__10D_0005e848Fv */
/* Clone of src/eboot/dtor_000b6320.cpp (hstclone.py tag c2): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_0005e848 { int v; ~Elem_0005e848() {} };
class V_0005e848 {
public:
    Elem_0005e848 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_0005e848() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_0005e848 : public V_0005e848 { public: ~D_0005e848(); };
D_0005e848::~D_0005e848() { size = 0; }
