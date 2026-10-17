/* HSTMATCH module=EBOOT.BIN start=0x0013f390 end=0x0013f400 symbol=__dt__10D_0013f390Fv */
/* Clone of src/eboot/dtor_000b6320.cpp (hstclone.py tag c2): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_0013f390 { int v; ~Elem_0013f390() {} };
class V_0013f390 {
public:
    Elem_0013f390 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_0013f390() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_0013f390 : public V_0013f390 { public: ~D_0013f390(); };
D_0013f390::~D_0013f390() { size = 0; }
