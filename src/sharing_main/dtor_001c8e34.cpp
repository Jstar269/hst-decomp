/* HSTMATCH module=hstp_trans_main.prx start=0x001c8e34 end=0x001c8e9c symbol=__dt__10V_001c8e34Fv */
/* Clone of src/eboot/dtor_00050ed4.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Vector-like container destructor: inline shrink(size) through a local copy (kept as a load/subtract,
   not folded) with an empty allocator class passed by value (the temporary reserves the 32-byte frame),
   then delete the element block. Names provisional. */
struct Alloc {};
struct Elem_001c8e34 { int v; ~Elem_001c8e34() {} };
class V_001c8e34 {
public:
    Elem_001c8e34 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_001c8e34();
};
V_001c8e34::~V_001c8e34() { int n = size; shrink(n, Alloc()); delete data; }
