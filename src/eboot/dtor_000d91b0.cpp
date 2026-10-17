/* HSTMATCH module=EBOOT.BIN start=0x000d91b0 end=0x000d9220 symbol=__dt__10D_000d91b0Fv */
/* Clone of src/eboot/dtor_000b6320.cpp (hstclone.py tag c2): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_000d91b0 { int v; ~Elem_000d91b0() {} };
class V_000d91b0 {
public:
    Elem_000d91b0 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_000d91b0() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_000d91b0 : public V_000d91b0 { public: ~D_000d91b0(); };
D_000d91b0::~D_000d91b0() { size = 0; }
