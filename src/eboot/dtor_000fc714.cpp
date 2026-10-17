/* HSTMATCH module=EBOOT.BIN start=0x000fc714 end=0x000fc784 symbol=__dt__10D_000fc714Fv */
/* Clone of src/eboot/dtor_000b6320.cpp (hstclone.py tag c2): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_000fc714 { int v; ~Elem_000fc714() {} };
class V_000fc714 {
public:
    Elem_000fc714 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_000fc714() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_000fc714 : public V_000fc714 { public: ~D_000fc714(); };
D_000fc714::~D_000fc714() { size = 0; }
