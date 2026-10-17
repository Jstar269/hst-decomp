/* HSTMATCH module=EBOOT.BIN start=0x002b3c04 end=0x002b3c6c symbol=__dt__10V_002b3c04Fv */
/* Clone of src/eboot/dtor_000fc2ec.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
/* Vector-like container destructor: inline shrink(size) through a local copy (kept as a load/subtract,
   not folded) with an empty allocator class passed by value (the temporary reserves the 32-byte frame),
   then delete the element block. Names provisional. */
struct Alloc {};
struct Elem_002b3c04 { int v; ~Elem_002b3c04() {} };
class V_002b3c04 {
public:
    Elem_002b3c04 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_002b3c04();
};
V_002b3c04::~V_002b3c04() { int n = size; shrink(n, Alloc()); delete data; }
