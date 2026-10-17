/* HSTMATCH module=hstp_trans_main.prx start=0x002a562c end=0x002a5694 symbol=__dt__10V_002a562cFv */
/* Clone of src/eboot/dtor_00050ed4.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Vector-like container destructor: inline shrink(size) through a local copy (kept as a load/subtract,
   not folded) with an empty allocator class passed by value (the temporary reserves the 32-byte frame),
   then delete the element block. Names provisional. */
struct Alloc {};
struct Elem_002a562c { int v; ~Elem_002a562c() {} };
class V_002a562c {
public:
    Elem_002a562c *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_002a562c();
};
V_002a562c::~V_002a562c() { int n = size; shrink(n, Alloc()); delete data; }
