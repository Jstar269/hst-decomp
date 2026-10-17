/* HSTMATCH module=EBOOT.BIN start=0x001095b8 end=0x00109628 symbol=__dt__10D_001095b8Fv */
/* Clone of src/eboot/dtor_000b6320.cpp (hstclone.py tag c2): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_001095b8 { int v; ~Elem_001095b8() {} };
class V_001095b8 {
public:
    Elem_001095b8 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_001095b8() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_001095b8 : public V_001095b8 { public: ~D_001095b8(); };
D_001095b8::~D_001095b8() { size = 0; }
