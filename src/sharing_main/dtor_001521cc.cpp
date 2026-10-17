/* HSTMATCH module=hstp_trans_main.prx start=0x001521cc end=0x00152234 symbol=__dt__10V_001521ccFv */
/* Clone of src/eboot/dtor_00050ed4.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
/* Vector-like container destructor: inline shrink(size) through a local copy (kept as a load/subtract,
   not folded) with an empty allocator class passed by value (the temporary reserves the 32-byte frame),
   then delete the element block. Names provisional. */
struct Alloc {};
struct Elem_001521cc { int v; ~Elem_001521cc() {} };
class V_001521cc {
public:
    Elem_001521cc *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_001521cc();
};
V_001521cc::~V_001521cc() { int n = size; shrink(n, Alloc()); delete data; }
