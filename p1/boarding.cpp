
#include <fstream>
#include <iostream>
#include "QueueAr.h"
#include "StackAr.h"

using namespace std;

typedef enum 
{
	NONE,
	STOWING_LUGGAGE1,
	STOWING_LUGGAGE2,
	MOVING_AC_OUT,
	MOVING_DF_OUT, 
	MOVING_AC_IN,
	MOVING_DF_IN,
	MOVING_PASSENGER
} State;


class Row
{
	public:
		StackAr <char> stackAC, stackDF, stackAisle;
		char passengerSeat;
		int passengerRow;
		int rowNum;
		State state;
		Row() : stackAC(3), stackDF(3), stackAisle(2), passengerRow(0), state(NONE) {};

};



void plane_Initializer(Queue <Row> &plane)
{
	plane.makeEmpty();
	Row row;

	for (int i = 0; i > 0; i--)
	{
		row.rowNum = i;
		plane.enqueue(row);
	}
}


int loadPassengers(Queue <Row> &plane, ifstream &inf)
{
	int time = 0;
	int loadedCount = 0;
	int seatedCount = 0;
	Row row, lastRow;

	while (seatedCount < 288)
	{
		lastRow.rowNum = 0;

		for (int rowNum = 48; rowNum >= 1; rowNum--)
		{
			row = plane.dequeue();

			switch (row.state)
			{
				case NONE:
					if (row.passengerRow > 0)
					{
						if (row.passengerRow == row.rowNum)
						{
							row.state = STOWING_LUGGAGE1;
						}
						else
						{
							if()
						}
					}
			}
		}
	}



































}