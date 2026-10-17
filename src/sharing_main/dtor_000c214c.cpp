/* HSTMATCH module=hstp_trans_main.prx start=0x000c214c end=0x000c21b4 symbol=__dt__10V_000c214cFv */
/* Clone of src/eboot/dtor_00050ed4.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
/* Vector-like container destructor: inline shrink(size) through a local copy (kept as a load/subtract,
   not folded) with an empty allocator class passed by value (the temporary reserves the 32-byte frame),
   then delete the element block. Names provisional. */
struct Alloc {};
struct Elem_000c214c { int v; ~Elem_000c214c() {} };
class V_000c214c {
public:
    Elem_000c214c *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_000c214c();
};
V_000c214c::~V_000c214c() { int n = size; shrink(n, Alloc()); delete data; }
