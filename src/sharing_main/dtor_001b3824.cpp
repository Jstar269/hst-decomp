/* HSTMATCH module=hstp_trans_main.prx start=0x001b3824 end=0x001b388c symbol=__dt__10V_001b3824Fv */
/* Clone of src/eboot/dtor_00050ed4.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
/* Vector-like container destructor: inline shrink(size) through a local copy (kept as a load/subtract,
   not folded) with an empty allocator class passed by value (the temporary reserves the 32-byte frame),
   then delete the element block. Names provisional. */
struct Alloc {};
struct Elem_001b3824 { int v; ~Elem_001b3824() {} };
class V_001b3824 {
public:
    Elem_001b3824 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_001b3824();
};
V_001b3824::~V_001b3824() { int n = size; shrink(n, Alloc()); delete data; }
