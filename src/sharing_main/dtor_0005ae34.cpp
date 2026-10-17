/* HSTMATCH module=hstp_trans_main.prx start=0x0005ae34 end=0x0005aea4 symbol=__dt__10D_0005ae34Fv */
/* Clone of src/eboot/dtor_00054cbc.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_0005ae34 { int v; ~Elem_0005ae34() {} };
class V_0005ae34 {
public:
    Elem_0005ae34 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_0005ae34() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_0005ae34 : public V_0005ae34 { public: ~D_0005ae34(); };
D_0005ae34::~D_0005ae34() { size = 0; }
