/* HSTMATCH module=hstp_trans_main.prx start=0x001481c0 end=0x00148228 symbol=__dt__10V_001481c0Fv */
/* Clone of src/eboot/dtor_00050ed4.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
/* Vector-like container destructor: inline shrink(size) through a local copy (kept as a load/subtract,
   not folded) with an empty allocator class passed by value (the temporary reserves the 32-byte frame),
   then delete the element block. Names provisional. */
struct Alloc {};
struct Elem_001481c0 { int v; ~Elem_001481c0() {} };
class V_001481c0 {
public:
    Elem_001481c0 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_001481c0();
};
V_001481c0::~V_001481c0() { int n = size; shrink(n, Alloc()); delete data; }
