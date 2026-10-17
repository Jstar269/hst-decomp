/* HSTMATCH module=EBOOT.BIN start=0x00146adc end=0x00146b44 symbol=__dt__10V_00146adcFv */
/* Clone of src/eboot/dtor_000fc2ec.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
/* Vector-like container destructor: inline shrink(size) through a local copy (kept as a load/subtract,
   not folded) with an empty allocator class passed by value (the temporary reserves the 32-byte frame),
   then delete the element block. Names provisional. */
struct Alloc {};
struct Elem_00146adc { int v; ~Elem_00146adc() {} };
class V_00146adc {
public:
    Elem_00146adc *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_00146adc();
};
V_00146adc::~V_00146adc() { int n = size; shrink(n, Alloc()); delete data; }
