///////////////////////////////////////////////////////////////////////////////
//
//	Writer.h
//
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <systemc.h>
#include "LMBIF.h"
#include "InterfaceWrite.h"

///////////////////////////////////////////////////////////////////////////////
//
//	Class Writer
//
///////////////////////////////////////////////////////////////////////////////
class Writer : public sc_channel, public InterfaceWrite
{
public:
	// Ports
	/* À compléter */
	sc_port<LMBIF> dataPortRAM;

	// Constructor
	Writer(sc_module_name name);

	// Destructor
	~Writer();

	void Write(unsigned int offset, unsigned int data);

private:
	/* À compléter */
	// It is a bit useless to remember the name of the module considering
	// the fact that in this situation there's only one writer.
	
};

