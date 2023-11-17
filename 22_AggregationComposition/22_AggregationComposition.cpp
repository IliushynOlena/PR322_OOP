#include <iostream>
using namespace std;

class Document
{
private:
	string name;
	string format;
	int pages;
public:
	Document() :name("no name"), format("no format"), pages(0) {}
	Document(string name, string format, int pages) :name(name), format(format) {
		this->pages = pages > 0 ? pages : 0;
	}
	void ShowInfo()
	{
		cout << "________________Document " << name << "______________" << endl;
		cout << "Format : " << format << endl;
		cout << "Pages : " << pages << endl;
	}

};

class Cartridge
{
public:
	enum Type {None, Standart, XL };
private:
	string color;
	float volume;
	Type type;
public:
	Cartridge():color("none"),volume(0),type(None){}
	Cartridge(string c, float v, Type t):color(c),volume(v),type(t){}
	void ShowInfo()const
	{
		cout << "Color : " << color << endl;
		cout << "Volume  : " << volume << endl;
		cout << "Type : " ;
		switch (type)
		{
		case Cartridge::None:cout << "None" << endl;break;
		case Cartridge::Standart:cout << "Standart" << endl;break;
		case Cartridge::XL:cout << "XL" << endl;break;
		}
		cout << endl;
	}
};

class Scaner
{
private:
	float resolution;
	float height, width;
public:
	Scaner():resolution(0),height(0),width(0){}
	Scaner(float r, float h, float w):resolution(r),height(h),width(w){}

	void ShowInfo()const
	{
		cout << "Scan Resolution : " << resolution << "dpi" << endl;
		cout << "Scan Area : height = " << height << "mm, width = "<<width << "mm" << endl;
	}
};
class Printer
{
	string model;
	Cartridge* cartridges;
	int countCartriges;
	Scaner scaner;//
	Document *doc;
public:
	Printer():model("none"),cartridges (nullptr),countCartriges(0),doc(nullptr) {}
	Printer(string m,float r, float h, float w):doc(nullptr)
	{
		this->model = m;
		scaner = Scaner(r, h, w);

		countCartriges = 4;
		cartridges = new Cartridge[countCartriges];

		cartridges[0] = Cartridge("Black", 300, Cartridge::XL);
		cartridges[1] = Cartridge("Red", 100, Cartridge::Standart);
		cartridges[2] = Cartridge("Green", 100, Cartridge::Standart);
		cartridges[3] = Cartridge("Blue", 100, Cartridge::Standart);
	}
	void AddToQueue(Document* doc)
	{
		this->doc = doc;
	}
	void Scan()
	{
		cout << "Scanning........." << endl;
	}
	void PrintDocument()
	{
		if (doc == nullptr)
		{
			cout << "no document to print " << endl;
		}
		else
		{
			cout << "Printing..................." << endl;
			doc->ShowInfo();
		}
	
	}
	void Cancel()
	{
		doc = nullptr;
	}
	void Setting()
	{
		cout << "Printing with setting..................." << endl;
		for (int i = 0; i < countCartriges; i++)
		{
			cartridges[i].ShowInfo();
		}
	}
	~Printer()
	{
		if (cartridges != nullptr)
			delete[]cartridges;

	}
};


int main()
{
	Scaner s;

	Printer printer("Canon",300,50,40);
	printer.Scan();
	printer.PrintDocument();

	Document doc1("C++ for begginers", "A4", 1500);
	Document doc2("passport", "A5", 4);

	printer.AddToQueue(&doc1);
	printer.Cancel();
	printer.PrintDocument();

	printer.AddToQueue(&doc2);
	printer.PrintDocument();

}
