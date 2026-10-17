/* HSTMATCH module=EBOOT.BIN start=0x001a8864 end=0x001a88d4 symbol=__dt__10D_001a8864Fv */
/* Clone of src/eboot/dtor_000b6320.cpp (hstclone.py tag c2): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_001a8864 { int v; ~Elem_001a8864() {} };
class V_001a8864 {
public:
    Elem_001a8864 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_001a8864() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_001a8864 : public V_001a8864 { public: ~D_001a8864(); };
D_001a8864::~D_001a8864() { size = 0; }
