/* HSTMATCH module=hstp_trans_main.prx start=0x0027a28c end=0x0027a2f4 symbol=__dt__10V_0027a28cFv */
/* Clone of src/eboot/dtor_00050ed4.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Vector-like container destructor: inline shrink(size) through a local copy (kept as a load/subtract,
   not folded) with an empty allocator class passed by value (the temporary reserves the 32-byte frame),
   then delete the element block. Names provisional. */
struct Alloc {};
struct Elem_0027a28c { int v; ~Elem_0027a28c() {} };
class V_0027a28c {
public:
    Elem_0027a28c *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_0027a28c();
};
V_0027a28c::~V_0027a28c() { int n = size; shrink(n, Alloc()); delete data; }
