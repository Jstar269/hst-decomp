/* HSTMATCH module=EBOOT.BIN start=0x0005b4ec end=0x0005b55c symbol=__dt__10D_0005b4ecFv */
/* Clone of src/eboot/dtor_000b6320.cpp (hstclone.py tag c2): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_0005b4ec { int v; ~Elem_0005b4ec() {} };
class V_0005b4ec {
public:
    Elem_0005b4ec *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_0005b4ec() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_0005b4ec : public V_0005b4ec { public: ~D_0005b4ec(); };
D_0005b4ec::~D_0005b4ec() { size = 0; }
