/* HSTMATCH module=EBOOT.BIN start=0x000b6320 end=0x000b6390 symbol=__dt__10D_000b6320Fv */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_000b6320 { int v; ~Elem_000b6320() {} };
class V_000b6320 {
public:
    Elem_000b6320 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_000b6320() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_000b6320 : public V_000b6320 { public: ~D_000b6320(); };
D_000b6320::~D_000b6320() { size = 0; }
