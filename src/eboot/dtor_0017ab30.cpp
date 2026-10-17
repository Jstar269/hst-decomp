/* HSTMATCH module=EBOOT.BIN start=0x0017ab30 end=0x0017aba0 symbol=__dt__10D_0017ab30Fv */
/* Clone of src/eboot/dtor_000b6320.cpp (hstclone.py tag c2): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_0017ab30 { int v; ~Elem_0017ab30() {} };
class V_0017ab30 {
public:
    Elem_0017ab30 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_0017ab30() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_0017ab30 : public V_0017ab30 { public: ~D_0017ab30(); };
D_0017ab30::~D_0017ab30() { size = 0; }
