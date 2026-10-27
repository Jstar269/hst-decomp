/* HSTMATCH module=hstp_trans_main.prx start=0x002a2a40 end=0x002a2acc symbol=FUN_002a2a40 lang=c++ helpers=FUN_002a130c@0x002a130c-0x002a1338 */
/* Clone of src/eboot/power_callback_00291434.cpp (hstclone.py tag a0db26h2): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane sw1 near miss wip/power_callback_002a2a40.cpp, completed with its same-file static helper FUN_002a130c defined in front of it and placed at its own retail address by helpers=); exact match verified; names and types await human review. */
extern "C" {
extern unsigned char DAT_003f3b3c;
extern char DAT_003a87f4[];
extern char DAT_003a8834[];
extern char DAT_003a8874[];
static void FUN_002a130c(...)
{
}

int FUN_002a2a40(int param_1, unsigned param_2)
{
  if ((param_2 & 0x80000) != 0 || (param_2 & 0x10000) != 0) {
    DAT_003f3b3c = 1;
    if ((param_2 & 0x80000) != 0) {
      FUN_002a130c(DAT_003a87f4);
    }
    else {
      FUN_002a130c(DAT_003a8834);
    }
  }
  else {
    if ((param_2 & 0x40000) != 0) {
      DAT_003f3b3c = 0;
      FUN_002a130c(DAT_003a8874);
    }
  }
  return 0;
}
}
