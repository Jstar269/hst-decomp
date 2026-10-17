/* HSTMATCH module=EBOOT.BIN start=0x000d8dcc end=0x000d8e34 symbol=__dt__10V_000d8dccFv */
/* Clone of src/eboot/dtor_000fc2ec.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
/* Vector-like container destructor: inline shrink(size) through a local copy (kept as a load/subtract,
   not folded) with an empty allocator class passed by value (the temporary reserves the 32-byte frame),
   then delete the element block. Names provisional. */
struct Alloc {};
struct Elem_000d8dcc { int v; ~Elem_000d8dcc() {} };
class V_000d8dcc {
public:
    Elem_000d8dcc *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_000d8dcc();
};
V_000d8dcc::~V_000d8dcc() { int n = size; shrink(n, Alloc()); delete data; }
