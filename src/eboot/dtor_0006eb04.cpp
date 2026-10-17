/* HSTMATCH module=EBOOT.BIN start=0x0006eb04 end=0x0006eb6c symbol=__dt__10V_0006eb04Fv */
/* Clone of src/eboot/dtor_000fc2ec.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
/* Vector-like container destructor: inline shrink(size) through a local copy (kept as a load/subtract,
   not folded) with an empty allocator class passed by value (the temporary reserves the 32-byte frame),
   then delete the element block. Names provisional. */
struct Alloc {};
struct Elem_0006eb04 { int v; ~Elem_0006eb04() {} };
class V_0006eb04 {
public:
    Elem_0006eb04 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_0006eb04();
};
V_0006eb04::~V_0006eb04() { int n = size; shrink(n, Alloc()); delete data; }
