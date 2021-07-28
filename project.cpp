#include <iostream>
#include<queue>
#include<vector>
#include<stack>
#include<string>
#include<cmath>
#include<map>
#include<bits/stdc++.h>

using namespace std;


class Patient{
public:
	int patient_id;
	string p_name;
	int p_contact;
	int P_condition;

	Patient(){
		cout<<"ENTER THE DETAILS OF THE PATITENT"<<endl;
		cout<<"		ENTER Patient ID: ";
		cin>>patient_id;
		cout<<"\n		Enter Patient name: ";
		cin>>p_name;
		cout<<"\n		Enter Patient Contact number: ";
		cin>>p_contact;
		//1->critical
		//2->below critical
		//3->normal
		cout<<"\n		Enter Patient Phase(1,2,3): ";
		cin>>P_condition;
	}
	//GET PATIENT DETAILS->

	int getPatientCondition()
	{
		return P_condition;
	}

	int getPatientID(){
		return patient_id;
	}

	int getPatientContact(){
		return p_contact;
	}

	string getPatientName(){
		return p_name;
	}
	void getPatientDetails()
	{
		cout<<"\n\tPatient ID: "<<patient_id;
		cout<<"\n\tPatient Name: "<<p_name;
		cout<<"\n\tPatient Contact Number: "<<p_contact;
	}


	
};

// void getPatientDetailsWithPatientID(int p_id,n,)
// 	{
// 		for(int i=0;i<n;i++)
// 		{
// 			if(P[i]->patient_id==p_id)
// 			{
// 				P[i]->getPatientDetails();
// 			}
// 		}	
// 	}



#define MAX 10
#define INF 100000;

void dijk(int G[MAX][MAX], int n, int start, vector<string> centers, vector<int> Vaccine)
{
	int cost[MAX][MAX], dist[MAX], visited[MAX], pred[MAX];
	int i, j, count, mindist, nextnode;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (G[i][j] == 0)
			{
				cost[i][j] = INF;
			}
			else
			{
				cost[i][j] = G[i][j];
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		dist[i] = cost[start][i];
		pred[i] = start;
		visited[i] = 0;
	}
	dist[start] = 0;
	visited[start] = 1;
	count = 1;

	while (count < n - 1)
	{
		mindist = INF;
		for (i = 0; i < n; i++)
		{
			if (dist[i] < mindist && !visited[i])
			{
				mindist = dist[i];
				nextnode = i;
			}
		}
		visited[nextnode] = 1;

		for (i = 0; i < n; i++)
		{
			if (!visited[i])
			{
				if ((mindist + cost[nextnode][i]) < dist[i])
				{
					dist[i] = mindist + cost[nextnode][i];
					pred[i] = nextnode;
				}
			}
		}
		count++;
	}

	for (i = 0; i < n; i++)
	{
		int sum = 0;
		if (i != start)
		{
			cout << "\n	----OUTPUT----\n";
			cout << "The nearest vaccination centre from :" << centers[start] << ": to center :" << centers[i] << ": is " << dist[i] << endl;
			cout << "The path is: " << centers[i] << "-(" << Vaccine[i] << " Vaccines) ";
			sum = sum + Vaccine[i];
			j = i;
			do
			{
				j = pred[j];
				cout << "<-" << centers[j] << "-(" << Vaccine[j] << " Vaccines) ";
				sum = sum + Vaccine[j];
			} while (j != start);
		}
		cout << "\n";
		if(sum!=0){
		cout << "Total Vaccines-" << sum << endl;
		}
	}
}

int getIndex(vector<string> centers, int n)
{
	string x;
	int ind;
	cout << "\n\tEnter the center-->  ";
	cin >> x;

	for (int i = 0; i != n; i++)
	{
		if (centers[i] == x)
		{
			ind = i;
			break;
		}
	}
	return ind;
}

void getGraph(int G[MAX][MAX], vector<string> centers, int n)
{
	for (int i = 0; i < n; i++)
	{

		for (int j = i; j < n; j++)
		{
			if (i != j)
			{
				int X;
				cout << "Weight/Distance of:  " << centers[i] << " -> " << centers[j] << endl;
				cin >> X;
				G[i][j] = G[j][i] = X;
			}
			else
			{
				G[i][j] = 0;
			}
		}
	}
}


void showq(queue<int> gq)
{
    queue<int> g = gq;
    while (!g.empty()) {
        cout << '\t' << g.front();
        g.pop();
    }
    cout << '\n';
}


void makePatientQueue(queue<int> q1,queue<int> q2,queue<int> q3,queue<int> patientQueue)
{
	queue<int> g1 = q1;
	queue<int> g2 = q2;
	queue<int> g3 = q3;

	while (!g1.empty()) {
		patientQueue.push(g1.front());
        g1.pop();
    }
	while (!g2.empty()) {
		patientQueue.push(g2.front());
        g2.pop();
    }
	while (!g3.empty()) {
		patientQueue.push(g3.front());
        g3.pop();
    }
}


