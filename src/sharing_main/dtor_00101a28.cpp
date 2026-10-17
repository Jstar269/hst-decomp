/* HSTMATCH module=hstp_trans_main.prx start=0x00101a28 end=0x00101a90 symbol=__dt__10V_00101a28Fv */
/* Clone of src/eboot/dtor_00050ed4.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
/* Vector-like container destructor: inline shrink(size) through a local copy (kept as a load/subtract,
   not folded) with an empty allocator class passed by value (the temporary reserves the 32-byte frame),
   then delete the element block. Names provisional. */
struct Alloc {};
struct Elem_00101a28 { int v; ~Elem_00101a28() {} };
class V_00101a28 {
public:
    Elem_00101a28 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_00101a28();
};
V_00101a28::~V_00101a28() { int n = size; shrink(n, Alloc()); delete data; }
