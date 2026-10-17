/* HSTMATCH module=EBOOT.BIN start=0x000e855c end=0x000e85c4 symbol=__dt__10V_000e855cFv */
/* Clone of src/eboot/dtor_000fc2ec.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
/* Vector-like container destructor: inline shrink(size) through a local copy (kept as a load/subtract,
   not folded) with an empty allocator class passed by value (the temporary reserves the 32-byte frame),
   then delete the element block. Names provisional. */
struct Alloc {};
struct Elem_000e855c { int v; ~Elem_000e855c() {} };
class V_000e855c {
public:
    Elem_000e855c *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_000e855c();
};
V_000e855c::~V_000e855c() { int n = size; shrink(n, Alloc()); delete data; }
