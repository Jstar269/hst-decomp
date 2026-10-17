/* HSTMATCH module=hstp_trans_main.prx start=0x000706c4 end=0x00070734 symbol=__dt__10D_000706c4Fv */
/* Clone of src/eboot/dtor_00054cbc.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_000706c4 { int v; ~Elem_000706c4() {} };
class V_000706c4 {
public:
    Elem_000706c4 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_000706c4() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_000706c4 : public V_000706c4 { public: ~D_000706c4(); };
D_000706c4::~D_000706c4() { size = 0; }
