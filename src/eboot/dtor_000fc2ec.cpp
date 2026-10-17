/* HSTMATCH module=EBOOT.BIN start=0x000fc2ec end=0x000fc354 symbol=__dt__10V_000fc2ecFv */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
/* Vector-like container destructor: inline shrink(size) through a local copy (kept as a load/subtract,
   not folded) with an empty allocator class passed by value (the temporary reserves the 32-byte frame),
   then delete the element block. Names provisional. */
struct Alloc {};
struct Elem_000fc2ec { int v; ~Elem_000fc2ec() {} };
class V_000fc2ec {
public:
    Elem_000fc2ec *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_000fc2ec();
};
V_000fc2ec::~V_000fc2ec() { int n = size; shrink(n, Alloc()); delete data; }
