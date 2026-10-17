/* HSTMATCH module=hstp_trans_main.prx start=0x0006762c end=0x00067694 symbol=__dt__10V_0006762cFv */
/* Clone of src/eboot/dtor_00050ed4.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
/* Vector-like container destructor: inline shrink(size) through a local copy (kept as a load/subtract,
   not folded) with an empty allocator class passed by value (the temporary reserves the 32-byte frame),
   then delete the element block. Names provisional. */
struct Alloc {};
struct Elem_0006762c { int v; ~Elem_0006762c() {} };
class V_0006762c {
public:
    Elem_0006762c *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_0006762c();
};
V_0006762c::~V_0006762c() { int n = size; shrink(n, Alloc()); delete data; }
