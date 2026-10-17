/* HSTMATCH module=hstp_trans_main.prx start=0x00186544 end=0x001865ac symbol=__dt__10V_00186544Fv */
/* Clone of src/eboot/dtor_00050ed4.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
/* Vector-like container destructor: inline shrink(size) through a local copy (kept as a load/subtract,
   not folded) with an empty allocator class passed by value (the temporary reserves the 32-byte frame),
   then delete the element block. Names provisional. */
struct Alloc {};
struct Elem_00186544 { int v; ~Elem_00186544() {} };
class V_00186544 {
public:
    Elem_00186544 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_00186544();
};
V_00186544::~V_00186544() { int n = size; shrink(n, Alloc()); delete data; }
