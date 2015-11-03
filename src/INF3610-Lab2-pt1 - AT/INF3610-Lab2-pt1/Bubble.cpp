///////////////////////////////////////////////////////////////////////////////
//
//	Bubble.cpp
//
///////////////////////////////////////////////////////////////////////////////
#include "Bubble.h"


///////////////////////////////////////////////////////////////////////////////
//
//	Constructeur
//
///////////////////////////////////////////////////////////////////////////////
Bubble::Bubble( sc_module_name name )
/* À compléter */
{
	/*
	
	À compléter
	
	*/
	SC_THREAD(thread);
}


///////////////////////////////////////////////////////////////////////////////
//
//	Destructeur
//
///////////////////////////////////////////////////////////////////////////////
Bubble::~Bubble()
{
	/*
	
	À compléter
	
	*/
}


///////////////////////////////////////////////////////////////////////////////
//
//	thread
//
///////////////////////////////////////////////////////////////////////////////
void Bubble::thread(void)
{
	/*
	
	À compléter
	
	*/
	while (1)
	{
		// Read the amount of elements to read
		unsigned int nbElements = readData(0);

		// Read those elements
		unsigned int* elements;
		elements = new unsigned int[nbElements];
		for (unsigned int i = 0; i < nbElements; i++)
		{
			elements[i] = readData(i+1);
		}

		// Sort those value
		bubbleSort(elements, nbElements);

		// Write the sorted elements
		for (unsigned int i = 0; i < nbElements; i++)
		{
			writeData(i, elements[i]);
		}

		delete []elements;
		elements = nullptr;

		// Stopping the app
		sc_stop();
	}
	

}

///////////////////////////////////////////////////////////////////////////////
//
//	readData
//
///////////////////////////////////////////////////////////////////////////////
unsigned int Bubble::readData(unsigned int offset)
{
	// Synchonize and read the data
	address.write(offset * 4);
	requestRead.write(true);
	do
	{
		wait(clk.posedge_event());
	} while (!ack.read());

	requestRead.write(false);

	return data.read();
}

///////////////////////////////////////////////////////////////////////////////
//
//	writeData
//
///////////////////////////////////////////////////////////////////////////////
void Bubble::writeData(unsigned int offset, unsigned int d)
{
	// Synchonize and write the data
	address.write(offset * 4);
	data.write(d);
	requestWrite.write(true);
	do
	{
		wait(clk.posedge_event());
	} while (!ack.read());

	requestWrite.write(false);

	return;
}

///////////////////////////////////////////////////////////////////////////////
//
//	bubbleSort
//
///////////////////////////////////////////////////////////////////////////////
void Bubble::bubbleSort(unsigned int *ptr, int counter)
{
	// Variable
	unsigned int tmp = 0;
	
	for (int i = 1; i < counter; ++i){
		for (int j = 0; j < counter - i; ++j){
			if (ptr[j] > ptr[j + 1]){
				// Changing position
				tmp = ptr[j];
				ptr[j] = ptr[j + 1];
				ptr[j + 1] = tmp;
			}
	
		}
	}
	// Display
	for (int i = 0; i < counter; i++)
		cout << ptr[i] << endl;
}
