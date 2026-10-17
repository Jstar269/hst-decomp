/* HSTMATCH module=EBOOT.BIN start=0x000d55e4 end=0x000d564c symbol=__dt__10V_000d55e4Fv */
/* Clone of src/eboot/dtor_000fc2ec.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
/* Vector-like container destructor: inline shrink(size) through a local copy (kept as a load/subtract,
   not folded) with an empty allocator class passed by value (the temporary reserves the 32-byte frame),
   then delete the element block. Names provisional. */
struct Alloc {};
struct Elem_000d55e4 { int v; ~Elem_000d55e4() {} };
class V_000d55e4 {
public:
    Elem_000d55e4 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_000d55e4();
};
V_000d55e4::~V_000d55e4() { int n = size; shrink(n, Alloc()); delete data; }
