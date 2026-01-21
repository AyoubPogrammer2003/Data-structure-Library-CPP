#pragma once
#include<iostream>
#include<queue>
#include<stack>
#include<string>
#include "Lib/clsDate.h"
using namespace std;
class clsQueueLine
{
private:
	string _Prefix = "";
	short _TotalTicketsCount = 0;
	short _AverageServingTime = 0;
	
	class clsTicket {

	private:
		int _Number = 0;
		string _Prefix = "";
		string _TicketTime;
		short _WatingClients = 0;
		short _AvrageServeTime = 0;
		short _ExpectedServeTime = 0;

	public:

		clsTicket(string Prefix, short Number, short WatingClients, short AvrageServeTime)
		{
			_Number = Number;
			_Prefix = Prefix;
			_TicketTime = clsDate::GetSystemdateToString().;
			_WatingClients = WatingClients;
			_AvrageServeTime = AvrageServeTime;			
		}

		string Prefix()
		{
			return _Prefix;

		}
		short Number()
		{
			return _Number;
		}

		string FullNumber()
		{
			return _Prefix + to_string(_Number);
		}

		string TicketTime()
		{
			return _TicketTime;
		}

		short WaitingClients()
		{
			return _WatingClients;
		}

		short ExpectedServeTime()
		{
			return _AvrageServeTime * _WatingClients;
		}

	};
public:
	queue <clsTicket> QueueLine; 

	clsQueueLine(string Prefix, short AverageServeTime)
	{
		_Prefix = Prefix;
		_AverageServingTime = AverageServeTime;
	}

	void IssueTicket()
	{
		_TotalTicketsCount++;
		clsTicket Ticket(_Prefix, _TotalTicketsCount, WatingClients(), _AverageServingTime);
		QueueLine.push(Ticket);
	}
	short WatingClients()
	{
		return QueueLine.size();
	}

	string HowIsNext()
	{
		if (QueueLine.empty())
			return "No Clients Left.";
		else
		
			return QueueLine.front().FullNumber();
	}

	bool ServeNextClient()
	{
		if (QueueLine.empty())
			return false;
		else
		{
			QueueLine.pop();
			return true;
		}
	}

	short ServeClients()
	{
		return _TotalTicketsCount - QueueLine.size();
	}

	void PrintInfo()
	{
		cout << "\n\t\t\t _________________________\n";
		cout << "\n\t\t\t\tQueue Info";
		cout << "\n\t\t\t _________________________\n";
		cout << "\n\t\t\t    Prefix   = " << _Prefix;
		cout << "\n\t\t\t    Total Tickets   = " << _TotalTicketsCount;
		cout << "\n\t\t\t    Served Clients  = " << ServeClients();
		cout << "\n\t\t\t    Wating Clients  = " << WatingClients() ;
		cout << "\n\t\t\t _________________________\n";
		cout << "\n";

	}




};

