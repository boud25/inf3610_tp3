///////////////////////////////////////////////////////////////////////////////
//
//	InterfaceRead.h
//
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <systemc.h>

///////////////////////////////////////////////////////////////////////////////
//
//	Classe InterfaceRead
//
///////////////////////////////////////////////////////////////////////////////
class InterfaceRead : public virtual sc_interface
{
	public:

		// M�thode
		virtual unsigned int Read(unsigned int offset)	= 0;

};

