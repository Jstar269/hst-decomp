/* HSTMATCH module=hstp_trans_main.prx start=0x00092f18 end=0x00092f80 symbol=__dt__10V_00092f18Fv */
/* Clone of src/eboot/dtor_00050ed4.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
/* Vector-like container destructor: inline shrink(size) through a local copy (kept as a load/subtract,
   not folded) with an empty allocator class passed by value (the temporary reserves the 32-byte frame),
   then delete the element block. Names provisional. */
struct Alloc {};
struct Elem_00092f18 { int v; ~Elem_00092f18() {} };
class V_00092f18 {
public:
    Elem_00092f18 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_00092f18();
};
V_00092f18::~V_00092f18() { int n = size; shrink(n, Alloc()); delete data; }
