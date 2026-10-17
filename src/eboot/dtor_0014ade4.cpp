/* HSTMATCH module=EBOOT.BIN start=0x0014ade4 end=0x0014ae54 symbol=__dt__10D_0014ade4Fv */
/* Clone of src/eboot/dtor_000b6320.cpp (hstclone.py tag c2): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_0014ade4 { int v; ~Elem_0014ade4() {} };
class V_0014ade4 {
public:
    Elem_0014ade4 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_0014ade4() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_0014ade4 : public V_0014ade4 { public: ~D_0014ade4(); };
D_0014ade4::~D_0014ade4() { size = 0; }
