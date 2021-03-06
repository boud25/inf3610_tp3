///////////////////////////////////////////////////////////////////////////////
//
//	Reader.h
//
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <systemc.h>
#include "LMBIF.h"
#include "InterfaceRead.h"

///////////////////////////////////////////////////////////////////////////////
//
//	Class Reader
//
///////////////////////////////////////////////////////////////////////////////
class Reader : public sc_channel, public InterfaceRead
{
	public:
		// Ports
		/* └ complÚter */
		sc_port<LMBIF> dataPortRAM;

		unsigned int Read(unsigned int offset);
		
		// Constructor
		Reader( sc_module_name name );

		// Destructor
		~Reader();

	private:
		/* └ complÚter */
		// It is a bit useless to remember the name of the module considering
		// the fact that in this situation there's only one reader.
};

