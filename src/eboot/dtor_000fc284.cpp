/* HSTMATCH module=EBOOT.BIN start=0x000fc284 end=0x000fc2ec symbol=__dt__10V_000fc284Fv */
/* Clone of src/eboot/dtor_000fc2ec.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
/* Vector-like container destructor: inline shrink(size) through a local copy (kept as a load/subtract,
   not folded) with an empty allocator class passed by value (the temporary reserves the 32-byte frame),
   then delete the element block. Names provisional. */
struct Alloc {};
struct Elem_000fc284 { int v; ~Elem_000fc284() {} };
class V_000fc284 {
public:
    Elem_000fc284 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_000fc284();
};
V_000fc284::~V_000fc284() { int n = size; shrink(n, Alloc()); delete data; }
