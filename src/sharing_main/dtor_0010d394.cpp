/* HSTMATCH module=hstp_trans_main.prx start=0x0010d394 end=0x0010d3fc symbol=__dt__10V_0010d394Fv */
/* Clone of src/eboot/dtor_00050ed4.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
/* Vector-like container destructor: inline shrink(size) through a local copy (kept as a load/subtract,
   not folded) with an empty allocator class passed by value (the temporary reserves the 32-byte frame),
   then delete the element block. Names provisional. */
struct Alloc {};
struct Elem_0010d394 { int v; ~Elem_0010d394() {} };
class V_0010d394 {
public:
    Elem_0010d394 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_0010d394();
};
V_0010d394::~V_0010d394() { int n = size; shrink(n, Alloc()); delete data; }
