/* HSTMATCH module=hstp_trans_main.prx start=0x00147f54 end=0x00147fbc symbol=__dt__10V_00147f54Fv */
/* Clone of src/eboot/dtor_00050ed4.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
/* Vector-like container destructor: inline shrink(size) through a local copy (kept as a load/subtract,
   not folded) with an empty allocator class passed by value (the temporary reserves the 32-byte frame),
   then delete the element block. Names provisional. */
struct Alloc {};
struct Elem_00147f54 { int v; ~Elem_00147f54() {} };
class V_00147f54 {
public:
    Elem_00147f54 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_00147f54();
};
V_00147f54::~V_00147f54() { int n = size; shrink(n, Alloc()); delete data; }
