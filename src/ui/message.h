/**
 * Simple way to style console text
 * @author Emilio Cobos (emiliocobos@usal.es)
 */
#ifndef __MESSAGE_H
#define __MESSAGE_H
#ifdef _WIN32
	#include "message-windows.h"
#else
	#include "message-linux.h"
#endif
#endif
