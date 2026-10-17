/* HSTMATCH module=hstp_trans_main.prx start=0x00152c6c end=0x00152cd4 symbol=__dt__10V_00152c6cFv */
/* Clone of src/eboot/dtor_00050ed4.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
/* Vector-like container destructor: inline shrink(size) through a local copy (kept as a load/subtract,
   not folded) with an empty allocator class passed by value (the temporary reserves the 32-byte frame),
   then delete the element block. Names provisional. */
struct Alloc {};
struct Elem_00152c6c { int v; ~Elem_00152c6c() {} };
class V_00152c6c {
public:
    Elem_00152c6c *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_00152c6c();
};
V_00152c6c::~V_00152c6c() { int n = size; shrink(n, Alloc()); delete data; }
