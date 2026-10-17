/* HSTMATCH module=hstp_trans_main.prx start=0x0016cc10 end=0x0016cc80 symbol=__dt__10D_0016cc10Fv */
/* Clone of src/eboot/dtor_00054cbc.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_0016cc10 { int v; ~Elem_0016cc10() {} };
class V_0016cc10 {
public:
    Elem_0016cc10 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_0016cc10() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_0016cc10 : public V_0016cc10 { public: ~D_0016cc10(); };
D_0016cc10::~D_0016cc10() { size = 0; }
