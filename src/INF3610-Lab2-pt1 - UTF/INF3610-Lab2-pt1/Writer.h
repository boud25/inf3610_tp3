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
	/* └ complÚter */
	sc_port<LMBIF> dataPortRAM;

	// Constructor
	Writer(sc_module_name name);

	// Destructor
	~Writer();

private:
	/* └ complÚter */
	unsigned int Write(unsigned int offset, unsigned int data);
};

