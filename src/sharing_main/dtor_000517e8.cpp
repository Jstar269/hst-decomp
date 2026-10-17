/* HSTMATCH module=hstp_trans_main.prx start=0x000517e8 end=0x00051850 symbol=__dt__10V_000517e8Fv */
/* Clone of src/eboot/dtor_00050ed4.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
/* Vector-like container destructor: inline shrink(size) through a local copy (kept as a load/subtract,
   not folded) with an empty allocator class passed by value (the temporary reserves the 32-byte frame),
   then delete the element block. Names provisional. */
struct Alloc {};
struct Elem_000517e8 { int v; ~Elem_000517e8() {} };
class V_000517e8 {
public:
    Elem_000517e8 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_000517e8();
};
V_000517e8::~V_000517e8() { int n = size; shrink(n, Alloc()); delete data; }
