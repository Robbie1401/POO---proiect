#include<iostream>
#include<fstream>
#include<string.h>
#include<string>

using namespace std;

class Eveniment
{
	string denumire;
	const string cod_eveniment;
	int ziua;
	int ora;
	int luna;
	
public :

	void varsta_de_acces()
	{
		cout << "BINE ATI VENIT , INTRODUCETI ORA EVENIMENTULUI : " << endl;
		cin >> ora;
		if (ora > 22)
		{
			cout << "Interzis copiilor sup 15 ani! , puteti continua "<<endl;
		}
		else
		{
			cout << "Nu exista restrictii de varsta , puteti continua"<<endl;
		}
	}
	void verificare_denumire()
	{
		cout << "Scrieti evenimentul la care doriti sa participati (Meci/Film/Teatru): "<<endl;
		cin >> denumire;
		if (denumire == "Meci")
		{
			cout << "Buna ziua , pentru meci selectati urmatoarele : " << endl;
		}
		else if (denumire == "Film")
		{
			cout << "Buna ziua , pentru film selectati urmatoarele : " << endl;
		}
		else if (denumire == "Teatru")
		{
			cout << "Buna ziua , pentru teatru selectati urmatoarele : " << endl;
		}
	}
		Eveniment() :cod_eveniment("EVENTROM")
	{
		this->denumire = "Necunoscut";
		this->ziua = 0;
		this->ora = 0;
		this->luna = 0;
	}
	Eveniment(string denumire, int ziua, int ora, int luna) :cod_eveniment("EVENTROM")
	{
		this->denumire = denumire;
		this->ziua = ziua;
		this->ora = ora;
		this->luna = luna;
	}
	string getDenumire()
	{
		return this->denumire;
	}
	int getZiua()
	{
		return this->ziua;
	}
	int getOra()
	{
		return this->ora;
	}
	int getLuna()
	{
		return this->luna;
	}
	void setDenumire(string denumire)
	{   
		this->denumire = denumire;
	}
	void setOra(int ora)
	{
		if (ora >= 1 && ora <= 24)
		{
			this->ora = ora;
		}
	}
		void setZiua(int ziua)
		{
			if (ziua >= 1 && ziua <= 31)
			{
				this->ziua = ziua;
			}
		}
		void setLuna(int luna)
		{
			if (luna >= 1 && luna <= 12)
			{
				this->luna = luna;
			}
		}
		friend ostream& operator<< (ostream & out, const Eveniment & ev)
		{
			out << ev.denumire << endl;
			out << ev.luna << endl;
			out << ev.ora << endl;
			out << ev.ziua << endl;
			return out;
		}
		friend istream& operator>>(istream& in, Eveniment& ev)
		{
			cout << "Denumire : " << endl;
			in >> ev.denumire;
			cout << "Luna : " << endl;
			in >> ev.luna;
			cout << "Ora : " << endl;
			in >> ev.ora;
			cout << "Ziua : " << endl;

			return in;
		}
};
class Locatie
{
	string denumire_locatie;
	long int capacitate;
	long int* codificare_locuri;
public:
	void denumire_loc()
	{
		if (denumire_locatie == "Stadion")
			capacitate = 10.000;
		else if (denumire_locatie == "Cinema")
			capacitate = 500;
		else if (denumire_locatie == "Sala")
			capacitate = 5000;
	}
	void marire_capacitate(int scaune_pliabile)
	{
		capacitate += scaune_pliabile;
	}
	Locatie()
	{
		this->denumire_locatie = "Necunoscut";
		this->capacitate;
		this->codificare_locuri = nullptr;
	}
	Locatie(string denumire_locatie, long int capacitate, long int* codificare_locuri)
	{
		if (denumire_locatie.size() >= 3)
		{
			this->denumire_locatie = denumire_locatie;
	    }
		else
		{
			this->denumire_locatie = "locatieNecunoscuta";
		}
		this->denumire_locatie = denumire_locatie;
		this->capacitate = capacitate;
		if (capacitate > 0 && codificare_locuri != nullptr)
		{
			this->codificare_locuri = new long int[this->capacitate];
			for (int i;i < this->capacitate;i++)
				this->codificare_locuri[i] = codificare_locuri[i];
		}
	}
	string getDenumirelocatie()
	{
		return this->denumire_locatie;
	}
	long int getCapacitate()
	{
		return this->capacitate;
	}
	long int* getCodificarelocuri()
	{
		return this->codificare_locuri;
	}

