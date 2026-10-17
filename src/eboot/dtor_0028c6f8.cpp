/* HSTMATCH module=EBOOT.BIN start=0x0028c6f8 end=0x0028c760 symbol=__dt__10V_0028c6f8Fv */
/* Clone of src/eboot/dtor_000fc2ec.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
/* Vector-like container destructor: inline shrink(size) through a local copy (kept as a load/subtract,
   not folded) with an empty allocator class passed by value (the temporary reserves the 32-byte frame),
   then delete the element block. Names provisional. */
struct Alloc {};
struct Elem_0028c6f8 { int v; ~Elem_0028c6f8() {} };
class V_0028c6f8 {
public:
    Elem_0028c6f8 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_0028c6f8();
};
V_0028c6f8::~V_0028c6f8() { int n = size; shrink(n, Alloc()); delete data; }
