#include "ReadJSON.h"


void ReadJSON::leerLibrerias()
{
	/*string findFile = nameFile();

	//int length = sizeof(findFile) / sizeof(findFile[0]);
	
	stringstream cadena;


	for (int i = 0; i < findFile.length(); i++)
	{
		if (findFile[i] == '\\')
		{
			cadena << '\\';
		}
		else if (findFile[i] != '\n')
		{
			cadena << findFile[i];
		}
	
	}
	
	string path = cadena.str(); 
	cout << path << "verificador" << endl;*/

	string path = "C:\\Users\\crisg\\Desktop\\Librerias.json";

	ifstream file(path);
	json j;

	file >> j;
	file.close();

	int length = j["Libreria"].size();

	int id = 0;
	string nombre = "";
	string letra = "";
	string color = "";
	string puntos = {};
	int x = 0;
	int y = 0;

	ArbolB* tree = new ArbolB();
	int size = 0;

	for (int i = 0; i < length; i++)
	{
		id =  j["Libreria"][i]["identificador"];
		nombre = j["Libreria"][i]["nombre"];
		letra = j["Libreria"][i]["letra"];
		color = j["Libreria"][i]["color"];

		size = j["Libreria"][i]["puntos"].size();
		SimpleList<Point>* list = new SimpleList<Point>();

		for (int k = 0; k < size; k++)
		{
			x = j["Libreria"][i]["puntos"][k]["x"];
			y = j["Libreria"][i]["puntos"][k]["y"];
			
			Point p;
			p.setX(x + "");
			p.setY(y + "");
			list->add(p);
		}

		
		tree->insert(id, nombre, letra, color, list);
		delete list;
	}
	tree->graficar();

}


void ReadJSON::leerProyectos()
{
	string path = "C:\\Users\\crisg\\Desktop\\Proyectos.json";

	ifstream file(path);
	json j;

	file >> j;
	file.close();

	string nombreProyecto = "";
	string nameNivel = "";
	int inicioX = 0;
	int inicioY = 0;
	int finalX = 0;
	int finalY = 0;
	string colorParedes = "";

	// Ventanas

	//Objetos
	int id = 0;
	string nombre = "";
	string letra = "";
	string color = "";
	int x = 0;
	int y = 0;
	int lengthNiveles = 0;

	int length = j["proyectos"].size();

	for (int i = 0; i < length; i++)
	{
		json proyecto = j["proyectos"][i];
		nombreProyecto = proyecto["nombre"];
		json niveles = proyecto["niveles"];

		if (niveles != NULL)
		{
			for (int x = 0; x < niveles.size(); x++)
			{
				json nivel = niveles[x];
				if (nivel["paredes"] != NULL) {
					for (int y = 0; y < nivel["paredes"].size(); y++)
					{
						json paredes = nivel["paredes"][y];
						inicioX = paredes["inicio"][0];
						inicioY = paredes["inicio"][1];
						finalX = paredes["final"][0];
						finalY = paredes["final"][1];
						colorParedes = paredes["color"];
					}
				}

				if (nivel["ventanas"] != NULL)
				{
				}

				if (nivel["objetos"] != NULL)
				{
					for (int o = 0; o < nivel["objetos"].size() ; o++)
					{
						json objetos = nivel["objetos"];

						id = objetos[o]["identificador"];
						nombre = objetos[o]["nombre"];
						letra = objetos[o]["letra"];
						color = objetos[o]["color"];
						json puntos = objetos[o]["puntos"];

						for (int p = 0; p < puntos.size(); p++)
						{
							x = puntos[p]["x"];
							y = puntos[p]["y"];
						}
					}

				}

			}
		}
	}

}

string ReadJSON::nameFile()
{
	OPENFILENAME ofn;       // common dialog box structure
	//char szFile[1024];       // buffer for file name
	wchar_t szFile[260];
	HWND hwnd = NULL;              // owner window
	HANDLE hf;              // file handle

	// Initialize OPENFILENAME
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = hwnd;
	ofn.lpstrFile = szFile;
	//
	// Set lpstrFile[0] to '\0' so that GetOpenFileName does not 
	// use the contents of szFile to initialize itself.
	//
	ofn.lpstrFile[0] = '\0';
	ofn.nMaxFile = sizeof(szFile);
	//ofn.lpstrFilter = (LPWSTR) "All\0*.*\0Text\0*.TXT\0";
	ofn.nFilterIndex = 1;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.lpstrInitialDir = NULL;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

	// Display the Open dialog box. 

	if (GetOpenFileName(&ofn) == TRUE)
	{
		hf = CreateFile(ofn.lpstrFile, GENERIC_READ,
			0, (LPSECURITY_ATTRIBUTES)NULL,
			OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL,
			(HANDLE)NULL);
		wstring ws(szFile);
		string str(ws.begin(), ws.end());

		cout << str << endl;
		return str;
	}

	return NULL;
}