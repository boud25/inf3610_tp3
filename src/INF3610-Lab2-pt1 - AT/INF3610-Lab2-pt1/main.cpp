///////////////////////////////////////////////////////////////////////////////
//
//	main.cpp
//
///////////////////////////////////////////////////////////////////////////////
#include <systemc.h>
#include "Bubble.h"
#include "Reader.h"
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

	// Signal
	sc_signal<bool> requestReader, ackReader;
	sc_signal<unsigned int> dataReader, addressReader;
	sc_clock clock("clock");

	// Connexions
	bubble.clk(clock);
	reader.clk(clock);
	bubble.ack(ackReader);
	reader.ack(ackReader);
	bubble.data(dataReader);
	reader.data(dataReader);
	bubble.address(addressReader);
	reader.address(addressReader);
	bubble.requestRead(requestReader);
	reader.request(requestReader);

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
