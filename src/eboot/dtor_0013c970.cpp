/* HSTMATCH module=EBOOT.BIN start=0x0013c970 end=0x0013c9d8 symbol=__dt__10V_0013c970Fv */
/* Clone of src/eboot/dtor_000fc2ec.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
/* Vector-like container destructor: inline shrink(size) through a local copy (kept as a load/subtract,
   not folded) with an empty allocator class passed by value (the temporary reserves the 32-byte frame),
   then delete the element block. Names provisional. */
struct Alloc {};
struct Elem_0013c970 { int v; ~Elem_0013c970() {} };
class V_0013c970 {
public:
    Elem_0013c970 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_0013c970();
};
V_0013c970::~V_0013c970() { int n = size; shrink(n, Alloc()); delete data; }
