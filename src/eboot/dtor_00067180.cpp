/* HSTMATCH module=EBOOT.BIN start=0x00067180 end=0x000671f0 symbol=__dt__10D_00067180Fv */
/* Clone of src/eboot/dtor_000b6320.cpp (hstclone.py tag c2): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_00067180 { int v; ~Elem_00067180() {} };
class V_00067180 {
public:
    Elem_00067180 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_00067180() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_00067180 : public V_00067180 { public: ~D_00067180(); };
D_00067180::~D_00067180() { size = 0; }
