/* HSTMATCH module=hstp_trans_main.prx start=0x0010f3e8 end=0x0010f458 symbol=__dt__10D_0010f3e8Fv */
/* Clone of src/eboot/dtor_00054cbc.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_0010f3e8 { int v; ~Elem_0010f3e8() {} };
class V_0010f3e8 {
public:
    Elem_0010f3e8 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_0010f3e8() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_0010f3e8 : public V_0010f3e8 { public: ~D_0010f3e8(); };
D_0010f3e8::~D_0010f3e8() { size = 0; }
