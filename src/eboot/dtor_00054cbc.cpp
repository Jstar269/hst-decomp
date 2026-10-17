/* HSTMATCH module=EBOOT.BIN start=0x00054cbc end=0x00054d2c symbol=__dt__10D_00054cbcFv */
/* Clone of src/eboot/dtor_000b6320.cpp (hstclone.py tag c2): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_00054cbc { int v; ~Elem_00054cbc() {} };
class V_00054cbc {
public:
    Elem_00054cbc *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_00054cbc() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_00054cbc : public V_00054cbc { public: ~D_00054cbc(); };
D_00054cbc::~D_00054cbc() { size = 0; }
