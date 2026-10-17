/* HSTMATCH module=EBOOT.BIN start=0x001bb4ec end=0x001bb55c symbol=__dt__10D_001bb4ecFv */
/* Clone of src/eboot/dtor_000b6320.cpp (hstclone.py tag c2): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_001bb4ec { int v; ~Elem_001bb4ec() {} };
class V_001bb4ec {
public:
    Elem_001bb4ec *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_001bb4ec() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_001bb4ec : public V_001bb4ec { public: ~D_001bb4ec(); };
D_001bb4ec::~D_001bb4ec() { size = 0; }
