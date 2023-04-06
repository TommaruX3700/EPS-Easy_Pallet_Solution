#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <windows.h>
#include <algorithm>
#include <fstream>
#include <cctype>
#include <vector>
#include <future>

#include "../../external/rapidjson/document.h"
#include "../../external/rapidjson/rapidjson.h"
#include "../../external/rapidjson/istreamwrapper.h"
#include "../../external/rapidjson/writer.h"
#include "../../external/rapidjson/ostreamwrapper.h"


#include "../../3D_Objects/headers/Pack.h"
#include "quicksort.cpp"
#include "getjson.cpp"


using namespace std;

void inputmanager(vector<Pack>& pacchi, vector<Pack>& pacchiNP){
    ifstream ifs("../../../input/spedizioni.json");
    rapidjson::IStreamWrapper isw(ifs);

    rapidjson::Document document;
    document.ParseStream(isw);

    if (document.HasParseError()) {
        cout << "Errore nel parsing del file JSON." << endl;
        return;
    }

    // Verifica se il documento contiene un array
    if (!document.IsArray()) {
        cout << "Il file JSON non contiene un array." << endl;
        return;
    }

    int n=document.Size();

    Pack pacco;
        
    ofstream output_file("../../out/output.txt"); // crea un oggetto ofstream per scrivere su file
    output_file.rdbuf()->pubsetbuf(0, 0); // disabilita il buffer del file

    for (int i = 0; i < n; i++) {
        getJson(i, pacco, document, pacchi, pacchiNP);
    }

    quickSort(pacchi, 0, pacchi.size() - 1);

    output_file << "PACCHI PALLETTIZZABILI" << endl;
    for (int i = 0; i < pacchi.size(); i++) {
         output_file << "Collo n." << pacchi[i].get_PackID() << " -> x=" << pacchi[i].get_Dims()->x << " y=" << pacchi[i].get_Dims()->y << " h=" << pacchi[i].get_Dims()->z << endl;
    }

    output_file << endl << "PACCHI NON PALLETTIZZABILI" << endl;
    for (int i = 0; i < pacchiNP.size(); i++) {
        output_file << "Collo n." << pacchiNP[i].get_PackID() << " -> x=" << pacchiNP[i].get_Dims()->x << " y=" << pacchiNP[i].get_Dims()->y << " h=" << pacchiNP[i].get_Dims()->z << endl;
    }
}
