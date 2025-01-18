#include <iostream>
#include <string>
using namespace std;

class Vehicul {
private:
    int id;  // ID unic pentru vehicul
    string marca;
    string model;
    int anFabricatie;
    double kilometriParcursi;
    string tipCombustibil;

public:
    // Constructor implicit
    Vehicul() {
        id = 0;
        marca = "Necunoscut";
        model = "Necunoscut";
        anFabricatie = 0;
        kilometriParcursi = 0.0;
        tipCombustibil = "Necunoscut";
    }

    // Constructor cu parametri
    Vehicul(int id_, string m, string mod, int an, double km, string tipComb) {
        id = id_;
        marca = m;
        model = mod;
        anFabricatie = an;
        kilometriParcursi = km;
        tipCombustibil = tipComb;
    }

    // Constructor de copiere
    Vehicul(const Vehicul &v) {
        id = v.id + 1;
        marca = v.marca;
        model = v.model;
        anFabricatie = v.anFabricatie;
        kilometriParcursi = v.kilometriParcursi;
        tipCombustibil = v.tipCombustibil;
    }

    // Destructor
    ~Vehicul() {
        cout << "Obiectul cu ID-ul " << id << " (" << marca << " " << model << ") a fost distrus!" << endl;
    }

    // Metode pentru interogarea atributelor
    int getId() const { return id; }
    string getMarca() const { return marca; }
    string getModel() const { return model; }
    int getAnFabricatie() const { return anFabricatie; }
    double getKilometriParcursi() const { return kilometriParcursi; }
    string getTipCombustibil() const { return tipCombustibil; }

    // Metode pentru modificarea atributelor
    void setId(int id_) { id = id_; }
    void setMarca(string m) { marca = m; }
    void setModel(string mod) { model = mod; }
    void setAnFabricatie(int an) { anFabricatie = an; }
    void setKilometriParcursi(double km) { kilometriParcursi = km; }
    void setTipCombustibil(string tip) { tipCombustibil = tip; }

    // Metodă pentru a afișa informațiile vehiculului
    void afiseazaInfo() const {
        cout << "ID: " << id << endl;
        cout << "Marca: " << marca << endl;
        cout << "Model: " << model << endl;
        cout << "An Fabricatie: " << anFabricatie << endl;
        cout << "Kilometri Parcursi: " << kilometriParcursi << endl;
        cout << "Tip Combustibil: " << tipCombustibil << endl;
    }

    // Metodă pentru a adăuga kilometri
    void adaugaKilometri(double km) {
        kilometriParcursi += km;
    }
};

int main() {
    // Crearea unui obiect utilizând constructorul cu parametri
    Vehicul v1(1, "Dacia", "Logan", 2015, 120000, "Benzina");
    v1.afiseazaInfo();

    // Modificarea unui atribut
    v1.setKilometriParcursi(125000);
    cout << "\nDupa actualizare:\n";
    v1.afiseazaInfo();

    // Crearea unui obiect utilizând constructorul de copiere
    Vehicul v2 = v1;
    cout << "\nObiectul copiat:\n";
    v2.afiseazaInfo();

    // Adăugarea de kilometri
    v1.adaugaKilometri(1000);
    cout << "\nDupa adăugarea de kilometri:\n";
    v1.afiseazaInfo();

    return 0;
}