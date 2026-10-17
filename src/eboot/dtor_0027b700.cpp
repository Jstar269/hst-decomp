/* HSTMATCH module=EBOOT.BIN start=0x0027b700 end=0x0027b770 symbol=__dt__10D_0027b700Fv */
/* Clone of src/eboot/dtor_000b6320.cpp (hstclone.py tag c2): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_0027b700 { int v; ~Elem_0027b700() {} };
class V_0027b700 {
public:
    Elem_0027b700 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_0027b700() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_0027b700 : public V_0027b700 { public: ~D_0027b700(); };
D_0027b700::~D_0027b700() { size = 0; }
