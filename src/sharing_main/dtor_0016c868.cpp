/* HSTMATCH module=hstp_trans_main.prx start=0x0016c868 end=0x0016c8d0 symbol=__dt__10V_0016c868Fv */
/* Clone of src/eboot/dtor_00050ed4.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
/* Vector-like container destructor: inline shrink(size) through a local copy (kept as a load/subtract,
   not folded) with an empty allocator class passed by value (the temporary reserves the 32-byte frame),
   then delete the element block. Names provisional. */
struct Alloc {};
struct Elem_0016c868 { int v; ~Elem_0016c868() {} };
class V_0016c868 {
public:
    Elem_0016c868 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_0016c868();
};
V_0016c868::~V_0016c868() { int n = size; shrink(n, Alloc()); delete data; }
