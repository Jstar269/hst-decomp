/* HSTMATCH module=hstp_trans_main.prx start=0x0005a5ac end=0x0005a614 symbol=__dt__10V_0005a5acFv */
/* Clone of src/eboot/dtor_00050ed4.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
/* Vector-like container destructor: inline shrink(size) through a local copy (kept as a load/subtract,
   not folded) with an empty allocator class passed by value (the temporary reserves the 32-byte frame),
   then delete the element block. Names provisional. */
struct Alloc {};
struct Elem_0005a5ac { int v; ~Elem_0005a5ac() {} };
class V_0005a5ac {
public:
    Elem_0005a5ac *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_0005a5ac();
};
V_0005a5ac::~V_0005a5ac() { int n = size; shrink(n, Alloc()); delete data; }
