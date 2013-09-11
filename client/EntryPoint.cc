#include "EntryPoint.h"
#include "Quake3.h"
#include "Recordsystem.h"

Recordsystem *gRecordsystem = NULL;

extern "C" {
	DLLEXPORT void dllEntry( syscall_t syscall ) {
		gRecordsystem = new Recordsystem(syscall);
	}

	DLLEXPORT int vmMain( int command, int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11) {
		return gRecordsystem->VmMain(command, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
	}
}