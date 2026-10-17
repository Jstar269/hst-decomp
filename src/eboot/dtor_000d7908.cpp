/* HSTMATCH module=EBOOT.BIN start=0x000d7908 end=0x000d7978 symbol=__dt__10D_000d7908Fv */
/* Clone of src/eboot/dtor_000b6320.cpp (hstclone.py tag c2): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_000d7908 { int v; ~Elem_000d7908() {} };
class V_000d7908 {
public:
    Elem_000d7908 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_000d7908() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_000d7908 : public V_000d7908 { public: ~D_000d7908(); };
D_000d7908::~D_000d7908() { size = 0; }
