#pragma once
#pragma warning(disable : 4996)
#include <queue>
#include <iostream>
#include <string>
#include <stack>
using namespace std;
class clsQueueLine
{
protected:

	struct ClientData {
		int Number;
		string Date;
		string Time;
	};

	queue<ClientData> _Line;
	string _Prefix = "";
	int _TotolTickets = 0;
	int _ServedClients = 0;
	int _WaitingClients = 0;
	int _ServiceDuration = 0;

public:



	clsQueueLine(string Prefix, int Duration) {
		_Prefix = Prefix;
		_ServiceDuration = Duration;
	}

	static string GetSystemDateTimeString()
	{
		//system datetime string
		time_t t = time(0);
		tm* now = localtime(&t);

		short Day, Month, Year, Hour, Minute, Second;

		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_mday;
		Hour = now->tm_hour;
		Minute = now->tm_min;
		Second = now->tm_sec;

		return (to_string(Day) + "/" + to_string(Month) + "/"
			+ to_string(Year) + " - "
			+ to_string(Hour) + ":" + to_string(Minute)
			+ ":" + to_string(Second));

	}

	void IssueTicket() {
		ClientData Data;
		Data.Number = _TotolTickets + 1;
		Data.Time = GetSystemDateTimeString();
		_TotolTickets++;
		_WaitingClients++;

		_Line.push(Data);
	}

	void PrintInfo() {
		cout << "----------------------------------\n";
		cout << "\n\n\nQueue Info\n";
		cout << "----------------------------------\n";
		cout << "\n\nPrefix : "<< _Prefix;
		cout << "\n\nTotal Tickets : "<< _TotolTickets;
		cout << "\n\nServed Clients : "<< _ServedClients;
		cout << "\n\nWaiting Clients : "<< _WaitingClients;
		cout << "\n----------------------------------\n";
	}

	void PrintTicketsLineRTL() {
		queue<ClientData> Temp = _Line;
		Reverse(Temp);
		cout << "\nTickets:  ";
		while (!Temp.empty()) {
			ClientData Data = Temp.front();
			cout << _Prefix+to_string(Data.Number);
			Temp.pop();
			if (!Temp.empty()) {
				cout << " <-- ";
			}
		}
	}
	void Reverse(queue<ClientData> &Queue) {
		stack <ClientData> Temp;
		while (!Queue.empty()) {
			Temp.push(Queue.front());
			Queue.pop();
		}
		while (!Temp.empty())
		{
			Queue.push(Temp.top());
			Temp.pop();
		}
	}

	void PrintTicketsLineLTR() {
		queue<ClientData> Temp = _Line;
		cout << "\nTickets:  ";
		while (!Temp.empty()) {
			ClientData Data = Temp.front();
			cout << _Prefix+to_string(Data.Number);
			Temp.pop();
			if (!Temp.empty()) {
				cout << " --> ";
			}
		}
	}

	void PrintAllTickets() {
		cout << "\n\n\nAll Tickets:\n";
		
		queue<ClientData> Temp = _Line;
		ClientData Info;

		for (int i = 0; i < Temp.size(); i++) {
			Info = Temp.front();
			Temp.pop();
			cout << "\n\n\n---------------------------------------\n";
			cout << "\n\n\n" << _Prefix << Info.Number << endl;
			cout << "\n\n" << Info.Time<< endl;
			cout << "Waiting Clients: " << Info.Number - 1 << endl;
			cout << "Serve Time In\n " << 10 * Info.Number - 10 << " Minutes."<<endl;
			cout << "\n\n\n---------------------------------------\n";
		}
	}


	void ServeNextClient() {
		_Line.pop();
		_ServedClients++;
		_WaitingClients--;
	}
};

