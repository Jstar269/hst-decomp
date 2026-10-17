/* HSTMATCH module=hstp_trans_main.prx start=0x0029dec0 end=0x0029df28 symbol=__dt__10V_0029dec0Fv */
/* Clone of src/eboot/dtor_00050ed4.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Vector-like container destructor: inline shrink(size) through a local copy (kept as a load/subtract,
   not folded) with an empty allocator class passed by value (the temporary reserves the 32-byte frame),
   then delete the element block. Names provisional. */
struct Alloc {};
struct Elem_0029dec0 { int v; ~Elem_0029dec0() {} };
class V_0029dec0 {
public:
    Elem_0029dec0 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_0029dec0();
};
V_0029dec0::~V_0029dec0() { int n = size; shrink(n, Alloc()); delete data; }
