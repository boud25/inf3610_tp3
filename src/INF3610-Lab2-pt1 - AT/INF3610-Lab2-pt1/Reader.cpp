///////////////////////////////////////////////////////////////////////////////
//
//	Reader.cpp
//
///////////////////////////////////////////////////////////////////////////////
#include "Reader.h"

///////////////////////////////////////////////////////////////////////////////
//
//	Constructor
//
///////////////////////////////////////////////////////////////////////////////
Reader::Reader(sc_module_name name)
	: sc_channel(name)
{
	/*
	
	└ complÚter
	
	*/
	SC_THREAD(thread);
}

///////////////////////////////////////////////////////////////////////////////
//
//	Destructor
//
///////////////////////////////////////////////////////////////////////////////
Reader::~Reader()
{
	/*
	
	└ complÚter
	
	*/
}

///////////////////////////////////////////////////////////////////////////////
//
//	Thread
//
///////////////////////////////////////////////////////////////////////////////
void Reader::thread(void)
{
	/*
	
	└ complÚter
	
	*/
	// Synchronize to gather the reading address 
	while (1)
	{
		do
		{
			wait(clk.posedge_event());
			if (isFirstTimeInLoop)
			{
				ack.write(false);
				isFirstTimeInLoop = false;
			}
			
		} while (!request.read());

		isFirstTimeInLoop = true;

		// Write the corresponding data
		data.write(dataPortRAM->Read(address.read()));

		// Ack bubble that the request was served
		ack.write(true);
	}
}