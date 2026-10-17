/* HSTMATCH module=hstp_trans_main.prx start=0x001dce24 end=0x001dce8c symbol=__dt__10V_001dce24Fv */
/* Clone of src/eboot/dtor_00050ed4.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Vector-like container destructor: inline shrink(size) through a local copy (kept as a load/subtract,
   not folded) with an empty allocator class passed by value (the temporary reserves the 32-byte frame),
   then delete the element block. Names provisional. */
struct Alloc {};
struct Elem_001dce24 { int v; ~Elem_001dce24() {} };
class V_001dce24 {
public:
    Elem_001dce24 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_001dce24();
};
V_001dce24::~V_001dce24() { int n = size; shrink(n, Alloc()); delete data; }
