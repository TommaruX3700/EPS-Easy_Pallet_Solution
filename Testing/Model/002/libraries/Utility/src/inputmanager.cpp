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

vector<Pack> inputmanager(vector<Pack>& pacchi, vector<Pack>& pacchiNP){
    ifstream ifs("../../input/spedizioni.json");
    rapidjson::IStreamWrapper isw(ifs);

    rapidjson::Document document;
    document.ParseStream(isw);

    int n=document.Size();

    vector<Pack> pacchi;
    vector<Pack> pacchiNP;

    Pack pacco;
        
    ofstream output_file("../../out/output.txt"); // crea un oggetto ofstream per scrivere su file
    output_file.rdbuf()->pubsetbuf(0, 0); // disabilita il buffer del file

    for (int i = 0; i < n; i++) {
        getJson(i, pacco, document, pacchi, pacchiNP);
    }

    quickSort(pacchi, 0, pacchi.size() - 1);

    output_file << "PACCHI PALLETTIZZABILI" << endl;
    for (int i = 0; i < pacchi.size(); i++) {
        if(pacchi[i].pallettizzabile==""){
            output_file << "Collo n." << pacchi[i].n_collo << " -> x=" << pacchi[i].x << " y=" << pacchi[i].y << " h=" << pacchi[i].z << endl;
        }
    }
    output_file << endl << "PACCHI NON PALLETTIZZABILI" << endl;
    for (int i = 0; i < pacchiNP.size(); i++) {
        output_file << "Collo n." << pacchiNP[i].n_collo << " -> x=" << pacchiNP[i].x << " y=" << pacchiNP[i].y << " h=" << pacchiNP[i].z << endl;
    }
}
