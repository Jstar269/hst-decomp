/* HSTMATCH module=hstp_trans_main.prx start=0x000c2e04 end=0x000c2e74 symbol=__dt__10D_000c2e04Fv */
/* Clone of src/eboot/dtor_00054cbc.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_000c2e04 { int v; ~Elem_000c2e04() {} };
class V_000c2e04 {
public:
    Elem_000c2e04 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_000c2e04() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_000c2e04 : public V_000c2e04 { public: ~D_000c2e04(); };
D_000c2e04::~D_000c2e04() { size = 0; }
