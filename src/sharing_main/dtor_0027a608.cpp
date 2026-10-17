/* HSTMATCH module=hstp_trans_main.prx start=0x0027a608 end=0x0027a678 symbol=__dt__10D_0027a608Fv */
/* Clone of src/eboot/dtor_00054cbc.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_0027a608 { int v; ~Elem_0027a608() {} };
class V_0027a608 {
public:
    Elem_0027a608 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_0027a608() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_0027a608 : public V_0027a608 { public: ~D_0027a608(); };
D_0027a608::~D_0027a608() { size = 0; }
