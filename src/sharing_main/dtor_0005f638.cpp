/* HSTMATCH module=hstp_trans_main.prx start=0x0005f638 end=0x0005f6a8 symbol=__dt__10D_0005f638Fv */
/* Clone of src/eboot/dtor_00054cbc.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_0005f638 { int v; ~Elem_0005f638() {} };
class V_0005f638 {
public:
    Elem_0005f638 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_0005f638() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_0005f638 : public V_0005f638 { public: ~D_0005f638(); };
D_0005f638::~D_0005f638() { size = 0; }
