#include<iostream>
#include<fstream>
#include<string>
using namespace std;
ofstream myfile("test.txt", fstream::app);
void start(string);
void move(int, string);
int main()
{
	int auswahl=0;
	string klasse;
	int simplemode=0;
	string simple;
	cout<<"(0=normal mode ; 1=simple mode)"<<endl;
	cout<<"should the patch be done for simple or normal mode?: ";
	cin>>simplemode;
	switch(simplemode)
	{
		case 0:
			simple="";
			break;
		case 1:
			simple="_contextsimplemode";
			break;
		default:
			cout<<"your input was invalid, please exit the tool.";
			break;
	}
	cout<<"which class do you want to edit?"<<endl<<"options are:"<<endl;
	cout<<"Archer: 1"<<endl<<"Assassin: 2"<<endl<<"Astromancer: 3"<<endl<<"Blade dancer: 4"<<endl<<"Blade master: 5"<<endl<<"Destroyer: 6"<<endl<<"Force master: 7"<<endl<<"Gunner: 8"<<endl<<"Kung fu master: 9"<<endl<<"Soul fighter: 10"<<endl<<"Summoner: 11"<<endl<<"Warden: 12"<<endl<<"Warlock: 13"<<endl<<"your input needs to be one of the numbers named above to select a class."<<endl;
	cin>>auswahl;
	switch(auswahl)
	{
	case 1:
		klasse="skill3_contextscriptdata_archer"+simple+".xml";
		break;
	case 2:
		klasse="skill3_contextscriptdata_assassin"+simple+".xml";
		break;
	case 3:
		klasse="skill3_contextscriptdata_thunderer"+simple+"_g1.xml";
		break;
	case 4:
		klasse="skill3_contextscriptdata_swordmaster"+simple+".xml";
		break;
	case 5:
		klasse="skill3_contextscriptdata_blademaster"+simple+".xml";
		break;
	case 6:
		klasse="skill3_contextscriptdata_destroyer"+simple+".xml";
		break;
	case 7:
		klasse="skill3_contextscriptdata_forcemaster"+simple+".xml";
		break;
	case 8:
		klasse="skill3_contextscriptdata_shooter"+simple+".xml";
		break;
	case 9:
		klasse="skill3_contextscriptdata_kungfufighter"+simple+".xml";
		break;
	case 10:
		klasse="skill3_contextscriptdata_soulfighter"+simple+".xml";
		break;
	case 11:
		klasse="skill3_contextscriptdata_summoner"+simple+".xml";
		break;
	case 12:
		klasse="skill3_contextscriptdata_warrior"+simple+".xml";
		break;
	case 13:
		klasse="skill3_contextscriptdata_warlock"+simple+".xml";
		break;
	default:
		cout<<"your input must have a invalid character or is not the same as the above named classes.";
		system("pause");
		return 0;
		break;
}
	start(klasse);
}
//bnspatch version

void start(string name)
{
	int repeat=0;
	int ID=0;
	string key;
	if(myfile.is_open())
	{
		myfile<<"<patches>"<<endl;
		myfile<<"<!-- This patch is made by Shalltear's xml creation tool -->"<<endl;
		myfile<<"<patch file=\""<<name<<"\">"<<endl;
	}
	cout<<"how many skills do you want to rebind?: ";
	cin>>repeat;
	for(repeat;repeat>0;repeat--)
	{
	cout<<"please enter the skill ID: ";
	cin>>ID;
	cout<<"please enter the skill button u want to assign it to: ";
	cin>>key;
	move(ID, key);
	}
	if(myfile.is_open())
	{
		myfile<<"</patch>"<<endl;
		myfile<<"</patches>"<<endl;
	}
	exit;
}

void move(int ID, string key)
{
	if(myfile.is_open())
	{
		myfile<<"<select-nodes query=\"//condition[@skill[(.='"<<ID<<"')]]/following-sibling::result[not(@"<<key<<")]/@*[(.='"<<ID<<"')]\">"<<endl;
		myfile<<"<set-name name=\""<<key<<"\" />"<<endl;
		myfile<<"</select-nodes>"<<endl;
	}
}

/*buddy version

void start(string name)
{
	if(myfile.is_open())
	{
		myfile<<"<?xml version=\"1.0\" encoding=\"utf-8\"?>"<<endl;
		myfile<<"<files>"<<endl;
		myfile<<"<file path=\"xml[bit].dat.files\\\\"<<name<<"\" >"<<endl;
	}
	search();
	ID();
	exit;
}

void search()
{
	if(myfile.is_open())
	{
		
	}
}

void replace()
{
	if(myfile.is_open())
	{
		
	}
}

void ID(int skill)
{
	if(myfile.is_open())
	{
		
	}
}*/

