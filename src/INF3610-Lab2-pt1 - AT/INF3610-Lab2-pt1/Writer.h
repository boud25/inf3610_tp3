///////////////////////////////////////////////////////////////////////////////
//
//	Writer.h
//
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <systemc.h>
#include "LMBIF.h"


///////////////////////////////////////////////////////////////////////////////
//
//	Class Writer
//
///////////////////////////////////////////////////////////////////////////////
class Writer : public sc_module
{
public:
	// Ports
	/*

	À compléter

	*/
	sc_in_clk clk;					// clock
	sc_port<LMBIF> dataPortRAM;		// memory port
	sc_in<unsigned int> data;		// input data
	sc_in<unsigned int> address;	// memory address to read
	sc_out<bool> ack;				// ack signal	--> sent to master (Bubble)
	sc_in<bool> request;			// request signal --> from Master (Bubble)

									// Constructor
	Writer(sc_module_name name);

	// Destructor
	~Writer();

private:
	// Process SystemC
	/*

	À compléter

	*/
	SC_HAS_PROCESS(Writer);

	void thread(void);
};

