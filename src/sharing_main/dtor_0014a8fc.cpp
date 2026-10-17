/* HSTMATCH module=hstp_trans_main.prx start=0x0014a8fc end=0x0014a96c symbol=__dt__10D_0014a8fcFv */
/* Clone of src/eboot/dtor_00054cbc.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_0014a8fc { int v; ~Elem_0014a8fc() {} };
class V_0014a8fc {
public:
    Elem_0014a8fc *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_0014a8fc() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_0014a8fc : public V_0014a8fc { public: ~D_0014a8fc(); };
D_0014a8fc::~D_0014a8fc() { size = 0; }
