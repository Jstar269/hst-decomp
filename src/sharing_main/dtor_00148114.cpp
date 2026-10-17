/* HSTMATCH module=hstp_trans_main.prx start=0x00148114 end=0x0014817c symbol=__dt__10V_00148114Fv */
/* Clone of src/eboot/dtor_00050ed4.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
/* Vector-like container destructor: inline shrink(size) through a local copy (kept as a load/subtract,
   not folded) with an empty allocator class passed by value (the temporary reserves the 32-byte frame),
   then delete the element block. Names provisional. */
struct Alloc {};
struct Elem_00148114 { int v; ~Elem_00148114() {} };
class V_00148114 {
public:
    Elem_00148114 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_00148114();
};
V_00148114::~V_00148114() { int n = size; shrink(n, Alloc()); delete data; }
