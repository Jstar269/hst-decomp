/* HSTMATCH module=hstp_trans_main.prx start=0x00186164 end=0x001861cc symbol=__dt__10V_00186164Fv */
/* Clone of src/eboot/dtor_00050ed4.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
/* Vector-like container destructor: inline shrink(size) through a local copy (kept as a load/subtract,
   not folded) with an empty allocator class passed by value (the temporary reserves the 32-byte frame),
   then delete the element block. Names provisional. */
struct Alloc {};
struct Elem_00186164 { int v; ~Elem_00186164() {} };
class V_00186164 {
public:
    Elem_00186164 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_00186164();
};
V_00186164::~V_00186164() { int n = size; shrink(n, Alloc()); delete data; }
