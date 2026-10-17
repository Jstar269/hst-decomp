/* HSTMATCH module=EBOOT.BIN start=0x00165724 end=0x0016578c symbol=__dt__10V_00165724Fv */
/* Clone of src/eboot/dtor_000fc2ec.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
/* Vector-like container destructor: inline shrink(size) through a local copy (kept as a load/subtract,
   not folded) with an empty allocator class passed by value (the temporary reserves the 32-byte frame),
   then delete the element block. Names provisional. */
struct Alloc {};
struct Elem_00165724 { int v; ~Elem_00165724() {} };
class V_00165724 {
public:
    Elem_00165724 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_00165724();
};
V_00165724::~V_00165724() { int n = size; shrink(n, Alloc()); delete data; }
