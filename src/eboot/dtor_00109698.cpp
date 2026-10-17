/* HSTMATCH module=EBOOT.BIN start=0x00109698 end=0x00109708 symbol=__dt__10D_00109698Fv */
/* Clone of src/eboot/dtor_000b6320.cpp (hstclone.py tag c2): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_00109698 { int v; ~Elem_00109698() {} };
class V_00109698 {
public:
    Elem_00109698 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_00109698() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_00109698 : public V_00109698 { public: ~D_00109698(); };
D_00109698::~D_00109698() { size = 0; }
