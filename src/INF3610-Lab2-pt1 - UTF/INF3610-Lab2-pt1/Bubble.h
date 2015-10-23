///////////////////////////////////////////////////////////////////////////////
//
//	Bubble.h
//
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <systemc.h>
#include <stdio.h>
#include "InterfaceRead.h"
#include "InterfaceWrite.h"


///////////////////////////////////////////////////////////////////////////////
//
//	Class Bubble
//
///////////////////////////////////////////////////////////////////////////////
class Bubble : public sc_module
{
	public: 
		// Ports    
		/* À compléter */
		sc_port<InterfaceRead> readPort;
		sc_port<InterfaceWrite> writePort;
	
		// Constructor
		Bubble( sc_module_name name );
		
		// Destructor
		~Bubble();
		
	private:
		// Process SystemC
		SC_HAS_PROCESS(Bubble);
		
		void thread(void);
		void bubbleSort(unsigned int *ptr, int counter);
};

