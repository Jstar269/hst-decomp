/* HSTMATCH module=EBOOT.BIN start=0x00054d2c end=0x00054d9c symbol=__dt__10D_00054d2cFv */
/* Clone of src/eboot/dtor_000b6320.cpp (hstclone.py tag c2): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_00054d2c { int v; ~Elem_00054d2c() {} };
class V_00054d2c {
public:
    Elem_00054d2c *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_00054d2c() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_00054d2c : public V_00054d2c { public: ~D_00054d2c(); };
D_00054d2c::~D_00054d2c() { size = 0; }
