#include <iostream>
#include <regex>
#include <string>

using namespace std;

class perscription{
	private:
		string patient;
		string birth;
		string medication;
		double dosage;
		string physician;
		void setPatient(string p) {
			patient = p;
		}
		string getPatient() {
			return patient;
		}
		bool validateBirth(string b) {
			regex dateFormat ("[0 - 9] {4} - (0[1 - 9] | 1[0 - 2]) - (0[1 - 9] | [1 - 2][0 - 9] | 3[0 - 1])");
			if (regex_match(b, dateFormat)) {
				return true;
			}
			else {
				return false;
			}
		}
		void setBirth(string b) {
			if (validateBirth(b)) {
				birth = b;
			}
			else {
				cout << "This is not an appropriate value for date. Please input the correct format yyyy-mm-dd" << endl;
				string newBirth;
				getline(cin, newBirth);
				setBirth(newBirth);
			}
		}
		string getBirth() {
			return birth;
		}
		void setMedication(string m) {
			medication = m;
		}
		string getMedication() {
			return medication;
		}
		bool validateDosage(int d) {
			if (d > 0) {
				return true;
			}
			else {
				return false;
			}
		}
		void setDosage(double d) {
			dosage= d;
		}
		double getDosage() {
			return dosage;
		}
		void setPhysician(string phy) {
			physician = phy;
		}
		string getPhysician() {
			return physician;
		}
	public:
		perscription() {
		}
		perscription(string p, string b, string m, double d, string phy) {
			setPatient(p);
			setBirth(b);
			setMedication(m);
			setDosage(d);
			setPhysician(phy);
		}
		string stringPrint() {
			string printPatient = "" + getPatient() + getBirth() + getMedication() + to_string(getDosage()) + getPhysician();
			return printPatient;
		}
};
