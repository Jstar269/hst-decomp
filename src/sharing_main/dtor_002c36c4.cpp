/* HSTMATCH module=hstp_trans_main.prx start=0x002c36c4 end=0x002c372c symbol=__dt__10V_002c36c4Fv */
/* Clone of src/eboot/dtor_00050ed4.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Vector-like container destructor: inline shrink(size) through a local copy (kept as a load/subtract,
   not folded) with an empty allocator class passed by value (the temporary reserves the 32-byte frame),
   then delete the element block. Names provisional. */
struct Alloc {};
struct Elem_002c36c4 { int v; ~Elem_002c36c4() {} };
class V_002c36c4 {
public:
    Elem_002c36c4 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_002c36c4();
};
V_002c36c4::~V_002c36c4() { int n = size; shrink(n, Alloc()); delete data; }
