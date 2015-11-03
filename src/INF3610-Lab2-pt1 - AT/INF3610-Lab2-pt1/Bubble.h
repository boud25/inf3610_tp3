///////////////////////////////////////////////////////////////////////////////
//
//	Bubble.h
//
///////////////////////////////////////////////////////////////////////////////
#ifndef _BUBBLE_H_
#define _BUBBLE_H_

#include <systemc.h>
#include <stdio.h>


///////////////////////////////////////////////////////////////////////////////
//
//	Class Bubble
//
///////////////////////////////////////////////////////////////////////////////
class Bubble : public sc_module
{
	public: 
		// Ports
		/*
		
		À compléter
		
		*/
		sc_in_clk clk;					// clock
		sc_out<unsigned int> address;	// address to read or write
		sc_inout<unsigned int> data;	// data that was read or to be writen
		sc_out<bool> requestRead;		// signal to read --> sent to Reader
		sc_out<bool> requestWrite;		// signal to write --> sent to Writer
		sc_in<bool> ack;				// signal of the ack --> from Slave (Reader or Writer)
	
		// Constructor
		Bubble( sc_module_name name );
		
		// Destructor
		~Bubble();
		
	private:
		/*
		
		À compléter
		
		*/
		SC_HAS_PROCESS(Bubble);
		
		void thread(void);

		unsigned int readData(unsigned int offset);
		void bubbleSort(unsigned int *ptr, int counter);
};

#endif
