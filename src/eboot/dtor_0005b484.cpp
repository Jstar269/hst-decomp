/* HSTMATCH module=EBOOT.BIN start=0x0005b484 end=0x0005b4ec symbol=__dt__10V_0005b484Fv */
/* Clone of src/eboot/dtor_000fc2ec.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
/* Vector-like container destructor: inline shrink(size) through a local copy (kept as a load/subtract,
   not folded) with an empty allocator class passed by value (the temporary reserves the 32-byte frame),
   then delete the element block. Names provisional. */
struct Alloc {};
struct Elem_0005b484 { int v; ~Elem_0005b484() {} };
class V_0005b484 {
public:
    Elem_0005b484 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_0005b484();
};
V_0005b484::~V_0005b484() { int n = size; shrink(n, Alloc()); delete data; }
