/* HSTMATCH module=EBOOT.BIN start=0x0014af34 end=0x0014afa4 symbol=__dt__10D_0014af34Fv */
/* Clone of src/eboot/dtor_000b6320.cpp (hstclone.py tag c2): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_0014af34 { int v; ~Elem_0014af34() {} };
class V_0014af34 {
public:
    Elem_0014af34 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_0014af34() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_0014af34 : public V_0014af34 { public: ~D_0014af34(); };
D_0014af34::~D_0014af34() { size = 0; }
