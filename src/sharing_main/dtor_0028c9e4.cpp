/* HSTMATCH module=hstp_trans_main.prx start=0x0028c9e4 end=0x0028ca54 symbol=__dt__10D_0028c9e4Fv */
/* Clone of src/eboot/dtor_00054cbc.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_0028c9e4 { int v; ~Elem_0028c9e4() {} };
class V_0028c9e4 {
public:
    Elem_0028c9e4 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_0028c9e4() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_0028c9e4 : public V_0028c9e4 { public: ~D_0028c9e4(); };
D_0028c9e4::~D_0028c9e4() { size = 0; }
