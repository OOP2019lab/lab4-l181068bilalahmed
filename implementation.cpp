#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "CricketTeam.h"

using namespace std;

//Setters Functions

void CricketTeam::setCaptain(string CapName){
	captain = CapName;
}

void CricketTeam::setRank(int rankno){
	Rank = rankno;
}

void CricketTeam::setTeamName(string tname){
	if (teamName != nullptr){
		delete []teamName;
	}
	else{
		teamName= new char[tname.size()];
		for (int i = 0; i <= tname.size(); i++){
			teamName[i] = tname[i];
		}
	}
}

void CricketTeam::setno_of_members(int noMembers){
	no_of_members = noMembers;
}


//Getter Functions

string CricketTeam::getCaptain(){
	return captain;
}

int CricketTeam ::getRank(){
	return Rank;
}

string CricketTeam::getTeamName(){
	return teamName;
}

int CricketTeam::getno_of_members(){
	return no_of_members;
}

//Default Constructor
CricketTeam::CricketTeam(){
	membernames = nullptr;
	no_of_members = 0;
	teamName = nullptr;
	for (int i = 0; i < 10 ; i++){
		Scoreinlast10matches[i] = 0;
	}
	Rank = 0;
	captain = "";
}

//Constructor with parameters
CricketTeam::CricketTeam(string name, int noof_members){
	int size;
	string str (name);
	size = str.size();
	teamName = new char[size++];
	for (int i =0; i < size; i++){
		teamName[i] = name[i];
	}
	no_of_members = noof_members;
	membernames = nullptr;
	Rank = 0;
	captain = "";
}

//Constructor to read file
CricketTeam::CricketTeam(string filename){
	ifstream fin(filename.c_str());
	if (fin.fail()){
		cout << "File could not be located";
	}
	else{
		char buff [100];
		char temp;
		fin.getline (buff, 100, ':');
		fin.getline (buff, 100);
		teamName = new char[strlen(buff)];
		for (int i = 0; i < 50; i++) {
			teamName[i] = buff[i];
		}
		fin.getline(buff, 100, ':');
		fin >> no_of_members;
		fin.getline(buff, 100);
		membernames = new string[no_of_members];
		for(int i = 0; i < no_of_members; i++){
			fin.getline(buff, 100);
			membernames[i] = buff;
		}
		fin.getline (buff, 100, ':');
		fin >> Rank;
		fin.getline(buff, 100);
		fin.getline (buff, 100, ':');
		fin.getline(buff, 100);
		captain = buff;
		fin.getline(buff, 100, ':');

		for (int i = 0; i < 10; i++){
			 fin >> Scoreinlast10matches[i];
			 fin >> temp;
		}
	}
}

//Function to take new member namee
void CricketTeam::inputTeamMember(string name) {
	if (no_of_members == 11) {
		cout << "Error";
	}
	else {
		string *members = new string[no_of_members++];
		for (int i = 0; i < no_of_members; i++) {
			members[i] = membernames[i];
		}
		members[no_of_members] = name;
		delete[] membernames;
		membernames = members;
	}
}

//Function to take in new score
void CricketTeam :: InputScore(int score){
	int * temp = new int[10];
	for (int i = 1; i < 10; i++) {
		temp[i - 1] = Scoreinlast10matches[i];
	}
	temp[10] = score;
	for (int j = 0; j < 10; j++) {
		Scoreinlast10matches[j] = temp[j];
	}
}
//Function to take Average
int CricketTeam::AverageScore() {
	int sum = 0;
	int avg = 0;
	int x = 0;
	for (int i = 0; i < 10; i++) {
		sum = Scoreinlast10matches[i];
		x = sum + x;
	}
	 avg = sum / 10;
	return avg;
}

//Print data
void CricketTeam :: print() {
	cout << "Latest Scores: " << Scoreinlast10matches[10] << endl;
	cout << "Team Name: " << *teamName << endl;
	cout << "Captain Name: " << captain << endl;
}

//Prints Team Info
void CricketTeam::printInfo() {
	cout << "Team Name: " << teamName << endl;
	cout << "Total Members: " << no_of_members << endl;
	for (int i = 0; i < 10; i++) {
		cout << membernames[i] << endl;
	}
	cout << "Rank: " << Rank << endl;
	cout << "Captain: " << captain << endl;
	for (int j = 0; j < 9; j++) {
		cout << Scoreinlast10matches[j] << ",";
	}
	cout << Scoreinlast10matches[10];
}

/*void CricketTeam::Compare(CricketTeam A, CricketTeam B) {
	int avg1 = 0, avg2 = 0;
	avg1 = AverageScore(A);
	avg2 = AverageScore(B);

	if (avg1 > avg2) {
		cout << "Team " << A << " is better";
	}
	else {
		cout << "Team" << B << " is better";
	}
}*/

//Deconstructor Function
CricketTeam :: ~CricketTeam() {
	delete[]membernames;
	delete[]teamName;
	no_of_members = -1;
	for (int i = 0; i < 10; i++) {
		Scoreinlast10matches[i] = -1;
	}
	Rank = -1;
	captain = "";
}
