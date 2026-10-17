/* HSTMATCH module=hstp_trans_main.prx start=0x000702c4 end=0x0007032c symbol=__dt__10V_000702c4Fv */
/* Clone of src/eboot/dtor_00050ed4.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
/* Vector-like container destructor: inline shrink(size) through a local copy (kept as a load/subtract,
   not folded) with an empty allocator class passed by value (the temporary reserves the 32-byte frame),
   then delete the element block. Names provisional. */
struct Alloc {};
struct Elem_000702c4 { int v; ~Elem_000702c4() {} };
class V_000702c4 {
public:
    Elem_000702c4 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_000702c4();
};
V_000702c4::~V_000702c4() { int n = size; shrink(n, Alloc()); delete data; }
