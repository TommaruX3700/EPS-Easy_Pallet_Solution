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

#include "../libraries/rapidjson/document.h"
#include "../libraries/rapidjson/rapidjson.h"
#include "../libraries/rapidjson/istreamwrapper.h"
#include "../libraries/rapidjson/writer.h"
#include "../libraries/rapidjson/ostreamwrapper.h"


#include "pacco.h"
#include "qsp.h"
#include "getjson.h"


using namespace std;

int main(){
    ifstream ifs("../out/spedizioni.json");
    rapidjson::IStreamWrapper isw(ifs);

    rapidjson::Document document;
    document.ParseStream(isw);

    int n=document.Size();

    vector<Pacco2D> pacchi;
    vector<Pacco2D> pacchiNP;

    Pacco2D pacco;
        
    ofstream output_file("../out/output.txt"); // crea un oggetto ofstream per scrivere su file
    output_file.rdbuf()->pubsetbuf(0, 0); // disabilita il buffer del file

    rapidjson::Document pallettizzabili, non_pallettizzabili;
    pallettizzabili.SetArray();
    non_pallettizzabili.SetArray();

    for (int i = 0; i < n; i++) {
        getJson(i, pacco, document, pacchi, pacchiNP, pallettizzabili, non_pallettizzabili);
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


    ofstream outfile_pallettizzabili("../out/pallettizzabili.json");
    rapidjson::OStreamWrapper osw_pallettizzabili(outfile_pallettizzabili);
    rapidjson::Writer<rapidjson::OStreamWrapper> writer_pallettizzabili(osw_pallettizzabili);
    pallettizzabili.Accept(writer_pallettizzabili);

    ofstream outfile_non_pallettizzabili("../out/non_pallettizzabili.json");
    rapidjson::OStreamWrapper osw_non_pallettizzabili(outfile_non_pallettizzabili);
    rapidjson::Writer<rapidjson::OStreamWrapper> writer_non_pallettizzabili(osw_non_pallettizzabili);
    non_pallettizzabili.Accept(writer_non_pallettizzabili);


    STARTUPINFOA si = {0};
    PROCESS_INFORMATION pi = {0};
    si.cb = sizeof(si);
    si.dwFlags = STARTF_USESHOWWINDOW;
    si.wShowWindow = SW_HIDE;

    const char cmdLine[] = "pythonw.exe ../gotjson/gotjson.py";

    CreateProcessA(
        nullptr,             // lpApplicationName
        const_cast<LPSTR>(cmdLine),            // lpCommandLine
        nullptr,             // lpProcessAttributes
        nullptr,             // lpThreadAttributes
        false,               // bInheritHandles
        0,                   // dwCreationFlags
        nullptr,             // lpEnvironment
        nullptr,             // lpCurrentDirectory
        &si,                 // lpStartupInfo
        &pi);  


    return 0;
}
