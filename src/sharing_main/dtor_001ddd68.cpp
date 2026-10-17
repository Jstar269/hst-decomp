/* HSTMATCH module=hstp_trans_main.prx start=0x001ddd68 end=0x001dddd8 symbol=__dt__10D_001ddd68Fv */
/* Clone of src/eboot/dtor_00054cbc.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_001ddd68 { int v; ~Elem_001ddd68() {} };
class V_001ddd68 {
public:
    Elem_001ddd68 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_001ddd68() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_001ddd68 : public V_001ddd68 { public: ~D_001ddd68(); };
D_001ddd68::~D_001ddd68() { size = 0; }
