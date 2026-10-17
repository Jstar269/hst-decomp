/* HSTMATCH module=hstp_trans_main.prx start=0x001b5e30 end=0x001b5ea0 symbol=__dt__10D_001b5e30Fv */
/* Clone of src/eboot/dtor_00054cbc.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_001b5e30 { int v; ~Elem_001b5e30() {} };
class V_001b5e30 {
public:
    Elem_001b5e30 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_001b5e30() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_001b5e30 : public V_001b5e30 { public: ~D_001b5e30(); };
D_001b5e30::~D_001b5e30() { size = 0; }