// string chooseCenter(vector<string> center,vector<int> vaccine,int n)
// {
	
// 	return cc;
// }


void displaydetails(string cc,int pid)
{

}

int main()
{
	system("CLS");
	//VACCINES centers 
	int G[MAX][MAX], n, start;
	int i, j;

	cout << "\n";
	cout << "Enter the number of centers:" << endl;
	cin >> n;
	cout << "\n";

	//centers name
	cout << "Enter the centers:" << endl;
	vector<string> center(10);
	for (int i = 0; i < n; i++)
	{
		cin >> center[i];
	}
	cout << "\n";
	cout << "Enter the number of vaccines:" << endl;
	vector<int> vaccine(10);
	for (int i = 0; i < n; i++)
	{
		cout << center[i] << " -> ";
		cin >> vaccine[i];
	}

	cout << "\n";
	cout << "Enter the Graph" << endl;
	getGraph(G, center, n);



	int m;
	cout<<"	------------Enter Number Of Patients------------"<<endl;
	cin>>m;
	// patients details
	Patient *P[m];
	
    for(int i=0;i<m;i++)
    {
        P[i]=new Patient;
    }



//# QUEUE A,B,C
	queue<int> q1;
	queue<int> q2;
	queue<int> q3;
	queue<int> patientQueue;
	cout<<endl;
	for(int i=0;i<m;i++){
		if(P[i]->P_condition==3)
		{
			// cout<<"\npatient id:"<<P[i]->patient_id;
			int p=P[i]->patient_id;
			q1.push(p);
		}
		else if(P[i]->P_condition==1){
			// cout<<"\npatient id:"<<P[i]->patient_id;
			int p=P[i]->patient_id;
			q2.push(p);
		}
		else if(P[i]->P_condition==2){
			// cout<<"\npatient id:"<<P[i]->patient_id;
			int p=P[i]->patient_id;
			q3.push(p);
			
		}
	}
	cout<<"\n	---- OUTPUT----";
	cout << "\nThe Patient(s) are in PHASE 3 : ";
    showq(q1);
	cout << "\nThe Patient(s) are in PHASE 1 : ";
    showq(q2);
	cout << "\nThe Patient(s) are in PHASE 2 : ";
    showq(q3);
	cout<<"\n	---- OUTPUT----\n";
	//MAKING A QUEUE THAT STORES PATIENT IDS WITH CONDITION 
	// makePatientQueue(q1,q2,q3,patientQueue);
	queue<int> g1 = q1;
	queue<int> g2 = q2;
	queue<int> g3 = q3;
	while (!g1.empty()) {
		patientQueue.push(g1.front());
        g1.pop();
    }
	while (!g2.empty()) {
		patientQueue.push(g2.front());
        g2.pop();
    }
	while (!g3.empty()) {
		patientQueue.push(g3.front());
        g3.pop();
    }

	cout << "\nThe Patient(s)_id(s) ASSIGNED by PRIORITY PHASES(3,1,2) are : ";
	showq(patientQueue);
	// getPatientDetailsWithPatientID(111,3);
	queue<int> patientIDS=patientQueue;
	while(!patientIDS.empty()){

		char choice;
		
		
		int PidQueue=patientIDS.front();
		for(int i=0;i<m;i++)
		{
			if(P[i]->patient_id==PidQueue)
			{
				P[i]->getPatientDetails();
				cout<<"\nIf you accept your slot enter Y otherwise N: ";
				cin>>choice;
				if(choice=='Y'){
				start=getIndex(center,n);
				
				dijk(G, n, start, center, vaccine);
				string cc;
				cout<<"\n	Choose center from above based on the number of vaccines available: ";
				cin>>cc;
				for(int j=0;j<n;j++)
				{
					if(cc==center[j])
					{
						vaccine[j]-=1;
						// cout<<"\nCOMPARED ANURAG DIVYANSH----------------------";
						break;
					}
				}
				cout<<"\n	SLOT BOOKED  \n";
				
// function call
				cout<<"\nID: "<<P[i]->getPatientID()<<endl;
				cout<<"Patient Name: "<<P[i]->getPatientName()<<endl;
				cout<<"Patient Choosen Center: "<<cc<<endl;
				cout<<"Patient Phase: "<<P[i]->getPatientCondition()<<endl;
				cout<<"Patient Contact Number: "<<P[i]->getPatientContact()<<endl;
				cout<<"Security Code: "<<rand()%10000<<endl;
				cout<<"\n____________________________________\n";
				patientIDS.pop();
				}
				else{
					patientIDS.pop();
				}
			}
		}
		cout<<endl;
		
	}

	return 0;
}
