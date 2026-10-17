/* HSTMATCH module=EBOOT.BIN start=0x00160684 end=0x001606f4 symbol=__dt__10D_00160684Fv */
/* Clone of src/eboot/dtor_000b6320.cpp (hstclone.py tag c2): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_00160684 { int v; ~Elem_00160684() {} };
class V_00160684 {
public:
    Elem_00160684 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_00160684() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_00160684 : public V_00160684 { public: ~D_00160684(); };
D_00160684::~D_00160684() { size = 0; }
