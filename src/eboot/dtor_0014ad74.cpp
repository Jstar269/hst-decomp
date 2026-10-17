/* HSTMATCH module=EBOOT.BIN start=0x0014ad74 end=0x0014ade4 symbol=__dt__10D_0014ad74Fv */
/* Clone of src/eboot/dtor_000b6320.cpp (hstclone.py tag c2): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_0014ad74 { int v; ~Elem_0014ad74() {} };
class V_0014ad74 {
public:
    Elem_0014ad74 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_0014ad74() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_0014ad74 : public V_0014ad74 { public: ~D_0014ad74(); };
D_0014ad74::~D_0014ad74() { size = 0; }
