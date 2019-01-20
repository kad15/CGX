#include "Kml.h"
// #include <stdlib.h> // pour system()
using namespace std;

int main()
{
    string kmlFic = "kml/vizu.kml";
    ofstream flux (kmlFic);
    if(flux) {
        Kml::writeKmlHead(flux);
        Kml::jsonToKmlPoint(flux, "","data/hospitals.json","files/hospital.png");
        /** 4 helico sur une base de capacité 10 */
        Kml::jsonToKmlPoint(flux,"","data/bases.json","files/heliport.png");
        string color ="ffff0000"; // blue /*red*/"ff0000ff"; //
        string width = "1";
        Kml::jsonToKmlFlightPlan(flux, \
                                 "data/flightPlan.json", \
                                 "files/patient.png", color, width);
        Kml::writeKmlTail(flux);
        flux.close();
    } else {
        cout << "ERREUR fichier "<<  kmlFic << endl;
    }
    /** Compress kml file vizu.kml with folder "files" to get
    a self sufficient kmz file which can be visualized in google earth
    or other applications like https://worldwind.arc.nasa.gov/*/
    system("zip -r kml/vizu.kmz kml/files/ " + *kmlFic.c_str());
   // system("zip -r kml/vizu.kmz kml/files/ kml/vizu.kml");

}



/*
<TimeStamp>
  <when>1997-07-16T07:30:15Z</when>
</TimeStamp>

*/
