/* HSTMATCH module=EBOOT.BIN start=0x00147384 end=0x001473ec symbol=__dt__10V_00147384Fv */
/* Clone of src/eboot/dtor_000fc2ec.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
/* Vector-like container destructor: inline shrink(size) through a local copy (kept as a load/subtract,
   not folded) with an empty allocator class passed by value (the temporary reserves the 32-byte frame),
   then delete the element block. Names provisional. */
struct Alloc {};
struct Elem_00147384 { int v; ~Elem_00147384() {} };
class V_00147384 {
public:
    Elem_00147384 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_00147384();
};
V_00147384::~V_00147384() { int n = size; shrink(n, Alloc()); delete data; }
