/* HSTMATCH module=hstp_trans_main.prx start=0x0010f458 end=0x0010f4c8 symbol=__dt__10D_0010f458Fv */
/* Clone of src/eboot/dtor_00054cbc.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_0010f458 { int v; ~Elem_0010f458() {} };
class V_0010f458 {
public:
    Elem_0010f458 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_0010f458() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_0010f458 : public V_0010f458 { public: ~D_0010f458(); };
D_0010f458::~D_0010f458() { size = 0; }
