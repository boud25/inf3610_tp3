///////////////////////////////////////////////////////////////////////////////
//
//	main.cpp
//
///////////////////////////////////////////////////////////////////////////////
#include <systemc.h>
#include "Bubble.h"
#include "Reader.h"
#include "Writer.h"
#include "DataRAM.h"

#define RAMSIZE 0x400

// Global variables
bool m_bError = false;

///////////////////////////////////////////////////////////////////////////////
//
//	Main
//
///////////////////////////////////////////////////////////////////////////////
int sc_main(int arg_count, char **arg_value)
{
	// Variables
	int sim_units = 2; //SC_NS 
	
	/*
	
	À compléter
	
	*/
	// Module instanciation
	DataRAM ram(sc_module_name("dataram"), "chiffre.hex", RAMSIZE);
	Bubble bubble(sc_module_name("bubble"));

	// Channel instatiation
	Reader reader(sc_module_name("reader"));
	Writer writer(sc_module_name("writer"));

	// Signal
	sc_signal<bool> requestReader, requestWriter, ack;
	sc_signal<unsigned int> data, address;
	sc_clock clock("clock");

	// Connexions
	bubble.clk(clock);
	reader.clk(clock);
	writer.clk(clock);
	bubble.ack(ack);
	reader.ack(ack);
	writer.ack(ack);
	bubble.data(data);
	reader.data(data);
	writer.data(data);
	bubble.address(address);
	reader.address(address);
	writer.address(address);
	bubble.requestRead(requestReader);
	reader.request(requestReader);
	bubble.requestWrite(requestWriter);
	writer.request(requestWriter);

	reader.dataPortRAM(ram);

	// Démarrage de l'application
	if (!m_bError)
	{
		cout << "Démarrage de la simulation." << endl;
		sc_start( -1, sc_core::sc_time_unit(sim_units) );
		cout << endl << "Simulation s'est terminée à " << sc_time_stamp();
	}
	// Fin du programme
	return 0;
}
