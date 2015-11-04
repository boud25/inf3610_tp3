///////////////////////////////////////////////////////////////////////////////
//
//	Reader.h
//
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <systemc.h>
#include "LMBIF.h"


///////////////////////////////////////////////////////////////////////////////
//
//	Class Reader
//
///////////////////////////////////////////////////////////////////////////////
class Reader : public sc_module
{
	public:
		// Ports
		/*
		
		À compléter
		
		*/
		sc_in_clk clk;					// clock
		sc_port<LMBIF> dataPortRAM;		// memory port
		sc_out<unsigned int> data;		// output data
		sc_in<unsigned int> address;	// memory address to read
		sc_out<bool> ack;				// ack signal	--> sent to master (Bubble)
		sc_in<bool> request;			// request signal --> from Master (Bubble)

		// Constructor
		Reader( sc_module_name name );

		// Destructor
		~Reader();

	private:
		// Process SystemC
		/*
		
		À compléter
		
		*/
		SC_HAS_PROCESS(Reader);
		
		void thread(void);

		// Synchro boolean
		bool isFirstTimeInLoop = true;
};

