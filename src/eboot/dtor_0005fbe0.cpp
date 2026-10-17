/* HSTMATCH module=EBOOT.BIN start=0x0005fbe0 end=0x0005fc50 symbol=__dt__10D_0005fbe0Fv */
/* Clone of src/eboot/dtor_000b6320.cpp (hstclone.py tag c2): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_0005fbe0 { int v; ~Elem_0005fbe0() {} };
class V_0005fbe0 {
public:
    Elem_0005fbe0 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_0005fbe0() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_0005fbe0 : public V_0005fbe0 { public: ~D_0005fbe0(); };
D_0005fbe0::~D_0005fbe0() { size = 0; }
