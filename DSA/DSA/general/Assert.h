#pragma once

#include <cstdlib>
#include <stdio.h>
#include <conio.h>

#if defined(_MSC_VER)
	#define BREAK_IN_DEBUGGER() __debugbreak()
#elif defined(__GUNC__)
	#define BREAK_IN_DEBUGGER() __builtin_trap()
#else
	#error "Provide a implementation of BREAK_IN_DEBUGGER"
#endif // defined(_MSC_VER)



#if  defined(_DEBUG)

	#define EMIT_LOCATION() printf("File: %s, Line: %d\n", __FILE__, __LINE__)
	#define EMIT_STATEMENT_ERROR(error) printf("Assert: %s\n", error)
	#define DEBUG_PRINT(format, ...) {printf(format, __VA_ARGS__); EMIT_LOCATION();}
	#define ASSERT(condition) if((condition) == false) {EMIT_LOCATION(); BREAK_IN_DEBUGGER();}

#else

	#define EMIT_LOCATION() void(0)
	#define EMIT_STATEMENT_ERROR(error) void(0)
	#define DEBUG_PRINT(fmt, ...) void(0)
	#define assert(cmnd, errorCode) void(0)
#endif //  defined(_DEBUG)