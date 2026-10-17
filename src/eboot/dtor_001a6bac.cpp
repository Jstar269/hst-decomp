/* HSTMATCH module=EBOOT.BIN start=0x001a6bac end=0x001a6c14 symbol=__dt__10V_001a6bacFv */
/* Clone of src/eboot/dtor_000fc2ec.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
/* Vector-like container destructor: inline shrink(size) through a local copy (kept as a load/subtract,
   not folded) with an empty allocator class passed by value (the temporary reserves the 32-byte frame),
   then delete the element block. Names provisional. */
struct Alloc {};
struct Elem_001a6bac { int v; ~Elem_001a6bac() {} };
class V_001a6bac {
public:
    Elem_001a6bac *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_001a6bac();
};
V_001a6bac::~V_001a6bac() { int n = size; shrink(n, Alloc()); delete data; }
