/* HSTMATCH module=EBOOT.BIN start=0x001474d0 end=0x00147538 symbol=__dt__10V_001474d0Fv */
/* Clone of src/eboot/dtor_000fc2ec.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
/* Vector-like container destructor: inline shrink(size) through a local copy (kept as a load/subtract,
   not folded) with an empty allocator class passed by value (the temporary reserves the 32-byte frame),
   then delete the element block. Names provisional. */
struct Alloc {};
struct Elem_001474d0 { int v; ~Elem_001474d0() {} };
class V_001474d0 {
public:
    Elem_001474d0 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_001474d0();
};
V_001474d0::~V_001474d0() { int n = size; shrink(n, Alloc()); delete data; }
