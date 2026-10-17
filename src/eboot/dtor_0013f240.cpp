/* HSTMATCH module=EBOOT.BIN start=0x0013f240 end=0x0013f2b0 symbol=__dt__10D_0013f240Fv */
/* Clone of src/eboot/dtor_000b6320.cpp (hstclone.py tag c2): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_0013f240 { int v; ~Elem_0013f240() {} };
class V_0013f240 {
public:
    Elem_0013f240 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_0013f240() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_0013f240 : public V_0013f240 { public: ~D_0013f240(); };
D_0013f240::~D_0013f240() { size = 0; }
