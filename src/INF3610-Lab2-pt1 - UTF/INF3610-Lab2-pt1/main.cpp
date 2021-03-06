///////////////////////////////////////////////////////////////////////////////
//
//	main.cpp
//
///////////////////////////////////////////////////////////////////////////////
#include <systemc.h>
#include "Bubble.h"
#include "Reader.h"
#include "DataRAM.h"
#include "Writer.h"
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
	
	// Components
	/* � compl�ter */
	// Modules instanciation
	DataRAM ram(sc_module_name("dataram"), "chiffre.hex", RAMSIZE);
	Bubble bubble(sc_module_name("bubble"));

	// Channel instanciation
	Reader reader(sc_module_name("reader"));
	Writer writer(sc_module_name("writer"));

	// Connexions
	/* � compl�ter */
	bubble.readPort(reader);
	bubble.writePort(writer);
	reader.dataPortRAM(ram);
	writer.dataPortRAM(ram);

	// D�marrage de l'application
	if (!m_bError)
	{
		cout << "D�marrage de la simulation." << endl;	
		sc_start( -1, sc_core::sc_time_unit(sim_units) );
		cout << endl << "Simulation s'est termin�e � " << sc_time_stamp();
	}
	// Fin du programme
	return 0;
}
