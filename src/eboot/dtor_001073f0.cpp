/* HSTMATCH module=EBOOT.BIN start=0x001073f0 end=0x00107458 symbol=__dt__10V_001073f0Fv */
/* Clone of src/eboot/dtor_000fc2ec.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
/* Vector-like container destructor: inline shrink(size) through a local copy (kept as a load/subtract,
   not folded) with an empty allocator class passed by value (the temporary reserves the 32-byte frame),
   then delete the element block. Names provisional. */
struct Alloc {};
struct Elem_001073f0 { int v; ~Elem_001073f0() {} };
class V_001073f0 {
public:
    Elem_001073f0 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_001073f0();
};
V_001073f0::~V_001073f0() { int n = size; shrink(n, Alloc()); delete data; }