	void setDenumirelocatie(string denumire_locatie)
	{
		this->denumire_locatie = denumire_locatie;
	}
	void setCapacitate(long int capacitate)
	{ 
		if (capacitate >= 0 && capacitate <= 55000)
		{
			this->capacitate = capacitate;
		}
		this->capacitate = capacitate;
	}
	void setCodificarelocuri(long int* codificare_locuri)
	{
		if (this->codificare_locuri != NULL)
		{
			delete[]this->codificare_locuri;
		}

		this->codificare_locuri = codificare_locuri;
	}
	Locatie(const Locatie& loc)
	{
		if (loc.denumire_locatie.size() >= 3)
		{
			this->denumire_locatie = loc.denumire_locatie;
		}
		else
		{
			this->denumire_locatie = "locatieNecunoscuta";
		}
		this->denumire_locatie = loc.denumire_locatie;
		this->capacitate = loc.capacitate;
		if (loc.capacitate > 0 && loc.codificare_locuri != nullptr)
		{
			this->codificare_locuri = new long int[this->capacitate];
			for (int i;i < this->capacitate;i++)
				this->codificare_locuri[i] = loc.codificare_locuri[i];
		}

	}
	Locatie& operator=(const Locatie& loc)
	{
		if (this->codificare_locuri != NULL)
		{
			delete[]this->codificare_locuri;
		}

		if (loc.denumire_locatie.size() >= 3)
		{
			this->denumire_locatie = loc.denumire_locatie;
		}
		else
		{
			this->denumire_locatie = "locatieNecunoscuta";
		}
		this->denumire_locatie = loc.denumire_locatie;
		this->capacitate = loc.capacitate;
		if (loc.capacitate > 0 && loc.codificare_locuri != nullptr)
		{
			this->codificare_locuri = new long int[this->capacitate];
			for (int i;i < this->capacitate;i++)
				this->codificare_locuri[i] = loc.codificare_locuri[i];
		}
		return *this;

	}

	~Locatie()
	{
		if (this->codificare_locuri != NULL)
		{
			delete[]this->codificare_locuri;
		}
	}
	friend ostream& operator<<(ostream& out, const Locatie& loc)
	{
		out << loc.denumire_locatie << endl;
		out << loc.capacitate << endl;
		for (int i = 0;i < loc.capacitate;i++)
		{
			out << loc.codificare_locuri[i] << endl << " ";
		}
		return out;
	}
	friend istream& operator>>(istream& in, Locatie& loc)
	{
		cout << "Denumire locatie: " << endl;
		in >> loc.denumire_locatie;
		cout << "Capacitate :" << endl;
		in >> loc.capacitate;

		for (int i = 0;i < loc.capacitate;i++)
		{
			in >> loc.codificare_locuri[i];
		}
		return in;
	}
};
class Bilet
{
	int id_bilet;
	static float pret_taxa_verde;
	float pret;
	char* zona_locuri;
public:
	void scumpire(int procent)
	{
		pret = +(procent / 100) * pret;
	}
	void generarebilet(int random)
	{
		id_bilet = id_bilet * random + random;
	}
	Bilet()
	{
		this->id_bilet = 0;
		this->pret = 0;
		this->zona_locuri = nullptr;
	};

	Bilet(int id_bilet, float pret, char* zona_locuri)
	{
		if (this->id_bilet != id_bilet)
		{
			this->id_bilet = id_bilet;
		}
		else
		{
			cout << "id invalid";
		}		
		if (pret > 0)
		{
			this->pret = pret;
		}
		this->zona_locuri = new char[strlen(zona_locuri) + 1];
		strcpy(this->zona_locuri, zona_locuri);
	}
	int getIdbilet()
	{
		return this->id_bilet;
	}
	float getPret()
	{
		return this->pret;
	}
	char* getZonalocuri()
	{
		return this->zona_locuri;
	}

	void setIdbilet(int id_bilet)
	{
		this->id_bilet = id_bilet;
	}
	void setPret(float pret)
	{   
		if (pret >= 0)
		{
			this->pret = pret;
		}
	}
	void setZonalocuri(char* zona_locuri)
	{
		if (this->zona_locuri != NULL)
		{
			delete[]this->zona_locuri;
		}
		this->zona_locuri = zona_locuri;
	}
	Bilet(const Bilet& blt)
	{
		if (this->id_bilet != blt.id_bilet)
		{
			this->id_bilet = blt.id_bilet;
		}
		else
		{
			cout << "id invalid";
		}
		if (blt.pret > 0)
		{
			this->pret = blt.pret;
		}
		this->zona_locuri = new char[strlen(blt.zona_locuri) + 1];
		strcpy(this->zona_locuri, blt.zona_locuri);
	}
	Bilet& operator=(const Bilet& blt)
	{
		if (this->zona_locuri != NULL)
		{
			delete[]this->zona_locuri;
		}

		if (this->id_bilet != blt.id_bilet)
		{
			this->id_bilet = blt.id_bilet;
		}
		else
		{
			cout << "id invalid";
		}
		if (blt.pret > 0)
		{
			this->pret = blt.pret;
		}
		this->zona_locuri = new char[strlen(blt.zona_locuri) + 1];
		strcpy(this->zona_locuri, blt.zona_locuri);

		return *this;
	}
	~Bilet()
	{
		if (this->zona_locuri != NULL)
		{
			delete[]this->zona_locuri;
		}
	}
	friend ostream& operator<<(ostream& out, const Bilet& blt)
	{
		out << blt.id_bilet;
		out << blt.pret;
		out << blt.zona_locuri;
		return out;
	}
	friend istream& operator>>(istream& in, Bilet& blt)
	{
		cout << "Id Bilet : " << endl;
		in >> blt.id_bilet;
		cout << " Pret :" << endl;
		in >> blt.pret;
		if (blt.zona_locuri != NULL)
		{
			delete[]blt.zona_locuri;
		}
		cout << "Zona locuri: ";
			char aux[100];
			in.getline(aux, 99);
			 blt.zona_locuri = new char[strlen(aux) + 1];
			 strcpy(blt.zona_locuri, aux);
		     return in;
	}
};

