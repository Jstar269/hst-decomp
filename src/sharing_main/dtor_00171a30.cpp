/* HSTMATCH module=hstp_trans_main.prx start=0x00171a30 end=0x00171a98 symbol=__dt__10V_00171a30Fv */
/* Clone of src/eboot/dtor_00050ed4.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
/* Vector-like container destructor: inline shrink(size) through a local copy (kept as a load/subtract,
   not folded) with an empty allocator class passed by value (the temporary reserves the 32-byte frame),
   then delete the element block. Names provisional. */
struct Alloc {};
struct Elem_00171a30 { int v; ~Elem_00171a30() {} };
class V_00171a30 {
public:
    Elem_00171a30 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_00171a30();
};
V_00171a30::~V_00171a30() { int n = size; shrink(n, Alloc()); delete data; }
