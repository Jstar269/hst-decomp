/* HSTMATCH module=EBOOT.BIN start=0x000043b4 end=0x00004400 symbol=FUN_000043b4 lang=c++ data=0x002cf254 */
/* Hand-written reconstruction from the disassembly: `throw std::length_error(msg)` (twin of src/sharing_main/length_error_throw_000043b4.cpp; constructor 0x3ab0, deleting destructor 0x39e8 and the runtime throw 0x260c are named through symbols/EBOOT.BIN.txt; the generated type-name string at 0x2cf254 is placed with data=); exact match verified; names and types await human review. */
namespace std {
class exception { public: exception(); virtual ~exception(); };
class logic_error : public exception { public: logic_error(const char *); virtual ~logic_error(); private: int pad[2]; };
class length_error : public logic_error { public: length_error(const char *); virtual ~length_error(); };
}
extern char DAT_002cf324[];
extern "C" void FUN_000043b4(void)
{
  throw std::length_error(DAT_002cf324);
}
