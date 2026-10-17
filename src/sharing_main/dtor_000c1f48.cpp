/* HSTMATCH module=hstp_trans_main.prx start=0x000c1f48 end=0x000c1fb0 symbol=__dt__10V_000c1f48Fv */
/* Clone of src/eboot/dtor_00050ed4.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
/* Vector-like container destructor: inline shrink(size) through a local copy (kept as a load/subtract,
   not folded) with an empty allocator class passed by value (the temporary reserves the 32-byte frame),
   then delete the element block. Names provisional. */
struct Alloc {};
struct Elem_000c1f48 { int v; ~Elem_000c1f48() {} };
class V_000c1f48 {
public:
    Elem_000c1f48 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_000c1f48();
};
V_000c1f48::~V_000c1f48() { int n = size; shrink(n, Alloc()); delete data; }
