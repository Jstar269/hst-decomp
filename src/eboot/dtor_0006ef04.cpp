/* HSTMATCH module=EBOOT.BIN start=0x0006ef04 end=0x0006ef74 symbol=__dt__10D_0006ef04Fv */
/* Clone of src/eboot/dtor_000b6320.cpp (hstclone.py tag c2): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_0006ef04 { int v; ~Elem_0006ef04() {} };
class V_0006ef04 {
public:
    Elem_0006ef04 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_0006ef04() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_0006ef04 : public V_0006ef04 { public: ~D_0006ef04(); };
D_0006ef04::~D_0006ef04() { size = 0; }
