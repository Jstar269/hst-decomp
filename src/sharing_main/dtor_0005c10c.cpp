/* HSTMATCH module=hstp_trans_main.prx start=0x0005c10c end=0x0005c174 symbol=__dt__10V_0005c10cFv */
/* Clone of src/eboot/dtor_00050ed4.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
/* Vector-like container destructor: inline shrink(size) through a local copy (kept as a load/subtract,
   not folded) with an empty allocator class passed by value (the temporary reserves the 32-byte frame),
   then delete the element block. Names provisional. */
struct Alloc {};
struct Elem_0005c10c { int v; ~Elem_0005c10c() {} };
class V_0005c10c {
public:
    Elem_0005c10c *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_0005c10c();
};
V_0005c10c::~V_0005c10c() { int n = size; shrink(n, Alloc()); delete data; }
