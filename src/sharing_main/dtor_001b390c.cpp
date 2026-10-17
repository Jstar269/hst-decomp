/* HSTMATCH module=hstp_trans_main.prx start=0x001b390c end=0x001b3974 symbol=__dt__10V_001b390cFv */
/* Clone of src/eboot/dtor_00050ed4.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
/* Vector-like container destructor: inline shrink(size) through a local copy (kept as a load/subtract,
   not folded) with an empty allocator class passed by value (the temporary reserves the 32-byte frame),
   then delete the element block. Names provisional. */
struct Alloc {};
struct Elem_001b390c { int v; ~Elem_001b390c() {} };
class V_001b390c {
public:
    Elem_001b390c *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_001b390c();
};
V_001b390c::~V_001b390c() { int n = size; shrink(n, Alloc()); delete data; }
