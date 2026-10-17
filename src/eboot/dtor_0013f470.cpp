/* HSTMATCH module=EBOOT.BIN start=0x0013f470 end=0x0013f4e0 symbol=__dt__10D_0013f470Fv */
/* Clone of src/eboot/dtor_000b6320.cpp (hstclone.py tag c2): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_0013f470 { int v; ~Elem_0013f470() {} };
class V_0013f470 {
public:
    Elem_0013f470 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_0013f470() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_0013f470 : public V_0013f470 { public: ~D_0013f470(); };
D_0013f470::~D_0013f470() { size = 0; }
