///////////////////////////////////////////////////////////////////////////////
//
//	InterfaceWrite.h
//
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <systemc.h>

///////////////////////////////////////////////////////////////////////////////
//
//	Classe InterfaceWrite
//
///////////////////////////////////////////////////////////////////////////////
class InterfaceWrite : public virtual sc_interface
{
public:

	// M�thode
	virtual unsigned int Write(unsigned int offset, unsigned int data) = 0; // TODO

};

